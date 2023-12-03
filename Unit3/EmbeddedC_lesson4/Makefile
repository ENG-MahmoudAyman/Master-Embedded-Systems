# Mahmoud Ayman
CC="D:Installed programs\STM32CubeIDE_1.4.0\STM32CubeIDE\plugins\com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.7-2018-q2-update.win32_1.4.0.202007081208\tools\bin\arm-none-eabi-"
CFLAGS=-mcpu=cortex-m4 -gdwarf-2 -g 
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
AS = $(wildcard *.s)
OBJ = $(SRC:.c=.o) $(AS:.s=.o)
Project_name=Lab3

All: $(Project_name).bin
	@echo "======Build is Done======"

%.o: %.s
	$(CC)as.exe $(CFLAGS) $(INCS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(Project_name).elf: $(OBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) -o $@ -Map=Map_file.map

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.elf *.bin
	@echo "======Clean_all is Done======"

clean:
	rm *.elf *.bin
	@echo "======Clean Execution Files is Done======"