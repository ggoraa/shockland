/*
 * This implementation of MultiWii Serial Protocol(MSP) v2 is
 * made with help of the Betaflight source code and iNav
 * documentation.
 */

#pragma once

#include "streambuf.h"
#include <stdint.h>
#include <stm32f1xx_hal.h>

typedef enum MSP_MessageType_e {
    MSP_Request = '<',
    MSP_Response = '>',
    MSP_Error = '!'
} MSP_MessageType_t;

void MSP_SendFrame(UART_HandleTypeDef *huart, MSP_MessageType_t type,
                   uint8_t flags, uint16_t cmd, sbuf_t *payload);