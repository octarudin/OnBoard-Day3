#pragma once
#ifndef __WEB_UTILS_H__
#define __WEB_UTILS_H__

#include <Arduino.h>
#include "config.h"
#include "registry.h"
#include "transport.h"

namespace web
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
        void uploadData();
    }
}

#endif