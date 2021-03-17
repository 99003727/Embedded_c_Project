//#include "Stm32f4xx.h"
#include "STM32F4xx_GPIO_DRIVER.h"
void delay(void)
{
	for(uint32_t i=0;i<50000;i++);
}

int main(void)
{
	GPIO_Handle_t GpioLed;
	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNum = GPIO_Pin_Num_13;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_Pin_Mode_1;
	GpioLed.GPIO_PinConfig.GPIO_Speed = GPIO_Speed_2;
	GpioLed.GPIO_PinConfig.GPIO_Otype = GPIO_Otype_0;
	GpioLed.GPIO_PinConfig.GPIO_PuPd = GPIO_PuPd_1;
	GPIO_PeripheralClk(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

	while(1)
	{
		GPIO_Toggle(GPIOD, GPIO_Pin_Num_13);
		delay();
	}
}
