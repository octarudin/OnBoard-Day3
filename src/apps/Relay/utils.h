#ifndef __RELY_UTILS_H__
#define __RELY_UTILS_H__

#include <Arduino.h>
#include "config.h"
#include "registry.h"
#include "transport.h"

namespace rely
{
    namespace utl
    {
        void setKernelStatus(KernelStatus status);
        KernelStatus getKernelStatus();
        void suspendKernel();
        void resumeKernel();
        void terminateKernel();

        // Define any required utility function for the kernel below!

        // For kernel transport
        void setRelayOn();
        void setRelayOff();
    }
}

#endif