#include <tugui.hpp>

bool is_exit = true;

unsigned long long key_notice(EFI_KEY_DATA *KeyData __attribute__((unused))) {
    is_exit = TRUE;
    return EFI_SUCCESS;
}

int tuguiMain() {
    TUGUI::Base b;
    unsigned long long status;
    void *tevent;
    void *wait_list[1];
    unsigned long long idx;

    /* 创建计时器事件tevent */
    TUGUI::INTERFACE::gEventInterfacePtr->createEvent(
        EVT_TIMER , 0, (void (*)(void *, void *))NULL, NULL,
        &tevent);

    /* 为WaitForEvent()创建要等待的事件数组 */
    wait_list[0] = tevent;

    while (true) {
        /* 设置1秒后触发tevent事件 */
        status = TUGUI::INTERFACE::gEventInterfacePtr->setTimer(
            tevent, TimerRelative, 10000000);

        b.puts(L"SetTimer\r\n");
        b.puts(L"wait for 3s\r\n");

        /* 等待tevent发生 */
        status = TUGUI::INTERFACE::gEventInterfacePtr->waitForEvent(
            1, wait_list, &idx);

        b.puts(L"success...\r\n");
    }

    return 0;
}
