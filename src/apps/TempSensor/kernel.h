#pragma once
#ifndef __TEMP_KERNEL_H__
#define __TEMP_KERNEL_H__

#include <Arduino.h>

#include "registry.h"
#include "utils.h"
#include "../shared.h"

namespace temp
{
    void kernelInit();
    void kernelLoop();
    void kernelTask(void *pvParameters);
    void startKernel();

    namespace func
    {
        void initBME();
        void getSensorReadings();
        // String processor(const String& var);
    }
}

#endif