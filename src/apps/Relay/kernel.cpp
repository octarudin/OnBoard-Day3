#include "kernel.h"

void rely::kernelInit()
{
    rely::utl::setKernelStatus(KERNEL_STATUS_INIT);
    pinMode(rely::cfg::RELAY_PIN, OUTPUT);
    rely::utl::setKernelStatus(KERNEL_STATUS_RUNNING);
}

void rely::kernelLoop()
{
    static rely::trp::models::Generic qBuf;

    if (xQueueReceive(rely::trp::queue, &qBuf, 0) == pdTRUE)
    {
        switch (qBuf.type)
        {
        // turn the relay ON (fan/cooler)
        case rely::trp::types::SET_RELAY_ON:
            digitalWrite(rely::cfg::RELAY_PIN, HIGH);
            break;

        // turn the relay OFF (fan/cooler)
        case rely::trp::types::SET_RELAY_OFF:
            digitalWrite(rely::cfg::RELAY_PIN, LOW);
            break;
        }
    }
}

void rely::kernelTask(void *pvParameters)
{
    rely::kernelInit();
    while (1)
    {
        rely::kernelLoop();
        vTaskDelay(pdMS_TO_TICKS(rely::cfg::KERNEL_DELAY_TICKS));
    }
}

void rely::startKernel()
{
    xTaskCreatePinnedToCore(
        rely::kernelTask,
        rely::cfg::KERNEL_NAME,
        rely::cfg::KERNEL_STACK_SIZE,
        NULL,
        rely::cfg::KERNEL_PRIORITY,
        &relayReg.kernelHandle,
        rely::cfg::KERNEL_CORE);
}