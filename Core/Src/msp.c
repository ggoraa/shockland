#include "msp.h"
#include "msp_protocol.h"
#include "softcrc.h"

void MSP_SendFrame(UART_HandleTypeDef *huart, MSP_MessageType_t type,
                   uint8_t flags, uint16_t cmd, sbuf_t *payload) {
    HAL_UART_Transmit_IT(huart, "$X", 2);
    HAL_UART_Transmit_IT(huart, type, 1);
    HAL_UART_Transmit_IT(huart, flags, sizeof(uint8_t));
    HAL_UART_Transmit_IT(huart, cmd, sizeof(uint16_t));
    HAL_UART_Transmit_IT(huart, payload->ptr, sbufBytesRemaining(payload));
    uint8_t crc = 0;
    for (int i = 0; i < sbufBytesRemaining(payload); i++) {
        crc = crc8_dvb_s2(crc, payload->ptr[i]);
    }
    HAL_UART_Transmit_IT(huart, crc, 1);
}