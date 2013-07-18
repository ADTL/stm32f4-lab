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

OPTIMIZE = -O -g

DEFS = -DUSE_STDPERIPH_DRIVER -DSTM32F4XX -DMANGUSTA_DISCOVERY -DUSE_USB_OTG_FS -DHSE_VALUE=8000000

MCU = cortex-m4
MCFLAGS = -std=c99 -mcpu=$(MCU) -mthumb -mlittle-endian -mfpu=fpv4-sp-d16 -mfloat-abi=hard \
		-mthumb-interwork

STM32_INCLUDES = -Iinclude \
	-Ilib/stm32f4/discovery \
	-Ilib/stm32f4/CMSIS/Include/ \
	-Ilib/stm32f4/CMSIS/ST/ \
	-Ilib/stm32f4/peripherals/inc/ \
	-Ilib/stm32f4
	
FREERTOS_INCLUDES = -Ilib/freertos/include -Ilib/freertos/portable/GCC/ARM_CM4F

LUA_INCLUDES = -Ilib/lua/inc

LIBSTMF4 =-Llib/stm32f4/ -Llib/freertos -Llib/lua

CFLAGS	= $(MCFLAGS)  $(OPTIMIZE)  $(DEFS) -I./ $(STM32_INCLUDES) $(FREERTOS_INCLUDES) $(LUA_INCLUDES) 
CFLAGS  += -Wl,-T,stm32_flash.ld
AFLAGS	= $(MCFLAGS)
 
SRC = src/main.c \
	src/leds.c \
	src/usart.c \
	src/task-lua.c \
	src/task-stepmotor.c \
	src/lua-functions.c \
	lib/lua/src/lapi.c \
	lib/lua/src/lauxlib.c \
	lib/lua/src/lbaselib.c \
	lib/lua/src/lbitlib.c \
	lib/lua/src/lcode.c \
	lib/lua/src/lcorolib.c \
	lib/lua/src/lctype.c \
	lib/lua/src/ldblib.c \
	lib/lua/src/ldebug.c \
	lib/lua/src/ldo.c \
	lib/lua/src/ldump.c \
	lib/lua/src/lfunc.c \
	lib/lua/src/lgc.c \
	lib/lua/src/linit.c \
	lib/lua/src/liolib.c \
	lib/lua/src/llex.c \
	lib/lua/src/lmathlib.c \
	lib/lua/src/lmem.c \
	lib/lua/src/loadlib.c \
	lib/lua/src/lobject.c \
	lib/lua/src/lopcodes.c \
	lib/lua/src/loslib.c \
	lib/lua/src/lparser.c \
	lib/lua/src/lstate.c \
	lib/lua/src/lstring.c \
	lib/lua/src/lstrlib.c \
	lib/lua/src/ltable.c \
	lib/lua/src/ltablib.c \
	lib/lua/src/ltm.c \
	lib/lua/src/lundump.c \
	lib/lua/src/lvm.c \
	lib/lua/src/lzio.c
	
STARTUP = lib/stm32f4/CMSIS/Source/startup_stm32f4xx.S

OBJDIR = .
OBJ = $(SRC:%.c=$(OBJDIR)/%.o) 
OBJ += Startup.o

all: $(TARGET)

$(TARGET): $(EXECUTABLE)
	$(CP) -O ihex $^ $@

$(EXECUTABLE): $(SRC) $(STARTUP)
	$(CC) $(CFLAGS) $^ -lm -lc -lnosys -lstm32f4 -lfreertos $(LIBSTMF4) -o $@

clean:
	rm -f Startup.lst \
	$(NAME) $(NAME).lst \
	$(NAME).out \
	$(NAME).hex $(NAME).map \
	$(NAME).dmp $(NAME) $(EXECUTABLE)
#	$(OBJ) $(AUTOGEN) \
