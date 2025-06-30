#pragma once
#ifndef __WEB_REGISTRY_H__
#define __WEB_REGISTRY_H__

#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>

namespace web
{
    enum KernelStatus : uint8_t
    {
        KERNEL_STATUS_NONE,
        KERNEL_STATUS_INIT,
        KERNEL_STATUS_RUNNING,
        KERNEL_STATUS_SUSPENDED,
        KERNEL_STATUS_TERMINATED
    };

    struct WebRegistry
    {
        SemaphoreHandle_t mtx = xSemaphoreCreateMutex();
        TaskHandle_t kernelHandle = NULL;
        KernelStatus kernelStatus = KERNEL_STATUS_NONE;
    };

    extern AsyncWebServer server;
    extern AsyncEventSource events;
    extern WebRegistry webReg;
}

#endif