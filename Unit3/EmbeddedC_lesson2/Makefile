# Mahmoud Ayman

All: Lab1.bin
	

startup.o: startup.s
	arm-none-eabi-as.exe -g -mcpu=arm926ej-s startup.s -o startup.o

app.o: app.c
	arm-none-eabi-gcc.exe -c -g -mcpu=arm926ej-s app.c -o app.o

uart.o: uart.c
	arm-none-eabi-gcc.exe -c -g -mcpu=arm926ej-s uart.c -o uart.o

Lab1.elf: uart.o app.o startup.o
	arm-none-eabi-ld.exe -T linker_script.ld app.o uart.o startup.o -o Lab1.elf

Lab1.bin: Lab1.elf
	arm-none-eabi-objcopy.exe -O binary Lab1.elf Lab1.bin

clean_all:
	rm *.o *.elf *.bin

clean:
	rm *.elf *.bin
