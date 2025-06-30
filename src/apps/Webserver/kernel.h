#pragma once
#ifndef __WEB_KERNEL_H__
#define __WEB_KERNEL_H__

#include <Arduino.h>

#include "registry.h"
#include "utils.h"
#include "../shared.h"
#include "../TempSensor/registry.h"

namespace web
{
    void kernelInit();
    void kernelLoop();
    void kernelTask(void *pvParameters);
    void startKernel();

    
    
    namespace func
    {
        void sendToWebserver();
        String processor(const String& var);
    }
}

#endif