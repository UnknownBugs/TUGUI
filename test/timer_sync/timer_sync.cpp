#include <tugui.hpp>

void timer_callback(void *event __attribute__((unused)),
                    void *context __attribute__((unused))) {
    TUGUI::INTERFACE::gBaseInterfacePtr->tuguiOutputString(
        L"success...\r\n");
}
int tuguiMain()
{
    unsigned long long status;
    void *tevent;

    status = TUGUI::INTERFACE::gEventInterfacePtr->createEvent(
        EVT_TIMER | EVT_NOTIFY_SIGNAL, TPL_CALLBACK, timer_callback, NULL,&tevent);

    TUGUI::INTERFACE::gBaseInterfacePtr->tuguiOutputString(L"\r\n");

    status = TUGUI::INTERFACE::gEventInterfacePtr->setTimer(
        tevent, TimerPeriodic, 10000000);
    TUGUI::INTERFACE::gBaseInterfacePtr->tuguiOutputString(L"\r\n");

    while(true)
    {
    }
        


    return 0;
}
