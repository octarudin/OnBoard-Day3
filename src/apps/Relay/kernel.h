#ifndef __RELY_KERNEL_H__
#define __RELY_KERNEL_H__

#include <Arduino.h>
#include "utils.h"
#include "registry.h"

namespace rely
{
    void kernelInit();
    void kernelLoop();
    void kernelTask(void *pvParameters);
    void startKernel();

    namespace func
    {
        // no additional func
    }
}

#endif