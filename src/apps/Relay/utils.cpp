#include "utils.h"

using namespace rely;

void utl::setKernelStatus(KernelStatus status)
{
    if (xSemaphoreTake(relayReg.mtx, portMAX_DELAY) == pdTRUE)
    {
        relayReg.kernelStatus = status;
        xSemaphoreGive(relayReg.mtx);
    }
}

KernelStatus utl::getKernelStatus()
{
    KernelStatus status = KERNEL_STATUS_NONE;
    if (xSemaphoreTake(relayReg.mtx, portMAX_DELAY) == pdTRUE)
    {
        status = relayReg.kernelStatus;
        xSemaphoreGive(relayReg.mtx);
    }
    return status;
}

void utl::suspendKernel()
{
    if (xSemaphoreTake(relayReg.mtx, portMAX_DELAY) == pdTRUE)
    {
        vTaskSuspend(relayReg.kernelHandle);
        relayReg.kernelStatus = KERNEL_STATUS_SUSPENDED;
        xSemaphoreGive(relayReg.mtx);
    }
}

void utl::resumeKernel()
{
    if (xSemaphoreTake(relayReg.mtx, portMAX_DELAY) == pdTRUE)
    {
        vTaskResume(relayReg.kernelHandle);
        relayReg.kernelStatus = KERNEL_STATUS_RUNNING;
        xSemaphoreGive(relayReg.mtx);
    }
    vTaskResume(relayReg.kernelHandle);
}

void utl::terminateKernel()
{
    if (xSemaphoreTake(relayReg.mtx, portMAX_DELAY) == pdTRUE)
    {
        vTaskDelete(relayReg.kernelHandle);
        relayReg.kernelStatus = KERNEL_STATUS_TERMINATED;
        xSemaphoreGive(relayReg.mtx);
    }
}


void utl::setRelayOn()
{
    static trp::models::Generic q;
    q.type = trp::types::SET_RELAY_ON;
    xQueueSend(trp::queue, &q, 0);
}

void utl::setRelayOff()
{
    static trp::models::Generic q;
    q.type = trp::types::SET_RELAY_OFF;
    xQueueSend(trp::queue, &q, 0);
}