#include "transport.h"

namespace rely
{
    namespace trp
    {
        QueueHandle_t queue = xQueueCreate(
            cfg::KERNEL_TRANSPORT_QUEUE_LEN,
            sizeof(models::Generic));
    }
}