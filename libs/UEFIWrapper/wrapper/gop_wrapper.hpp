/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-13 23:13:58 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-11-20 23:36:21
 * 
 * Graphics Output Protocal Wrapper
 * 
 */

#ifndef __GOP_WRAPPER_HPP__
#define __GOP_WRAPPER_HPP__

#include <defs.hpp>
#include <wrapper/systemtable_wrapper.hpp>

#define EFI_GRAPHICS_OUTPUT_PROTOCAL_GUID { \
    0x9042a9de, 0x23dc, 0x4a38, { \
        0x96, 0xfb, 0x7a, 0xde, 0xd0, 0x80, 0x51, 0x6a \
    }   \
};
namespace UEFIWrapper {
class GOP {
private:
    enum EFI_GRAPHICS_PIXEL_FORMAT {
        PixelRedGreenBlueReserved8BitPerColor,
        PixelBlueGreenRedReserved8BitPerColor,
        PixelBitMask,
        PixelBltOnly,
        PixelFormatMax
    };

    struct EFI_GRAPHICS_OUTPUT_BLT_PIXEL {
        unsigned char blue;
        unsigned char green;
        unsigned char red;
        unsigned char reserved;
    };

    struct EFI_GRAPHICS_OUTPUT_MODE_INFORMATION {
        uint32_t version;
        uint32_t horizontalResolution;
        uint32_t verticalResolution;
        EFI_GRAPHICS_PIXEL_FORMAT pixelFormat;
    };

    struct EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE {
        uint32_t maxMode;
        uint32_t mode;
        EFI_GRAPHICS_OUTPUT_MODE_INFORMATION *info;
        unsigned long long sizeOfInfo;
        unsigned long long frameBufferBase;
    };

    struct EFI_GRAPHICS_OUTPUT_PROTOCOL {
        unsigned long long (*queryMode)(
            struct EFI_GRAPHICS_OUTPUT_PROTOCOL *_this,
            uint32_t modeID,
            unsigned long long *sizeOfInfo,
            struct EFI_GRAPHICS_OUTPUT_MODE_INFORMATION* *info  // equal InfoTypePointer &itp; get back to info  
        );

        unsigned long long (*setMode)(
            struct EFI_GRAPHICS_OUTPUT_PROTOCOL *_this,
            uint32_t modeID
        );

        EFI_GRAPHICS_OUTPUT_BLT_PIXEL blt;
        EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE *mode;
    };


public:

    using EGOP          = EFI_GRAPHICS_OUTPUT_PROTOCOL;
    using PixelFormat   = EFI_GRAPHICS_PIXEL_FORMAT;
    using Pixel         = EFI_GRAPHICS_OUTPUT_BLT_PIXEL;

/*----------------------------------------------------------------*/

public:

    GOP();

    void init();

    unsigned long long getFrameBufferBase() const;

    PixelFormat getPixelFormat() const;

    uint32_t getHorizontalResolution() const;

    uint32_t getVerticalResolution() const;

private:
    EGOP *_mEGOP;  // not need to free

};  /* GOP end */

GOP::GOP() {
    SystemTable::EGUID eguid = EFI_GRAPHICS_OUTPUT_PROTOCAL_GUID;
    SystemTable::locateProtocol(&eguid, nullptr, (void **)&_mEGOP);
}

unsigned long long GOP::getFrameBufferBase() const {
    return _mEGOP->mode->frameBufferBase;
}

GOP::PixelFormat GOP::getPixelFormat() const {
    return _mEGOP->mode->info->pixelFormat;
}

uint32_t GOP::getHorizontalResolution() const {
    return _mEGOP->mode->info->horizontalResolution;
}

uint32_t GOP::getVerticalResolution() const {
    return _mEGOP->mode->info->verticalResolution;
}

} //UEFIWrapper

#endif // __GOP_WRAPPER_HPP__