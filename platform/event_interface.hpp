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
    virtual unsigned long long registerKeyNotify(
        EFI_KEY_DATA *key,
        unsigned long long (*key_notice)(EFI_KEY_DATA *KeyData),
        void **notify_handle) = 0;

    // blockkeyboardevent
    virtual unsigned long long waitForEvent(unsigned long long numberOfEvents,
                                            void **Event,
                                            unsigned long long *index) = 0;

    // blockkeyboardevent
    virtual unsigned long long waitForKeyEvent(unsigned long long numberOfEvents,
                                            unsigned long long *index) = 0;

    // noblockkeyboardevent
    virtual unsigned long long readKeyStrokeEvent(EFI_INPUT_KEY *key) = 0;

    // createevent
    virtual unsigned long long createEvent(
                                    unsigned int Type, 
                                    unsigned long long NotifyTpl,
                                    void (*NotifyFunction)(void *Event, void *Context), 
                                    void *NotifyContext,
                                    void **Event) = 0;
    // setTimer  TODO: EFI_TIMER_DELAY should not use here
    virtual unsigned long long setTimer(void *Event, 
                                        EFI_TIMER_DELAY Type,
                                        unsigned long long TriggerTime) = 0;
};

extern EventInterface *gEventInterfacePtr;

}; // INTERFACE

}; // TUGUI
#endif // __EVENT_INTERFACE_HPP__
