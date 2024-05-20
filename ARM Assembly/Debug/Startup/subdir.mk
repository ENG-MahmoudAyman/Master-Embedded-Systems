################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f103c8tx.s 

OBJS += \
./Startup/startup_stm32f103c8tx.o 

S_DEPS += \
./Startup/startup_stm32f103c8tx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/startup_stm32f103c8tx.o: ../Startup/startup_stm32f103c8tx.s
	arm-none-eabi-gcc -mcpu=cortex-m3 -g -c -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/CMSIS_V6" -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/MCAL_Stm32F103x8/Inc" -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/MY_RTOS/INC" -x assembler-with-cpp -MMD -MP -MF"Startup/startup_stm32f103c8tx.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@" "$<"

