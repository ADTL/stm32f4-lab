CC=arm-none-eabi-gcc
AR=arm-none-eabi-ar
OBJCOPY=arm-none-eabi-objcopy
SZ=arm-none-eabi-size

###################################################

# Project name
PROJ_NAME=accelerometer
OBJDIR=build

# Sources

SRCS = startup_stm32f4xx.s \
	main.c \
	stm32f4xx_it.c \
	stm32f4_discovery_lis302dl.c
	
	
###################################################

# Check for valid float argument
# NOTE that you have to run make clan after
# changing these as hardfloat and softfloat are not
# binary compatible
ifneq ($(FLOAT_TYPE), hard)
ifneq ($(FLOAT_TYPE), soft)
override FLOAT_TYPE = hard
#override FLOAT_TYPE = soft
endif
endif

###################################################

CFLAGS  = -std=gnu99 -Os -Tstm32_flash.ld
CFLAGS += --specs=nano.specs
CFLAGS += -mlittle-endian -mthumb -mthumb-interwork -mcpu=cortex-m4

#CFLAGS += -Wall -Wfatal-errors    <---- use it while developing

ifeq ($(FLOAT_TYPE), hard)
CFLAGS += -fsingle-precision-constant -Wdouble-promotion
CFLAGS += -mfpu=fpv4-sp-d16 -mfloat-abi=hard
else
CFLAGS += -msoft-float
endif

###################################################

vpath %.c src lib/lua/src
vpath %.s lib
vpath %.a li

ROOT=$(shell pwd)

# Includes
CFLAGS += -I. -Ilib/stm32f4/cmsis/st -Ilib/stm32f4/cmsis/include
CFLAGS += -Ilib/Conf


# Library paths
LIBPATHS = -Llib/stm32f4

# Libraries to link
LIBS = -lstm32f4
LIBS += -lc -lnosys


# Extra includes
CFLAGS += -Ilib/stm32f4/include

OBJS = $(SRCS:.c=.o)

USE_BOOTLOADER_OFFSET = 0x0000

###################################################

.PHONY: lib proj

all: lib dir proj
	$(SZ) $(OBJDIR)/$(PROJ_NAME).elf

lib:
	$(MAKE) -C lib FLOAT_TYPE=$(FLOAT_TYPE)

proj: 	$(OBJDIR)/$(PROJ_NAME).elf

dir:
	test -d $(OBJDIR) || mkdir $(OBJDIR)

$(OBJDIR)/$(PROJ_NAME).elf: $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBPATHS) $(LIBS)
	$(OBJCOPY) -O ihex $(OBJDIR)/$(PROJ_NAME).elf $(OBJDIR)/$(PROJ_NAME).hex
	$(OBJCOPY) -O binary $(OBJDIR)/$(PROJ_NAME).elf $(OBJDIR)/$(PROJ_NAME).bin

clean:
	rm -f *.o
	rm -f $(OBJDIR)/$(PROJ_NAME).elf
	rm -f $(OBJDIR)/$(PROJ_NAME).hex
	rm -f $(OBJDIR)/$(PROJ_NAME).bin

cleanlibs:
	$(MAKE) clean -C lib
