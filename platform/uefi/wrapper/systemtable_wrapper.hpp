/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-13 23:14:39 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-11-17 01:10:06
 * 
 * System Table Wrapper
 * 
 */

#ifndef __SYSTEMTABLE_WRAPPER_HPP__
#define __SYSTEMTABLE_WRAPPER_HPP__

#include <defs.h>

namespace UEFIWrapper {

class SystemTable {
private:

    struct EFI_INPUT_KEY {
        unsigned short ScanCode;
        unsigned short UnicodeChar;
    };

    struct EFI_GUID {
        unsigned int data1;
        unsigned short data2;
        unsigned short data3;
        unsigned char data4[8];
    };

    struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
        MUTILS::uint64_t _buf;
        MUTILS::uint64_t (*outputString)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *_this, unsigned short *str);
        MUTILS::uint64_t _buf2[4];
        MUTILS::uint64_t (*clearScreen)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *_this);
    };

    struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
        MUTILS::uint64_t _buf;
        MUTILS::uint64_t (*readKeyStroke)(struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL *_this, struct EFI_INPUT_KEY *key);
        void *waitForKey;
    };

    struct EFI_BOOT_SERVICES {
        char _buf1[24];

        // Task Priority Services
        MUTILS::uint64_t _buf2[2];

        // Memory Services
        MUTILS::uint64_t _buf3[5];

        // Event & Timer Services
        MUTILS::uint64_t _buf4[2];
        MUTILS::uint64_t (*waitForEvent)(MUTILS::uint64_t numberOfEvents, void **event, MUTILS::uint64_t *index);
        MUTILS::uint64_t _buf4_2[3];

        // Protocol Handler Services
        MUTILS::uint64_t _buf5[9];

        // Image Services
        MUTILS::uint64_t _buf6[5];

        // Miscellaneous Services
        MUTILS::uint64_t _buf7[2];
        MUTILS::uint64_t (*setWatchdogTimer)(MUTILS::uint64_t timeout, MUTILS::uint64_t watchdogCode, MUTILS::uint64_t dataSize, unsigned short *watchdogData);

        // DriverSupport Services
        MUTILS::uint64_t _buf8[2];

        // Open and Close Protocol Services
        MUTILS::uint64_t _buf9[3];

        // Library Services
        MUTILS::uint64_t _buf10[2];
        MUTILS::uint64_t (*locateProtocol)(EFI_GUID *protocol, void *registration, void **interface);
        MUTILS::uint64_t _buf10_2[2];

        // 32-bit CRC Services
        MUTILS::uint64_t _buf11;

        // Miscellaneous Services
        MUTILS::uint64_t _buf12[3];
    };

    struct EFI_SYSTEM_TABLE {
        char _buf1[44];
        EFI_SIMPLE_TEXT_INPUT_PROTOCOL *conIn;
        MUTILS::uint64_t _buf2;
        EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *conOut;
        MUTILS::uint64_t _buf3[3];
        EFI_BOOT_SERVICES *bootServices;
    };

    

public:

    using ESystemTable = EFI_SYSTEM_TABLE;
    using EGUID        = EFI_GUID;

    static void 
    init(ESystemTable * st);

    static void 
    setWatchdogTimer(MUTILS::uint64_t, MUTILS::uint64_t, MUTILS::uint64_t, unsigned short *);

    static void
    locateProtocol(EFI_GUID *protocol, void *registration, void **interface);

    static void
    clearScreen();

private:
    static ESystemTable *_mST;

};  /* SystemTable end */

inline void
SystemTable::init(ESystemTable * st) {
    _mST = st;
}

inline void
SystemTable::setWatchdogTimer(MUTILS::uint64_t timeout, MUTILS::uint64_t watchdogCode, MUTILS::uint64_t dataSize, unsigned short *watchdogData) {
    _mST->bootServices->setWatchdogTimer(timeout, watchdogCode, dataSize, watchdogData);
}

inline void
SystemTable::locateProtocol(EFI_GUID *protocol, void *registration, void **interface) {
    _mST->bootServices->locateProtocol(protocol, registration, interface);
}

inline void
SystemTable::clearScreen() {
    _mST->conOut->clearScreen(_mST->conOut);
}

}; // UEFIWrapper

UEFIWrapper::SystemTable::ESystemTable * UEFIWrapper::SystemTable::_mST = nullptr;

#endif