#include "utils.h"

using namespace temp;

void utl::setKernelStatus(KernelStatus status)
{
    if (xSemaphoreTake(tempReg.mtx, portMAX_DELAY) == pdTRUE)
    {
        tempReg.kernelStatus = status;
        xSemaphoreGive(tempReg.mtx);
    }
}

KernelStatus utl::getKernelStatus()
{
    KernelStatus status = KERNEL_STATUS_NONE;
    if (xSemaphoreTake(tempReg.mtx, portMAX_DELAY) == pdTRUE)
    {
        status = tempReg.kernelStatus;
        xSemaphoreGive(tempReg.mtx);
    }
    return status;
}

void utl::suspendKernel()
{
    if (xSemaphoreTake(tempReg.mtx, portMAX_DELAY) == pdTRUE)
    {
        vTaskSuspend(tempReg.kernelHandle);
        tempReg.kernelStatus = KERNEL_STATUS_SUSPENDED;
        xSemaphoreGive(tempReg.mtx);
    }
}

void utl::resumeKernel()
{
    if (xSemaphoreTake(tempReg.mtx, portMAX_DELAY) == pdTRUE)
    {
        vTaskResume(tempReg.kernelHandle);
        tempReg.kernelStatus = KERNEL_STATUS_RUNNING;
        xSemaphoreGive(tempReg.mtx);
    }
    vTaskResume(tempReg.kernelHandle);
}

void utl::terminateKernel()
{
    if (xSemaphoreTake(tempReg.mtx, portMAX_DELAY) == pdTRUE)
    {
        vTaskDelete(tempReg.kernelHandle);
        tempReg.kernelStatus = KERNEL_STATUS_TERMINATED;
        xSemaphoreGive(tempReg.mtx);
    }
}



void utl::getSensorData()
{
    static trp::models::Generic q;
    q.type = trp::types::GET_SENSOR_DATA;
    xQueueSend(trp::queue, &q, 0);
}