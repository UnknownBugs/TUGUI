/*
 * @Author: SPeak Shen 
 * @Date: 2022-01-24 01:03:49 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2022-01-24 02:03:34
 *
 * refLinks: https://github.com/dvdhrm/docs/blob/master/drm-howto/modeset.c
 * 
 */



#ifndef __LINUX_BASE_INTERFACE_IMPL_HPP__TUGUI
#define __LINUX_BASE_INTERFACE_IMPL_HPP__TUGUI

#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

#include <sys/poll.h>
#include <sys/time.h>
#include <sys/mman.h>

#include <platform/BaseInterface.hpp>

#include "xf86drm.h"
#include "xf86drmMode.h"

class LinuxBaseInterfaceImpl : public TUGUI::INTERFACE::BaseInterface {
    
    struct DrmBuff {
        uint32_t id;
        uint32_t size;
        void *addr;
    };

public:

    LinuxBaseInterfaceImpl() : __mMap { } {
        int ret;
        
        ret = __mFileDesc = open("/dev/dri/card0", O_RDWR | O_CLOEXEC);
        if (ret < 0) {
            fprintf(stderr, "retrieve DRM resources (%d): %m\n", errno);
            std::abort();
        }

        __mDrmModeRes = drmModeGetResources(__mFileDesc);
        __mDrmModeConnector = drmModeGetConnector(__mFileDesc,  __mDrmModeRes->connectors[0]);

        printf("retrieve DRM connector %u:%u (%d): %m\n", 0, __mDrmModeRes->connectors[0], errno);

        /* check if a monitor is connected */
        if (__mDrmModeConnector->connection != DRM_MODE_CONNECTED) {
            fprintf(stderr, "ignoring unused connector %u\n",
                __mDrmModeConnector->connector_id);
        }

        /* check if there is at least one valid mode */
        if (__mDrmModeConnector->count_modes == 0) {
            fprintf(stderr, "no valid mode for connector %u\n",
                __mDrmModeConnector->connector_id);
        }

        printf("mode for connector %u is %ux%u\n",
		__mDrmModeConnector->connector_id, getHorizontalResolution(), getVerticalResolution());

        /** 
         * find a crtc for this connector
         * first try the currently conected encoder+crtc
         */
        /*
        if (__mDrmModeConnector->encoder_id)
            __mModeEncoder = drmModeGetEncoder(__mFileDesc, __mDrmModeConnector->encoder_id);
        else {
            printf("currently conected encoder+crtc error....");
            std::abort();
        }
        */
        
    }

    ~LinuxBaseInterfaceImpl() {
        releaseDrmAllRes();
        drmModeFreeConnector(__mDrmModeConnector);
        drmModeFreeResources(__mDrmModeRes);
        //drmModeFreeEncoder(__mModeEncoder);
        close(__mFileDesc);
    }

    void init(void *ptr = nullptr) override {
        struct drm_mode_create_dumb create = { };
        int ret;

        if (ptr != nullptr) {
            // TODO
        }

        memset(&create, 0, sizeof(create));

        /* create a dumb-buffer, the pixel format is XRGB888 */
        create.width = getHorizontalResolution();
        create.height = getVerticalResolution();
        create.bpp = 32;

        ret = drmIoctl(__mFileDesc, DRM_IOCTL_MODE_CREATE_DUMB, &create);
        if (ret < 0) {
            printf("fd(%d), create dumb buffer (%d): %m\n", __mFileDesc, errno);
            std::abort();
        }

        printf("dumb-buff(return): size(%lld) handle(%d) pitch(%d) \n", create.size, create.handle, create.pitch);

        __mDrmBuff.size = create.size;

        ret = drmModeAddFB(
            __mFileDesc, 
            // getH and getVer pos error, spend 1.5h
            getHorizontalResolution(), getVerticalResolution(),
            24,
            32, create.pitch,
            create.handle, &(__mDrmBuff.id)
        );

        if (ret) {
            printf("create framebuffer (%d): %m\n", errno);
            std::abort();
        }

        // map buffer to userspace
        __mMap.handle = create.handle;
        ret = drmIoctl(__mFileDesc, DRM_IOCTL_MODE_MAP_DUMB, &__mMap);
        if (ret) {
            fprintf(stderr, "cannot map dumb buffer (%d): %m\n", errno);
            std::abort();
        }

        printf("map-buff(return): pad(%d) handle(%d) offset(%lld) \n", __mMap.pad, __mMap.handle, __mMap.offset);

        __mDrmBuff.addr = mmap(0, create.size, PROT_READ | PROT_WRITE, MAP_SHARED, __mFileDesc, __mMap.offset);

        if (__mDrmBuff.addr == MAP_FAILED) {
            fprintf(stderr, "cannot mmap dumb buffer (%d): %m\n", errno);
            std::abort();
    	}

        /* perform actual modesetting on each found connector+CRTC */
        ret = drmModeSetCrtc(
            __mFileDesc, __mDrmModeRes->crtcs[0],
            __mDrmBuff.id, 0, 0,
            &__mDrmModeRes->connectors[0], 1, &(__mDrmModeConnector->modes[0])
        );

		if (ret) {
            fprintf(stderr, "cannot set CRTC for connector %u (%d): %m\n", __mDrmModeRes->connectors[0], errno);
            std::abort();
        }

        clearScrean();

        // this is child-Ptr
        getInstancePtr() = this;

        printf("init: buffInfo(%p, %lld)\n", __mDrmBuff.addr, create.size);

    }

    void * getFrameBufferBase() const override {
        return __mDrmBuff.addr;
    }

    uint32_t getHorizontalResolution() const override {
        return __mDrmModeConnector->modes[0].hdisplay;
    }

    uint32_t getVerticalResolution() const override {
        return __mDrmModeConnector->modes[0].vdisplay;
    }

    void drawPixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t reserved) override {
        if (reserved != 0) {
            // TODO
        }
        
        auto offset = (getHorizontalResolution() * y) + x;

        RGB *rgbPtr = (RGB *)(__mDrmBuff.addr) + offset;

        rgbPtr->r = r;
        rgbPtr->g = g;
        rgbPtr->b = b;
    }

    int clearScrean() override {
        memset(__mDrmBuff.addr, 0x00, __mDrmBuff.size);
        return 0;
    }

private:
    int __mFileDesc;

    DrmBuff __mDrmBuff;
    drmModeConnector *__mDrmModeConnector;
    drmModeRes *__mDrmModeRes;
    //drmModeEncoder *__mModeEncoder;
 	struct drm_mode_map_dumb __mMap;

    void releaseDrmAllRes() {
        struct drm_mode_destroy_dumb destroy = { };
        drmModeRmFB(__mFileDesc, __mDrmBuff.id);
        munmap(__mDrmBuff.addr, __mDrmBuff.size);
        destroy.handle = __mMap.handle;
        drmIoctl(__mFileDesc, DRM_IOCTL_MODE_DESTROY_DUMB, &destroy);
    }

};  // BaseInterfaceImpl

#endif // __LINUX_BASE_INTERFACE_IMPL_HPP_TUGUI_