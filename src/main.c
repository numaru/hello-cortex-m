#include <stdbool.h>
#include <stdio.h>

#include "stm32f1xx_hal.h"

void SysTick_Handler(void)
{
}

int main(int argc, char *argv[])
{
  HAL_Init();

  printf("Hello World\n");

  while (true)
  {
  }

  return 0;
}
