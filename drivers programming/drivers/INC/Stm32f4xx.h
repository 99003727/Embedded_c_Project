//mcu specific header file
#include<stdio.h>

//generic macros
#define ENABLE 	1
#define DISABLE 0
#define SET 	1
#define RESET 	0
//macros for different memories

#define SRAM1 0x20000000U
#define SRAM2 0x2001C000U
#define Flash 0x08000000U
#define ROM 0x1FFF0000U

//macros for bus systems
#define BUS_BASEADDR 0x40000000U
#define APB1_BASEADDR 0x40000000U
#define APB2_BASEADDR 0x40010000U
#define AHB1_BASEADDR 0x40020000U
#define AHB2_BASEADDR 0x50000000U
#define AHB3_BASEADDR 0xA0000000U

//macro for RCC
#define RCC_BASEADDR (AHB1_BASEADDR + 0x3800U)



//macros for GPIO's
#define GPIOA_BASEADDR (AHB1_BASEADDR +0x0000U) //0x40020000U
#define GPIOB_BASEADDR (AHB1_BASEADDR +0x0400U)
#define GPIOC_BASEADDR (AHB1_BASEADDR +0x0800U)
#define GPIOD_BASEADDR (AHB1_BASEADDR +0x0C00U)
#define GPIOE_BASEADDR (AHB1_BASEADDR +0x1000U)
#define GPIOF_BASEADDR (AHB1_BASEADDR +0x1400U)
#define GPIOG_BASEADDR (AHB1_BASEADDR +0x1800U)
#define GPIOH_BASEADDR (AHB1_BASEADDR +0x1C00U)
#define GPIOI_BASEADDR (AHB1_BASEADDR +0x2000U)
#define GPIOJ_BASEADDR (AHB1_BASEADDR +0x2400U)
#define GPIOK_BASEADDR (AHB1_BASEADDR +0x2800U)

//macros for peripherals hanging on to APB1 bus
#define TIM2_BASEADDR 	(APB1_BASEADDR + 0x0000U)
#define TIM3_BASEADDR 	(APB1_BASEADDR + 0x0400U)
#define TIM4_BASEADDR 	(APB1_BASEADDR + 0x0800U)
#define TIM5_BASEADDR 	(APB1_BASEADDR + 0x0C00U)
#define TIM6_BASEADDR 	(APB1_BASEADDR + 0x1000U)
#define TIM7_BASEADDR 	(APB1_BASEADDR + 0x1400U)
#define TIM12_BASEADDR 	(APB1_BASEADDR + 0x1800U)
#define TIM13_BASEADDR 	(APB1_BASEADDR + 0x1C00U)
#define TIM14_BASEADDR 	(APB1_BASEADDR + 0x2000U)
#define RTC & BKP Registers_BASEADDR (APB1_BASEADDR + 0x2800U)
#define WWDG_BASEADDR (APB1_BASEADDR + 0x2C00U)
#define IWDG_BASEADDR (APB1_BASEADDR + 0x3000U)
#define I2S2ext_BASEADDR (APB1_BASEADDR + 0x3400U)
#define SPI2I2S2_BASEADDR (APB1_BASEADDR + 0x3800U)
#define SPI3I2S3_BASEADDR (APB1_BASEADDR + 0x3C00U)
#define I2S3ext_BASEADDR (APB1_BASEADDR + 0x4000U)
#define USART2_BASEADDR (APB1_BASEADDR + 0x4400U)
#define USART3_BASEADDR (APB1_BASEADDR + 0x4800U)
#define USART4_BASEADDR (APB1_BASEADDR + 0x4C00U)
#define USART5_BASEADDR (APB1_BASEADDR + 0x5000U)
#define I2C1_BASEADDR (APB1_BASEADDR + 0x5400U)
#define I2C2_BASEADDR (APB1_BASEADDR + 0x5800U)
#define I2C3_BASEADDR (APB1_BASEADDR + 0x5C00U)
#define CAN1_BASEADDR (APB1_BASEADDR + 0x6400U)
#define CAN2_BASEADDR (APB1_BASEADDR + 0x6800U)
#define PWR_BASEADDR (APB1_BASEADDR + 0x7000U)
#define DAC_BASEADDR (APB1_BASEADDR + 0x7400U)
#define UART7_BASEADDR (APB1_BASEADDR + 0x7800U)
#define UART8_BASEADDR (APB1_BASEADDR + 0x7C00U)


//macros for peripherals hanging on to APB2 bus
#define TIM1_BASEADDR (APB2_BASEADDR + 0x0000U)
#define TIM8_BASEADDR (APB2_BASEADDR + 0x0400U)
#define TIM9_BASEADDR (APB2_BASEADDR + 0x4000U)
#define TIM10_BASEADDR (APB2_BASEADDR + 0x4400U)
#define TIM11_BASEADDR (APB2_BASEADDR + 0x4800U)
#define USART1_BASEADDR (APB2_BASEADDR + 0x1000U)
#define USART6_BASEADDR (APB2_BASEADDR + 0x1400U)
#define ADC1_ADC2_ADC3_BASEADDR (APB2_BASEADDR + 0x2000U)
#define SDIO_BASEADDR (APB2_BASEADDR + 0x2C00U)
#define SPI1_BASEADDR (APB2_BASEADDR + 0x3000U)
#define SPI4_BASEADDR (APB2_BASEADDR + 0x3400U)
#define SYSCFG_BASEADDR (APB2_BASEADDR + 0x3800U)
#define EXTI_BASEADDR (APB2_BASEADDR + 0x3C00U)
#define SPI5_BASEADDR (APB2_BASEADDR + 0x5000U)
#define SPI6_BASEADDR (APB2_BASEADDR + 0x5400U)
#define SAI1_BASEADDR (APB2_BASEADDR + 0x5800U)
#define LCDTFT_BASEADDR (APB2_BASEADDR + 0x6800U)

