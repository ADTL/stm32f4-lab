THIS PROJECT IS NOT WORKING

even assigning simple variables is causing segmentation faults


NAME=main
TARGET=$(NAME).hex
EXECUTABLE=$(NAME).elf

CC=arm-none-eabi-gcc
#LD=arm-none-eabi-ld 
LD=arm-none-eabi-gcc
AR=arm-none-eabi-ar
AS=arm-none-eabi-as
CP=arm-none-eabi-objcopy
OD=arm-none-eabi-objdump

#BIN=$(CP) ihex -g

OPTIMIZE = -g
#-O
DEFS = -DUSE_STDPERIPH_DRIVER -DSTM32F4XX
# -DMANGUSTA_DISCOVERY -DUSE_USB_OTG_FS -DHSE_VALUE=8000000

MCU = cortex-m4
MCFLAGS = -std=c99 -mcpu=$(MCU) -mthumb -mlittle-endian -mfpu=fpv4-sp-d16 \
	-mfloat-abi=hard 
#		-mthumb-interwork

STM32_INCLUDES = -Iinclude \
	-Ilib/stm32f4/discovery \
	-Ilib/stm32f4/CMSIS/Include/ \
	-Ilib/stm32f4/CMSIS/ST/ \
	-Ilib/stm32f4/peripherals/include/ \
	-Ilib/stm32f4
	
LIBSTMF4 =-Llib/stm32f4/

CFLAGS	= $(MCFLAGS)  $(OPTIMIZE)  $(DEFS) -I./ $(STM32_INCLUDES)
CFLAGS  += -Wl,-T,stm32_flash.ld
AFLAGS	= $(MCFLAGS)
 
SRC = src/main.c src/wav.c
	
STARTUP = lib/stm32f4/CMSIS/Source/startup_stm32f4xx.S

OBJDIR = .
OBJ = $(SRC:%.c=$(OBJDIR)/%.o) 
OBJ += Startup.o

all: $(TARGET)

$(TARGET): $(EXECUTABLE)
	$(CP) -O ihex $^ $@

$(EXECUTABLE): $(SRC) $(STARTUP)
	$(CC) $(CFLAGS) $^ -lm -lc -lnosys  $(LIBSTMF4) -o $@ -lstm32f4

clean:
	rm -f Startup.lst \
	$(NAME) $(NAME).lst \
	$(NAME).out \
	$(NAME).hex $(NAME).map \
	$(NAME).dmp $(NAME) $(EXECUTABLE)
#	$(OBJ) $(AUTOGEN) \
