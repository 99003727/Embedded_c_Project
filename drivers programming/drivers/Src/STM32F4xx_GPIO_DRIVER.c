#include "STM32F4xx_GPIO_DRIVER.h"
//user defined prototypes of API's
//1.for peripheral clk enable or disable
void GPIO_PeripheralClk(GPIO_RegDef_t *pGPIOx,uint8_t ENorDI)
{
	if(ENorDI == ENABLE)
		{
			if (pGPIOx ==GPIOA)
			{
				GPIOA_PCLOCK_ENABLE;
			}
			else if (pGPIOx == GPIOB)
			{
				GPIOB_PCLOCK_ENABLE;
			}
			else if (pGPIOx == GPIOC)
			{
				GPIOC_PCLOCK_ENABLE;
			}
			else if (pGPIOx == GPIOD)
			{
				GPIOD_PCLOCK_ENABLE;
			}
			else if (pGPIOx == GPIOE)
			{
				GPIOE_PCLOCK_ENABLE;
			}

		}
	else
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLOCK_DISABLE;
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLOCK_DISABLE;
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLOCK_DISABLE;
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLOCK_DISABLE;
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLOCK_DISABLE;
		}
	}
}
//2.init and deinit of gpio
void GPIO_Init(GPIO_Handle_t *pGPIO_Handle)
{
	//1.config pin mode
	uint32_t temp=0;
	temp= (pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode << (2*pGPIO_Handle->GPIO_PinConfig.GPIO_PinNum));
	pGPIO_Handle->pGPIOx->MODER &= ~(0x3 << (2*pGPIO_Handle ->GPIO_PinConfig.GPIO_PinNum));
    pGPIO_Handle ->pGPIOx->MODER |= temp;

    //2.config pinOTYPER
    uint16_t dummy=0;
    temp= (pGPIO_Handle ->GPIO_PinConfig.GPIO_Otype << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNum);
    pGPIO_Handle ->pGPIOx-> OTYPER &= ~(0x1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNum);
    pGPIO_Handle ->pGPIOx->OTYPER |= dummy;
    //3.config OSPEED
    uint16_t temp1=0;
    temp1= (pGPIO_Handle ->GPIO_PinConfig.GPIO_Speed << (2*pGPIO_Handle->GPIO_PinConfig.GPIO_PinNum));
    pGPIO_Handle ->pGPIOx->OSPEEDR &= ~(0x3 << (2*pGPIO_Handle->GPIO_PinConfig.GPIO_PinNum));
    pGPIO_Handle ->pGPIOx->OSPEEDR |= temp1;
    //4.config pupud
    uint16_t temp2=0;
    temp2= (pGPIO_Handle->GPIO_PinConfig.GPIO_PuPd << (2*pGPIO_Handle->GPIO_PinConfig.GPIO_PinNum));
    pGPIO_Handle ->pGPIOx->PUPDR &= ~(0x3 << (2*pGPIO_Handle->GPIO_PinConfig.GPIO_PinNum));
    pGPIO_Handle ->pGPIOx->PUPDR |= temp2;
    //5.config alt function
    uint32_t temp3=0,temp4=0;
    temp3 = pGPIO_Handle->GPIO_PinConfig.GPIO_PinNum/8;
    temp4 = pGPIO_Handle->GPIO_PinConfig.GPIO_PinNum%8;
    pGPIO_Handle->pGPIOx->AFR[temp3] &= (~0xf<<(4*temp4));
    pGPIO_Handle->pGPIOx->AFR[temp3] |= (pGPIO_Handle->GPIO_PinConfig.GPIO_AltFn <<(4*temp4));

}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

//3.Read/write to/from port/pin
uint16_t GPIO_ReadfromPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t temp = 0;
	temp = (uint16_t)pGPIOx->IDR;
	return temp;
}
uint8_t GPIO_ReadfromPin(GPIO_RegDef_t *pGPIOx, uint8_t GPIO_PinNum)
{
	uint8_t temp=0;
	temp = (uint8_t)(pGPIOx -> IDR >> GPIO_PinNum & 0x00000001);
	return temp;
}
void GPIO_WritetoPort(GPIO_RegDef_t *pGPIOx, uint16_t value)
{
	pGPIOx->ODR = value;
}
void GPIO_WritetoPin(GPIO_RegDef_t *pGPIOx, uint8_t GPIO_PinNum, uint16_t value)
{
	if(value == SET)
	{
		pGPIOx-> ODR |= 1<< (GPIO_PinNum);
	}
	else
	{
		pGPIOx-> ODR &= ~(1<<GPIO_PinNum);
	}
}
void GPIO_Toggle(GPIO_RegDef_t *pGPIOx, uint8_t GPIO_PinNum)
{
	pGPIOx-> ODR ^= (1<<GPIO_PinNum);
}
