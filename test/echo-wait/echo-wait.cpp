#include <tugui.hpp>

int tuguiMain() {
  TUGUI::INTERFACE::gBaseInterfacePtr->tuguiOutputString(
      L"hello world\r\n");
  EFI_INPUT_KEY key;
  wchar_t str[3];
  unsigned long long waitindex;
  while (1) {
    // 程序会在这里阻塞
    TUGUI::INTERFACE::gEventInterfacePtr->waitForKeyEvent(1,&waitindex);

    TUGUI::INTERFACE::gBaseInterfacePtr->tuguiOutputString(
         L"hello world\r\n");

    if (!TUGUI::INTERFACE::gEventInterfacePtr->readKeyStrokeEvent(&key)) {
      if (key.UnicodeChar != L'\r') {
        str[0] = key.UnicodeChar;
        str[1] = L'\0';
      } else {
        str[0] = L'\r';
        str[1] = L'\n';
        str[2] = L'\0';
      }
      TUGUI::INTERFACE::gBaseInterfacePtr->tuguiOutputString(str);
    }
  }

  return 0;
}