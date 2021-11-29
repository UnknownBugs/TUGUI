#ifndef __UEFI_EVENT_INTERFACE_HPP__
#define __UEFI_EVENT_INTERFACE_HPP__

#include <event_interface.hpp>
#include <tdebug.hpp>

#include <uefi/wrapper/stiep_wrapper.hpp>
#include <uefi/wrapper/systemtable_wrapper.hpp>

class EventInterfaceImpl : public TUGUI::INTERFACE::EventInterface {

    using ST  = UEFIWrapper::SystemTable;
    using EST = UEFIWrapper::SystemTable::ESystemTable;

public:
    using keyFucntion = unsigned long long (*)(EFI_KEY_DATA *KeyData);

    void init(EST *est) {
        ST::init(est);
       // ST::setWatchdogTimer(0, 0, 0, nullptr);
        __mSTIEP = UEFIWrapper::STIEP(); // init stiep ptr
        }

        unsigned long long registerKeyNotify(EFI_KEY_DATA *key,
                                             keyFucntion key_notice,
                                             void **notify_handle) override{
            return __mSTIEP.RegisterKeyNotify(key, key_notice, notify_handle);
        }

        // basic event
        unsigned long long waitForKeyEvent(unsigned long long numberOfEvents,
                                        unsigned long long *index) override {
            return UEFIWrapper::SystemTable::waitForKeyEvent(numberOfEvents,
                                                          index);
        }

        // basic event
        unsigned long long waitForEvent(unsigned long long numberOfEvents,
                                        void **Event,
                                        unsigned long long *index) override {
            return  UEFIWrapper::SystemTable::waitForEvent(numberOfEvents, Event, index);
        }

        // noblockkeyboardevent
        unsigned long long readKeyStrokeEvent(EFI_INPUT_KEY *key) override{
            return UEFIWrapper::SystemTable::readKeyStroke(key);
        }

        // createevent
        unsigned long long createEvent(unsigned int Type,
                                       unsigned long long NotifyTpl,
                                       void (*NotifyFunction)(void *Event,void *Context),
                                       void *NotifyContext, 
                                       void **Event) {
            return UEFIWrapper::SystemTable::createEvent(Type, NotifyTpl, NotifyFunction, NotifyContext, Event);
        }
        // setTimer
        unsigned long long setTimer(void *Event,
                                    EFI_TIMER_DELAY Type,
                                    unsigned long long TriggerTime) {
            return UEFIWrapper::SystemTable::setTimer(Event, Type, TriggerTime);
        }

    private:
        static UEFIWrapper::STIEP __mSTIEP;
};  // EventInterfaceImpl

#endif // __UEFI_EVENT_INTERFACE_HPP__
