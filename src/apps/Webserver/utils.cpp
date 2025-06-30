#include "utils.h"

using namespace web;

void utl::setKernelStatus(KernelStatus status)
{
    if (xSemaphoreTake(webReg.mtx, portMAX_DELAY) == pdTRUE)
    {
        webReg.kernelStatus = status;
        xSemaphoreGive(webReg.mtx);
    }
}

KernelStatus utl::getKernelStatus()
{
    KernelStatus status = KERNEL_STATUS_NONE;
    if (xSemaphoreTake(webReg.mtx, portMAX_DELAY) == pdTRUE)
    {
        status = webReg.kernelStatus;
        xSemaphoreGive(webReg.mtx);
    }
    return status;
}

void utl::suspendKernel()
{
    if (xSemaphoreTake(webReg.mtx, portMAX_DELAY) == pdTRUE)
    {
        vTaskSuspend(webReg.kernelHandle);
        webReg.kernelStatus = KERNEL_STATUS_SUSPENDED;
        xSemaphoreGive(webReg.mtx);
    }
}

void utl::resumeKernel()
{
    if (xSemaphoreTake(webReg.mtx, portMAX_DELAY) == pdTRUE)
    {
        vTaskResume(webReg.kernelHandle);
        webReg.kernelStatus = KERNEL_STATUS_RUNNING;
        xSemaphoreGive(webReg.mtx);
    }
    vTaskResume(webReg.kernelHandle);
}

void utl::terminateKernel()
{
    if (xSemaphoreTake(webReg.mtx, portMAX_DELAY) == pdTRUE)
    {
        vTaskDelete(webReg.kernelHandle);
        webReg.kernelStatus = KERNEL_STATUS_TERMINATED;
        xSemaphoreGive(webReg.mtx);
    }
}



void utl::uploadData()
{
    static trp::models::Generic q;
    q.type = trp::types::UPLOAD_TO_WEBSERVER;
    xQueueSend(trp::queue, &q, 0);
}