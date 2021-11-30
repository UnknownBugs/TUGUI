#include <tugui.hpp>

unsigned char is_exit = FALSE;

unsigned long long key_notice(EFI_KEY_DATA *KeyData __attribute__((unused))) {
  is_exit = TRUE;

  return EFI_SUCCESS;
}

int tuguiMain() {
    TUGUI::Base b;
    EFI_KEY_DATA key_data = {{0, L'q'}, {0, 0}};
    void *notify_handle;

    b.puts(L"Waiting for the 'q' key input...\r\n");

    // unsigned long long status;
    /*status = */ TUGUI::INTERFACE::gEventInterfacePtr->registerKeyNotify(
        &key_data, key_notice, &notify_handle);

    while (!is_exit)
        ;
    b.puts(L"success...\r\n");

    while (1)
        ;
    return 0;
}
