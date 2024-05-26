################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MY_RTOS/CortexM3&4_OS_Porting.c \
../MY_RTOS/MY_RTOS_FIFO.c \
../MY_RTOS/Scheduler.c 

OBJS += \
./MY_RTOS/CortexM3&4_OS_Porting.o \
./MY_RTOS/MY_RTOS_FIFO.o \
./MY_RTOS/Scheduler.o 

C_DEPS += \
./MY_RTOS/CortexM3&4_OS_Porting.d \
./MY_RTOS/MY_RTOS_FIFO.d \
./MY_RTOS/Scheduler.d 


# Each subdirectory must supply rules for building sources it contributes
MY_RTOS/CortexM3&4_OS_Porting.o: ../MY_RTOS/CortexM3&4_OS_Porting.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/CMSIS_V6" -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/MCAL_Stm32F103x8/Inc" -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/MY_RTOS/INC" -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -v -fstack-usage -MMD -MP -MF"MY_RTOS/CortexM3&4_OS_Porting.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
MY_RTOS/MY_RTOS_FIFO.o: ../MY_RTOS/MY_RTOS_FIFO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/CMSIS_V6" -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/MCAL_Stm32F103x8/Inc" -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/MY_RTOS/INC" -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -v -fstack-usage -MMD -MP -MF"MY_RTOS/MY_RTOS_FIFO.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
MY_RTOS/Scheduler.o: ../MY_RTOS/Scheduler.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/CMSIS_V6" -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/MCAL_Stm32F103x8/Inc" -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/MY_RTOS/INC" -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -v -fstack-usage -MMD -MP -MF"MY_RTOS/Scheduler.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"

