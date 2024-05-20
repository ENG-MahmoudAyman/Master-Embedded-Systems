################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MainARM.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/MainARM.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/MainARM.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MainARM.o: ../Src/MainARM.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/CMSIS_V6" -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/MCAL_Stm32F103x8/Inc" -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/MY_RTOS/INC" -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -v -fstack-usage -MMD -MP -MF"Src/MainARM.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
Src/main.o: ../Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/CMSIS_V6" -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/MCAL_Stm32F103x8/Inc" -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/MY_RTOS/INC" -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -v -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/CMSIS_V6" -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/MCAL_Stm32F103x8/Inc" -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/MY_RTOS/INC" -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -v -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/CMSIS_V6" -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/MCAL_Stm32F103x8/Inc" -I"D:/MY Courses/Embedded Kero/Code/Master-Embedded-Systems/ARM Assembly/MY_RTOS/INC" -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -v -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"

