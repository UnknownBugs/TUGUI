/*
 * @Author: tiansongyu
 * @Date: 2021-11-29 23:55:54 
 * @Last Modified by: tiansongyu
 * @Last Modified time: 2021-11-29 00:12:48
 */

#ifndef __EVENT_INTERFACE_HPP__
#define __EVENT_INTERFACE_HPP__

#include <defs.hpp>
#include <tdebug.hpp>

#include "core/colors/color.hpp"

// TODO: When the event interface protocol is designed, delete here
#include <Uefi.h>

namespace TUGUI {

namespace INTERFACE {

class EventInterface {


public:

    virtual void waitEvent() {

    }

    virtual void timerEvent() {
        
    }
    // TODO: EFI_KEY_DATA should not use here  ,just temporary ues
    virtual unsigned long long keyboardEvent(EFI_KEY_DATA *key, unsigned long long (*key_notice)(EFI_KEY_DATA *KeyData), void **notify_handle)
    {
    }
    
};

extern EventInterface *gEventInterfacePtr;

}; // INTERFACE

}; // TUGUI
#endif // __EVENT_INTERFACE_HPP__