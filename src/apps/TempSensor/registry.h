#pragma once
#ifndef __TEMP_REGISTRY_H__
#define __TEMP_REGISTRY_H__

#include <Arduino.h>
#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>

namespace temp
{
    enum KernelStatus : uint8_t
    {
        KERNEL_STATUS_NONE,
        KERNEL_STATUS_INIT,
        KERNEL_STATUS_RUNNING,
        KERNEL_STATUS_SUSPENDED,
        KERNEL_STATUS_TERMINATED
    };

    struct TempRegistry
    {
        SemaphoreHandle_t mtx = xSemaphoreCreateMutex();
        TaskHandle_t kernelHandle = NULL;
        KernelStatus kernelStatus = KERNEL_STATUS_NONE;

        // Put any required variable below!
        float humidity;
        float temperature;
        float pressure;
    };

    extern Adafruit_BME280 bme;         // BME280 connect to ESP32 I2C (GPIO 21 = SDA, GPIO 22 = SCL)
    extern TempRegistry tempReg;
}

#endif