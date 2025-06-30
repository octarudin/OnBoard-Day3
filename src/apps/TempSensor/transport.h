#pragma once
#ifndef __TEMP_TRANSPORT_H__
#define __TEMP_TRANSPORT_H__

#include <Arduino.h>
#include "config.h"

namespace temp
{
    namespace trp
    {
        namespace types
        {
            enum TransportTypes : uint8_t
            {
                NONE,
                GET_SENSOR_DATA,
                PROCESS_SENSOR_DATA
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