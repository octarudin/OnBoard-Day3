#pragma once
#ifndef __TEMP_CONFIG_H__
#define __TEMP_CONFIG_H__

#include <Arduino.h>

namespace temp
{
    namespace cfg
    {
        extern const char *KERNEL_NAME;
        extern const uint32_t KERNEL_STACK_SIZE;
        extern const uint8_t KERNEL_PRIORITY;
        extern const uint8_t KERNEL_CORE;
        extern const uint64_t KERNEL_DELAY_TICKS;
        extern const uint16_t KERNEL_TRANSPORT_QUEUE_LEN;
    }
}

#endif