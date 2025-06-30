#pragma once
#ifndef __TEMP_UTILS_H__
#define __TEMP_UTILS_H__

#include <Arduino.h>
#include "config.h"
#include "registry.h"
#include "transport.h"

namespace temp
{
    namespace utl
    {
        void setKernelStatus(KernelStatus status);
        KernelStatus getKernelStatus();
        void suspendKernel();
        void resumeKernel();
        void terminateKernel();

        // Define any required utility function for the kernel below!

        // For kernel registry
        

        // For kernel transport
        void getSensorData();
    }
}

#endif