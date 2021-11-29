#ifndef __UEFI_EVENT_INTERFACE_HPP__
#define __UEFI_EVENT_INTERFACE_HPP__

#include <event_interface.hpp>
#include <tdebug.hpp>
#include <uefi/wrapper/stiep_wrapper.hpp>
#include <uefi/wrapper/systemtable_wrapper.hpp>

class EventInterfaceImpl : public TUGUI::INTERFACE::EventInterface {
  using ST = UEFIWrapper::SystemTable;
  using EST = UEFIWrapper::SystemTable::ESystemTable;

 public:
  using keyFucntion = unsigned long long (*)(EFI_KEY_DATA *KeyData);

  void init(EST *est) {
    ST::init(est);
    // ST::setWatchdogTimer(0, 0, 0, nullptr);
    __mSTIEP = UEFIWrapper::STIEP();  // init stiep ptr
  }

  unsigned long long registerKeyNotify(EFI_KEY_DATA *key,
                                       keyFucntion key_notice,
                                       void **notify_handle) override {
    return __mSTIEP.RegisterKeyNotify(key, key_notice, notify_handle);
  }
  // blockkeyboardevent
  void waitForKeyEvent(unsigned long long numberOfEvents,
                       unsigned long long *index) override {
    UEFIWrapper::SystemTable::waitForKey(numberOfEvents, index);
  }

  // noblockkeyboardevent
  unsigned long long readKeyStrokeEvent(EFI_INPUT_KEY *key) override {
   return  UEFIWrapper::SystemTable::readKeyStroke(key);
  }

 private:
  static UEFIWrapper::STIEP __mSTIEP;
};  // EventInterfaceImpl

#endif  // __UEFI_EVENT_INTERFACE_HPP__
