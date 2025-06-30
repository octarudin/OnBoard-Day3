#ifndef __RELY_REGISTRY_H__
#define __RELY_REGISTRY_H__

#include <Arduino.h>

namespace rely
{
    enum KernelStatus : uint8_t
    {
        KERNEL_STATUS_NONE,
        KERNEL_STATUS_INIT,
        KERNEL_STATUS_RUNNING,
        KERNEL_STATUS_SUSPENDED,
        KERNEL_STATUS_TERMINATED
    };

    struct RelayRegistry
    {
        SemaphoreHandle_t mtx = xSemaphoreCreateMutex();
        TaskHandle_t kernelHandle = NULL;
        KernelStatus kernelStatus = KERNEL_STATUS_NONE;

        // Put any required variable below!
        
    };

    extern RelayRegistry relayReg;
}

#endif