################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include MY_RTOS/subdir.mk
-include MCAL_Stm32F103x8/UART_Stm32F103x8/subdir.mk
-include MCAL_Stm32F103x8/SPI_Stm32F103x8/subdir.mk
-include MCAL_Stm32F103x8/RCC_Stm32F103x8/subdir.mk
-include MCAL_Stm32F103x8/GPIO_Stm32F103x8/subdir.mk
-include MCAL_Stm32F103x8/EXTI_Stm32F103x8/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
ARM.axf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
ARM.list \

OBJCOPY_BIN += \
ARM.bin \


# All Target
all: ARM.axf secondary-outputs

# Tool invocations
ARM.axf: $(OBJS) $(USER_OBJS) D:\MY\ Courses\Embedded\ Kero\Code\Master-Embedded-Systems\ARM\ Assembly\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -g -gdwarf-2 -o "ARM.axf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\MY Courses\Embedded Kero\Code\Master-Embedded-Systems\ARM Assembly\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="ARM.map" -Wl,--gc-sections -static -gdwarf-2  -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

ARM.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "ARM.list"
	@echo 'Finished building: $@'
	@echo ' '

ARM.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "ARM.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
