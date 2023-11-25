# Mahmoud Ayman

Lab1.bin:  uart.c app.c startup.s
	arm-none-eabi-as.exe -g -mcpu=arm926ej-s startup.s -o startup.o
	arm-none-eabi-gcc.exe -c -g -mcpu=arm926ej-s app.c -o app.o
	arm-none-eabi-gcc.exe -c -g -mcpu=arm926ej-s uart.c -o uart.o
	arm-none-eabi-ld.exe -T linker_script.ld app.o uart.o startup.o -o Lab1.elf
	arm-none-eabi-objcopy.exe -O binary Lab1.elf Lab1.bin