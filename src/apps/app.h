#pragma once
#ifndef __APPS_APP_H__
#define __APPS_APP_H__

#include <Arduino.h>
#include <WiFi.h>

#include "shared.h"
#include "Relay/kernel.h"
#include "TempSensor/kernel.h"
#include "Webserver/kernel.h"


namespace app
{
    void start();
    void initWiFi();
}

#endif