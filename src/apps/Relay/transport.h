#ifndef __RELY_TRANSPORT_H__
#define __RELY_TRANSPORT_H__

#include <Arduino.h>
#include "config.h"

namespace rely
{
    namespace trp
    {
        namespace types
        {
            enum TransportTypes : uint8_t
            {
                NONE,
                SET_RELAY_ON,
                SET_RELAY_OFF
            };
        }

        namespace models
        {
            struct Generic
            {
                types::TransportTypes type = types::NONE;
                void *dataPtr = nullptr;
            };

            // struct NotifA
            // {
            //     int a = 0;
            //     int b = 0;
            // };
        }

        extern QueueHandle_t queue;
    }
}

#endif