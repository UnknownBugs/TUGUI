#include <tugui.hpp>

void timer_callback(void *event __attribute__((unused)),
                    void *context __attribute__((unused))) {
    TUGUI::INTERFACE::gBaseInterfacePtr->tuguiOutputString(
        (uint16_t *)L"success...\r\n");
}

void writeValue(uint32_t val) {
    if (val < 10) {
        val += '0';
        TUGUI::INTERFACE::gBaseInterfacePtr->tuguiOutputString(
            (uint16_t *)(&(val)));
    } else {
        uint8_t s[35];
        uint32_t temp = val, pos = 0;
        while (temp) {
            s[pos++] = temp % 10;
            temp /= 10;
        }
        while (pos) {
            TUGUI::INTERFACE::gBaseInterfacePtr->tuguiOutputString(
                (uint16_t *)(s[--pos] + '0'));
        }
    }
}


int tuguiMain()
{
    unsigned long long status;
    void *tevent;

    status = TUGUI::INTERFACE::gEventInterfacePtr->createEvent(
        EVT_TIMER | EVT_NOTIFY_SIGNAL, TPL_CALLBACK, timer_callback, NULL,&tevent);

    writeValue(status);
    TUGUI::INTERFACE::gBaseInterfacePtr->tuguiOutputString((uint16_t *)L"\r\n");

    status = TUGUI::INTERFACE::gEventInterfacePtr->setTimer(
        tevent, TimerPeriodic, 10000000);
    writeValue(status);
    TUGUI::INTERFACE::gBaseInterfacePtr->tuguiOutputString((uint16_t *)L"\r\n");

    while(true)
    {
    }
        


    return 0;
}
