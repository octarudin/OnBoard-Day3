#include "kernel.h"


void web::kernelInit()
{
    web::utl::setKernelStatus(KERNEL_STATUS_INIT);
    
    // Handle Web Server
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/html", web::cfg::index_html, web::func::processor);
    });

    // Handle Web Server Events
    events.onConnect([](AsyncEventSourceClient *client){
        if(client->lastId()){
        Serial.printf("Client reconnected! Last message ID that it got is: %u\n", client->lastId());
        }
        // send event with message "hello!", id current millis
        // and set reconnect delay to 1 second
        client->send("hello!", NULL, millis(), 10000);
    });
    server.addHandler(&events);
    server.begin();

    web::utl::setKernelStatus(KERNEL_STATUS_RUNNING);
}

void web::kernelLoop()
{
    static web::trp::models::Generic qBuf;

    if (xQueueReceive(web::trp::queue, &qBuf, 0) == pdTRUE)
    {
        switch (qBuf.type)
        {
        case trp::types::UPLOAD_TO_WEBSERVER:
            web::utl::uploadData();
            break;
        }
    }
}

void web::kernelTask(void *pvParameters)
{
    web::kernelInit();
    while (1)
    {
        web::kernelLoop();
        vTaskDelay(pdMS_TO_TICKS(web::cfg::KERNEL_DELAY_TICKS));
    }
}

void web::startKernel()
{
    xTaskCreatePinnedToCore(
        web::kernelTask,
        web::cfg::KERNEL_NAME,
        web::cfg::KERNEL_STACK_SIZE,
        NULL,
        web::cfg::KERNEL_PRIORITY,
        &webReg.kernelHandle,
        web::cfg::KERNEL_CORE);
}

void web::func::sendToWebserver()
{
    // Send Events to the Web Client with the Sensor Readings
    web::events.send("ping", NULL, millis());
    web::events.send(String(temp::tempReg.temperature).c_str(), "temperature", millis());
    web::events.send(String(temp::tempReg.humidity).c_str(), "humidity", millis());
    web::events.send(String(temp::tempReg.pressure).c_str(), "pressure", millis());
}

String web::func::processor(const String& var)
{
    //SERIAL.println(var);
    if(var == "TEMPERATURE")
    {
        return String(temp::tempReg.temperature);
    }
    else if(var == "HUMIDITY")
    {
        return String(temp::tempReg.humidity);
    }
    else if(var == "PRESSURE")
    {
        return String(temp::tempReg.pressure);
    }

    return "null";
}