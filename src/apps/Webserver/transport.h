#pragma once
#ifndef __WEB_TRANSPORT_H__
#define __WEB_TRANSPORT_H__

#include <Arduino.h>
#include "config.h"

namespace web
{
    namespace trp
    {
        namespace types
        {
            enum TransportTypes : uint8_t
            {
                NONE,
                UPLOAD_TO_WEBSERVER
            };
        }

        namespace models
        {
            struct Generic
            {
                types::TransportTypes type = types::NONE;
                void *dataPtr = nullptr;
            };
        }

        extern QueueHandle_t queue;
    }
}

#endif