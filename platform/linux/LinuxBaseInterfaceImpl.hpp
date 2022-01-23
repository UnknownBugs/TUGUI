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

        __mFileDesc = open("/dev/dri/card0", O_RDWR | O_CLOEXEC);
        __mDrmModeRes = drmModeGetResources(__mFileDesc);
        __mDrmModeConnector = drmModeGetConnector(__mFileDesc,  __mDrmModeRes->connectors[0]);

    }

    ~LinuxBaseInterfaceImpl() {
        releaseDrmAllRes();
        drmModeFreeConnector(__mDrmModeConnector);
        drmModeFreeResources(__mDrmModeRes);
        close(__mFileDesc);
    }

    void init(void *ptr = nullptr) override {
        if (ptr != nullptr) {
            // TODO
        }

        struct drm_mode_create_dumb create = { };
        
        // get Buff
        drmIoctl(__mFileDesc, DRM_IOCTL_MODE_CREATE_DUMB, &create);
        __mDrmBuff.size = create.size;

        drmModeAddFB(
            __mFileDesc, getVerticalResolution(),
            getHorizontalResolution(), 24,
            32, create.pitch,
            create.handle, &(__mDrmBuff.id)
        );

        // map buffer to userspace
        __mMap.handle = create.handle;
        drmIoctl(__mFileDesc, DRM_IOCTL_MODE_MAP_DUMB, &__mMap);

        __mDrmBuff.addr = mmap(0, create.size, PROT_READ | PROT_WRITE, MAP_SHARED, __mFileDesc, __mMap.offset);

        clearScrean();

        // this is child-Ptr
        getInstancePtr() = this;

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
        memset(__mDrmBuff.addr, 0xff, __mDrmBuff.size);
        return 0;
    }

private:
    int __mFileDesc;

    DrmBuff __mDrmBuff;
    drmModeConnector *__mDrmModeConnector;
    drmModeRes *__mDrmModeRes;
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