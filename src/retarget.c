#include <stdbool.h>
#include <stdint.h>

#include "stm32f1xx_hal.h"

#define USARTx USART2
#define USARTx_CLK_ENABLE() __HAL_RCC_USART2_CLK_ENABLE();
#define USARTx_RX_GPIO_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
#define USARTx_TX_GPIO_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()

#define USARTx_FORCE_RESET() __HAL_RCC_USART2_FORCE_RESET()
#define USARTx_RELEASE_RESET() __HAL_RCC_USART2_RELEASE_RESET()

#define USARTx_TX_PIN GPIO_PIN_2
#define USARTx_TX_GPIO_PORT GPIOA
#define USARTx_RX_PIN GPIO_PIN_3
#define USARTx_RX_GPIO_PORT GPIOA

static UART_HandleTypeDef g_uartHandle;

int _write(int fd, char *buffer, int length)
{
    for (size_t i = 0; i < length; i++)
    {
        HAL_UART_Transmit(&g_uartHandle, (uint8_t *)&(buffer[i]), 1, 0xFFFF);
    }
    return length;
}

void HAL_MspInit(void)
{
    g_uartHandle.Instance = USARTx;

    g_uartHandle.Init.BaudRate = 9600;
    g_uartHandle.Init.WordLength = UART_WORDLENGTH_8B;
    g_uartHandle.Init.StopBits = UART_STOPBITS_1;
    g_uartHandle.Init.Parity = UART_PARITY_ODD;
    g_uartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    g_uartHandle.Init.Mode = UART_MODE_TX_RX;
    if (HAL_UART_Init(&g_uartHandle) != HAL_OK)
    {
        while (true)
        {
        }
    }
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    USARTx_TX_GPIO_CLK_ENABLE();
    USARTx_RX_GPIO_CLK_ENABLE();

    USARTx_CLK_ENABLE();

    GPIO_InitStruct.Pin = USARTx_TX_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

    HAL_GPIO_Init(USARTx_TX_GPIO_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = USARTx_RX_PIN;

    HAL_GPIO_Init(USARTx_RX_GPIO_PORT, &GPIO_InitStruct);
}

void HAL_UART_MspDeInit(UART_HandleTypeDef *huart)
{
    USARTx_FORCE_RESET();
    USARTx_RELEASE_RESET();

    HAL_GPIO_DeInit(USARTx_TX_GPIO_PORT, USARTx_TX_PIN);
    HAL_GPIO_DeInit(USARTx_RX_GPIO_PORT, USARTx_RX_PIN);
}
