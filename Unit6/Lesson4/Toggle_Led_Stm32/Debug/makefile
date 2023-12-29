################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
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
Toggle_Led_Stm32F103C8.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Toggle_Led_Stm32F103C8.list \

OBJCOPY_BIN += \
Toggle_Led_Stm32F103C8.bin \


# All Target
all: Toggle_Led_Stm32F103C8.elf secondary-outputs

# Tool invocations
Toggle_Led_Stm32F103C8.elf: $(OBJS) $(USER_OBJS) D:\MY\ Courses\Embedded\ Kero\Code\Master-Embedded-Systems\Unit6\Lesson4\Toggle_Led_Stm32\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "Toggle_Led_Stm32F103C8.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\MY Courses\Embedded Kero\Code\Master-Embedded-Systems\Unit6\Lesson4\Toggle_Led_Stm32\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Toggle_Led_Stm32F103C8.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Toggle_Led_Stm32F103C8.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Toggle_Led_Stm32F103C8.list"
	@echo 'Finished building: $@'
	@echo ' '

Toggle_Led_Stm32F103C8.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Toggle_Led_Stm32F103C8.bin"
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
