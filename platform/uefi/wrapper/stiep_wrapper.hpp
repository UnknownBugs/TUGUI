/*
 * @Author: tiansongyu
 * @Date: 2021-11-29 23:13:58
 * @Last Modified by: tiansongyu
 * @Last Modified time: 2021-11-29 23:36:21
 *
 * keyboard event Protocal Wrapper
 *
 */

#ifndef __STIEP_WRAPPER_HPP__
#define __STIEP_WRAPPER_HPP__

#include <defs.hpp>
#include <uefi/wrapper/systemtable_wrapper.hpp>

#define EFI_KEYBOARD_EVENT_PROTOCAL_GUID \
  {0xdd9e7534,                           \
   0x7762,                               \
   0x4698,                               \
   {0x8c, 0x14, 0xf5, 0x85, 0x17, 0xa6, 0x25, 0xaa}};

namespace UEFIWrapper {
class STIEP {
 private:

 public:
  using ESTIEP = EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL;
  using keyFucntion = unsigned long long (*)(EFI_KEY_DATA *KeyData);

  unsigned long long RegisterKeyNotify(EFI_KEY_DATA *key,
                                       keyFucntion key_notice, void **notify_handle);

  /*----------------------------------------------------------------*/

 public:
  STIEP();

  void init();

 private:
  ESTIEP *_mESTIEP;  // not need to free

}; /* STIEP end */

STIEP::STIEP() {
  SystemTable::EGUID sguid = EFI_KEYBOARD_EVENT_PROTOCAL_GUID;
  SystemTable::locateProtocol(&sguid, nullptr, (void **)&_mESTIEP);
}

unsigned long long STIEP::RegisterKeyNotify(EFI_KEY_DATA *key,
                                            keyFucntion key_notice, void **notify_handle){
   return  _mESTIEP->RegisterKeyNotify(_mESTIEP, key, key_notice, notify_handle);
}

}  // namespace UEFIWrapper

#endif  // __STIEP_WRAPPER_HPP__