//general macros
#define __vo volatile

//GPIOx register definitions
typedef struct
{
	__vo uint32_t MODER; //0x00 offset
	__vo uint32_t OTYPER; //0x04
	__vo uint32_t OSPEEDR; //0x08
	__vo uint32_t PUPDR; //0x0C
	__vo uint32_t IDR; //0x10
	__vo uint32_t ODR; // 0x14
	__vo uint32_t BSRR; //0x18
	__vo uint32_t LCKR; //0x1C
	__vo uint32_t AFR[2]; //0x20
}GPIO_RegDef_t;

//macros for RCC pointer structures
#define RCC ((RCC_RegDef_t*)RCC_BASEADDR)
//RCC register definitions
typedef struct
{
	__vo uint32_t RCC_CR;
	__vo uint32_t RCC_PLLCFGR;
	__vo uint32_t RCC_CFGR;
	__vo uint32_t RCC_CIR;
	__vo uint32_t RCC_AHB1RSTR;
	__vo uint32_t RCC_AHB2RSTR;
	__vo uint32_t RCC_AHB3RSTR;
	uint32_t      RCC_RESERVED0;
	__vo uint32_t RCC_APB1RSTR;
	__vo uint32_t RCC_APB2RSTR;
	uint32_t      RCC_RESERVED1[2];
	__vo uint32_t RCC_AHB1ENR;
	__vo uint32_t RCC_AHB2ENR;
	__vo uint32_t RCC_AHB3ENR;
	uint32_t      RCC_RESERVED2;
	__vo uint32_t RCC_APB1ENR;
	__vo uint32_t RCC_APB2ENR;
	uint32_t      RCC_RESERVED3[2];
	__vo uint32_t RCC_AHB1LPENR;
	__vo uint32_t RCC_AHB2LPENR;
	__vo uint32_t RCC_AHB3LPENR;
	uint32_t      RCC_RESERVED4;
	__vo uint32_t RCC_APB1LPENR;
	__vo uint32_t RCC_APB2LPENR;
	uint32_t      RCC_RESERVED5[2];
	__vo uint32_t RCC_BDCR;
	__vo uint32_t RCC_CSR;
	uint32_t      RCC_RESERVED6[2];
	__vo uint32_t RCC_SSCGR;
	__vo uint32_t RCC_PLLI2SCFGR;
	__vo uint32_t RCC_PLLSAICFGR;
	__vo uint32_t RCC_DCKCFGR;
	__vo uint32_t RCC_CKGATENR;
	__vo uint32_t RCC_DCKCFGR2;

}RCC_RegDef_t;
//RCC_RegDef_t *pRCC = (RCC_RegDef_t*)RCC_BASEADDR;

//macros for GPIO by type casting to their base address
#define GPIOA ((GPIO_RegDef_t*)GPIOA_BASEADDR)   //GPIO_RegDef_t *pGPIOA= (GPIO_RegDef_t*)GPIOA_BASEADDR;
#define GPIOB ((GPIO_RegDef_t*)GPIOB_BASEADDR)   //GPIO_RegDef_t *pGPIOB= (GPIO_RegDef_t*)GPIOB_BASEADDR;
#define GPIOC ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG ((GPIO_RegDef_t*)GPIOG_BASEADDR)




//macros for enabling the clock for GPIO's
#define GPIOA_PCLOCK_ENABLE (RCC->RCC_AHB1ENR |= (1<<0))
#define GPIOB_PCLOCK_ENABLE (RCC->RCC_AHB1ENR |= (1<<1))
#define GPIOC_PCLOCK_ENABLE (RCC->RCC_AHB1ENR |= (1<<2))
#define GPIOD_PCLOCK_ENABLE (RCC->RCC_AHB1ENR |= (1<<3))
#define GPIOE_PCLOCK_ENABLE (RCC->RCC_AHB1ENR |= (1<<4))
#define GPIOF_PCLOCK_ENABLE (RCC->RCC_AHB1ENR |= (1<<5))
#define GPIOG_PCLOCK_ENABLE (RCC->RCC_AHB1ENR |= (1<<6))
//to do for GPIO

//macros to disable the clock for GPIO's
#define GPIOA_PCLOCK_DISABLE (RCC->RCC_AHB1ENR &= ~(1<<0))
#define GPIOB_PCLOCK_DISABLE (RCC->RCC_AHB1ENR &= ~(1<<1))
#define GPIOC_PCLOCK_DISABLE (RCC->RCC_AHB1ENR &= ~(1<<2))
#define GPIOD_PCLOCK_DISABLE (RCC->RCC_AHB1ENR &= ~(1<<3))
#define GPIOE_PCLOCK_DISABLE (RCC->RCC_AHB1ENR &= ~(1<<4))
#define GPIOF_PCLOCK_DISABLE (RCC->RCC_AHB1ENR &= ~(1<<5))
#define GPIOG_PCLOCK_DISABLE (RCC->RCC_AHB1ENR &= ~(1<<6))



