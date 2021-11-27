/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-13 23:14:39 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-11-21 00:49:29
 * 
 * System Table Wrapper
 * 
 */

#ifndef __SYSTEMTABLE_WRAPPER_HPP__
#define __SYSTEMTABLE_WRAPPER_HPP__

#include <defs.hpp>
#include <Uefi.h>

namespace UEFIWrapper {

class SystemTable {
    
public:

    using ESystemTable = EFI_SYSTEM_TABLE;
    using EGUID        = EFI_GUID;

    static void 
    init(ESystemTable * st) {
        __mST = st;
    }

    static void 
    setWatchdogTimer(uint64_t timeout, uint64_t watchdogCode, uint64_t dataSize, unsigned short *watchdogData) {
        __mST->BootServices->SetWatchdogTimer(timeout, watchdogCode, dataSize, watchdogData);
    }

    static void
    locateProtocol(EFI_GUID *protocol, void *registration, void **interface) {
        __mST->BootServices->LocateProtocol(protocol, registration, interface);
    }

    static void *
    allocatePool(EFI_MEMORY_TYPE poolType, uint32_t size) {
        void *mPtr = nullptr;
        uint64_t status = __mST->BootServices->AllocatePool(poolType, size, (void **)&mPtr);
        if (status == 0) while (1);
        return mPtr;
    }

    // TODO: START
    static EFI_INPUT_KEY ReadKeyStroke() {
      EFI_INPUT_KEY key;
      __mST->ConIn->ReadKeyStroke(__mST->ConIn, &key);
      return key;
    }

    static void OutputString(EFI_INPUT_KEY key) {
      uint16_t str[3];
      if (key.UnicodeChar != L'\r') {
        str[0] = key.UnicodeChar;
        str[1] = L'\0';
      } else {
        str[0] = L'\r';
        str[1] = L'\n';
        str[2] = L'\0';
      }
      __mST->ConOut->OutputString(__mST->ConOut, str);
    }
    // TODO: END

    static void freePool(void *mPtr) {
        __mST->BootServices->FreePool(mPtr);
    }

    static void
    clearScreen()  {
        __mST->ConOut->ClearScreen(__mST->ConOut);
    }

private:
    static EFI_SYSTEM_TABLE  *__mST;

};  // SystemTable

}; // UEFIWrapper

UEFIWrapper::SystemTable::ESystemTable * UEFIWrapper::SystemTable::__mST = nullptr;

#endif