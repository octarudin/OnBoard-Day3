#include "transport.h"

namespace temp
{
    namespace trp
    {
        QueueHandle_t queue = xQueueCreate(
            cfg::KERNEL_TRANSPORT_QUEUE_LEN,
            sizeof(models::Generic));
    }
}