/**
 * UEFI:
 *  System Table Wrapper
 * 
*/

#ifndef __SYSTEMTABLE_WRAPPER_HPP__
#define __SYSTEMTABLE_WRAPPER_HPP__

namespace TUGUI {

namespace UEFIWrapper {

class SystemTable {
private:

    using uint64 = unsigned long long;

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
        uint64 _buf;
        uint64 (*outputString)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *_this, unsigned short *str);
        uint64 _buf2[4];
        uint64 (*clearScreen)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *_this);
    };

    struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
        uint64 _buf;
        uint64 (*readKeyStroke)(struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL *_this, struct EFI_INPUT_KEY *key);
        void *waitForKey;
    };

    struct EFI_BOOT_SERVICES {
        char _buf1[24];

        // Task Priority Services
        uint64 _buf2[2];

        // Memory Services
        uint64 _buf3[5];

        // Event & Timer Services
        uint64 _buf4[2];
        uint64 (*waitForEvent)(uint64 numberOfEvents, void **event, uint64 *index);
        uint64 _buf4_2[3];

        // Protocol Handler Services
        uint64 _buf5[9];

        // Image Services
        uint64 _buf6[5];

        // Miscellaneous Services
        uint64 _buf7[2];
        uint64 (*setWatchdogTimer)(uint64 timeout, uint64 watchdogCode, uint64 dataSize, unsigned short *watchdogData);

        // DriverSupport Services
        uint64 _buf8[2];

        // Open and Close Protocol Services
        uint64 _buf9[3];

        // Library Services
        uint64 _buf10[2];
        uint64 (*locateProtocol)(EFI_GUID *protocol, void *registration, void **interface);
        uint64 _buf10_2[2];

        // 32-bit CRC Services
        uint64 _buf11;

        // Miscellaneous Services
        uint64 _buf12[3];
    };

    struct EFI_SYSTEM_TABLE {
        char _buf1[44];
        EFI_SIMPLE_TEXT_INPUT_PROTOCOL *conIn;
        uint64 _buf2;
        EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *conOut;
        uint64 _buf3[3];
        EFI_BOOT_SERVICES *bootServices;
    };

    

public:

    using ESystemTable = EFI_SYSTEM_TABLE;
    using EGUID        = EFI_GUID;

    static void 
    init(ESystemTable * st);

    static void 
    setWatchdogTimer(uint64, uint64, uint64, unsigned short *);

    static void
    locateProtocol(EFI_GUID *protocol, void *registration, void **interface);

private:
    static ESystemTable *_mST;

};  /* SystemTable end */

inline void
SystemTable::init(ESystemTable * st) {
    _mST = st;
}

inline void
SystemTable::setWatchdogTimer(uint64 timeout, uint64 watchdogCode, uint64 dataSize, unsigned short *watchdogData) {
    _mST->bootServices->setWatchdogTimer(timeout, watchdogCode, dataSize, watchdogData);
}

inline void
SystemTable::locateProtocol(EFI_GUID *protocol, void *registration, void **interface) {
    _mST->bootServices->locateProtocol(protocol, registration, interface);
}

};  /* UEFIWrapper end */

UEFIWrapper::SystemTable::ESystemTable * UEFIWrapper::SystemTable::_mST = nullptr;

};  /* TUGUI */

#endif