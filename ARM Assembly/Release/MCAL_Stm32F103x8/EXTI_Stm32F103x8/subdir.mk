################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL_Stm32F103x8/EXTI_Stm32F103x8/EXTI_Stm32F103x8.c 

OBJS += \
./MCAL_Stm32F103x8/EXTI_Stm32F103x8/EXTI_Stm32F103x8.o 

C_DEPS += \
./MCAL_Stm32F103x8/EXTI_Stm32F103x8/EXTI_Stm32F103x8.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL_Stm32F103x8/EXTI_Stm32F103x8/EXTI_Stm32F103x8.o: ../MCAL_Stm32F103x8/EXTI_Stm32F103x8/EXTI_Stm32F103x8.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL_Stm32F103x8/EXTI_Stm32F103x8/EXTI_Stm32F103x8.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

