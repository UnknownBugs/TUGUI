#include <tugui.hpp>

int tuguiMain() {
  TUGUI::Base base;
  TUGUI::INTERFACE::gBaseInterfacePtr->tuguiOutputString((uint16_t*)L"hello world\n");
  while (1) {
    ;
  }
  return 0;
}