#include "Stm32f4xx.h"
//creating the structure for GPIO pin CONFIG
typedef struct
{
	uint8_t GPIO_PinNum; //16macros
	uint8_t GPIO_PinMode; //4macros
	uint8_t GPIO_Speed; //4macros
	uint8_t GPIO_Otype; //output type 2macros
	uint8_t GPIO_PuPd; //pull up or pull down congi //3macros
	uint8_t GPIO_AltFn; //Alternate Functions //16functions
}GPIO_PinConfig_t;

//creating handle structure for pin accessing???
typedef struct
{
	GPIO_RegDef_t *pGPIOx;//declared a pointer variable for gpio_regdef_t
	GPIO_PinConfig_t GPIO_PinConfig;//declaring the variable for pin configuration of the structure type pin config structure
}GPIO_Handle_t;


//user defined prototypes of API's
//1.for peripheral clk enable or disable
void GPIO_PeripheralClk(GPIO_RegDef_t *pGPIOx,uint8_t ENorDI);

//2.init and deinit of gpio
void GPIO_Init(GPIO_Handle_t *pGPIO_Handle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

//3.Read/write to/from port/pin
uint16_t GPIO_ReadfromPort(GPIO_RegDef_t *pGPIOx);
uint8_t GPIO_ReadfromPin(GPIO_RegDef_t *pGPIOx, uint8_t GPIO_PinNum);
void GPIO_WritetoPort(GPIO_RegDef_t *pGPIOx, uint16_t value);
void GPIO_WritetoPin(GPIO_RegDef_t *pGPIOx, uint8_t GPIO_PinNum, uint16_t value);
void GPIO_Toggle(GPIO_RegDef_t *pGPIOx, uint8_t GPIO_PinNum);

//defining macros for Pinnumbers16
#define GPIO_Pin_Num_0   0
#define GPIO_Pin_Num_1   1
#define GPIO_Pin_Num_2   2
#define GPIO_Pin_Num_3   3
#define GPIO_Pin_Num_4   4
#define GPIO_Pin_Num_5   5
#define GPIO_Pin_Num_6   6
#define GPIO_Pin_Num_7   7
#define GPIO_Pin_Num_8   8
#define GPIO_Pin_Num_9   9
#define GPIO_Pin_Num_10  10
#define GPIO_Pin_Num_11  11
#define GPIO_Pin_Num_12  12
#define GPIO_Pin_Num_13  13
#define GPIO_Pin_Num_14  14
#define GPIO_Pin_Num_15  15

//defining macros for GPIO_pin_mode
#define GPIO_Pin_Mode_0  0
#define GPIO_Pin_Mode_1  1
#define GPIO_Pin_Mode_2  2
#define GPIO_Pin_Mode_3  3

//defining macros for GPIO_Speed
#define GPIO_Speed_0 0 //low speed
#define GPIO_Speed_1 1 //medium speed
#define GPIO_Speed_2 2 //high speed
#define GPIO_Speed_3 3 //very high speed

//defining macros for Gpio_outtype
#define GPIO_Otype_0 0
#define GPIO_Otype_1 1

//defining macros for PuPd configuration
#define GPIO_PuPd_0 0
#define GPIO_PuPd_1 1
#define GPIO_PuPd_2 2

//define macros for alternate functions
/*#define GPIO_fun0[2]  0
#define GPIO_fun1[2]  1
#define GPIO_fun2[2]  2
#define GPIO_fun3[2]  3
#define GPIO_fun4[2]  4
#define GPIO_fun5[2]  5
#define GPIO_fun6[2]  6
#define GPIO_fun7[2]  7
#define GPIO_fun8[2]  8
#define GPIO_fun9[2]  9
#define GPIO_fun10[2] 10
#define GPIO_fun11[2] 11
#define GPIO_fun12[2] 12
#define GPIO_fun13[2] 13
#define GPIO_fun14[2] 14
#define GPIO_fun15[2] 15*/
