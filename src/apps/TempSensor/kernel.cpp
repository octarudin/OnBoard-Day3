#include "kernel.h"

void temp::kernelInit()
{
    temp::utl::setKernelStatus(KERNEL_STATUS_INIT);
    temp::func::initBME();
    temp::utl::setKernelStatus(KERNEL_STATUS_RUNNING);
    utl::getSensorData();
}

void temp::kernelLoop()
{
    static temp::trp::models::Generic qBuf;

    if (xQueueReceive(temp::trp::queue, &qBuf, 0) == pdTRUE)
    {
        switch (qBuf.type)
        {
        case trp::types::GET_SENSOR_DATA:
            temp::func::getSensorReadings();
            
            // here, you're already get the humidity and temperature data
            // just do a simple logic
            if (temp::tempReg.temperature >= 27.0)
            {
                // turn the relay ON (fan/cooler)
                rely::utl::setRelayOn(); // need import file rely::utl, shared.h
            }
            else 
            {
                // turn the relay OFF (fan/cooler)
                rely::utl::setRelayOff(); // need import file rely::utl, shared.h
            }
            break;
        }
    }
}

void temp::kernelTask(void *pvParameters)
{
    temp::kernelInit();
    while (1)
    {
        temp::kernelLoop();
        vTaskDelay(pdMS_TO_TICKS(temp::cfg::KERNEL_DELAY_TICKS));
    }
}

void temp::startKernel()
{
    xTaskCreatePinnedToCore(
        temp::kernelTask,
        temp::cfg::KERNEL_NAME,
        temp::cfg::KERNEL_STACK_SIZE,
        NULL,
        temp::cfg::KERNEL_PRIORITY,
        &tempReg.kernelHandle,
        temp::cfg::KERNEL_CORE);
}

void temp::func::initBME()
{
    if (!temp::bme.begin(0x76)) 
    {
        ser.println("Could not find a valid BME280 sensor, check wiring!");
        while (1);
    }
}

void temp::func::getSensorReadings()
{
    temp::tempReg.temperature = temp::bme.readTemperature();
    // Convert temperature to Fahrenheit
    //temperature = 1.8 * bme.readTemperature() + 32;
    temp::tempReg.humidity = temp::bme.readHumidity();
    temp::tempReg.pressure = temp::bme.readPressure() / 100.0F;

    ser.printf("Temperature = %.2f ºC \n", temp::tempReg.temperature);
    ser.printf("Humidity = %.2f \n", temp::tempReg.humidity);
    ser.printf("Pressure = %.2f hPa \n", temp::tempReg.pressure);
    ser.println();
}