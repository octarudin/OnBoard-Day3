#include "config.h"

namespace temp
{
    namespace cfg
    {
        const char *KERNEL_NAME = "TempTask";
        const uint32_t KERNEL_STACK_SIZE = 2048;
        const uint8_t KERNEL_PRIORITY = 1;
        const uint8_t KERNEL_CORE = 1;
        const uint64_t KERNEL_DELAY_TICKS = 3000;
        const uint16_t KERNEL_TRANSPORT_QUEUE_LEN = 16;
    }
}