################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/Src/STM32F4xx_GPIO_DRIVER.c 

OBJS += \
./drivers/Src/STM32F4xx_GPIO_DRIVER.o 

C_DEPS += \
./drivers/Src/STM32F4xx_GPIO_DRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/Src/STM32F4xx_GPIO_DRIVER.o: ../drivers/Src/STM32F4xx_GPIO_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I"D:/embedded c/drivers programming/drivers/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/Src/STM32F4xx_GPIO_DRIVER.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

