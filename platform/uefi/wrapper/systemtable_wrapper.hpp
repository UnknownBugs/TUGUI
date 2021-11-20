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
    init(ESystemTable * st);

    static void 
    setWatchdogTimer(uint64_t, uint64_t, uint64_t, unsigned short *);

    static void
    locateProtocol(EFI_GUID *protocol, void *registration, void **interface);

    static void
    clearScreen();

private:
    static EFI_SYSTEM_TABLE  *__mST;

};  /* SystemTable end */

inline void
SystemTable::init(ESystemTable * st) {
    __mST = st;
}

inline void
SystemTable::setWatchdogTimer(uint64_t timeout, uint64_t watchdogCode, uint64_t dataSize, unsigned short *watchdogData) {
    __mST->BootServices->SetWatchdogTimer(timeout, watchdogCode, dataSize, watchdogData);
}

inline void
SystemTable::locateProtocol(EFI_GUID *protocol, void *registration, void **interface) {
    __mST->BootServices->LocateProtocol(protocol, registration, interface);
}

inline void
SystemTable::clearScreen() {
    __mST->ConOut->ClearScreen(__mST->ConOut);
}

}; // UEFIWrapper

UEFIWrapper::SystemTable::ESystemTable * UEFIWrapper::SystemTable::__mST = nullptr;

#endif