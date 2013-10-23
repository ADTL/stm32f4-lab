CC=arm-none-eabi-gcc
AR=arm-none-eabi-ar

###################################################

# Check for valid float argument
ifneq ($(FLOAT_TYPE), hard)
ifneq ($(FLOAT_TYPE), soft)
override FLOAT_TYPE = hard
#override FLOAT_TYPE = soft
endif
endif

###################################################

vpath %.c src

CFLAGS  = -Os -Wall 
CFLAGS += -DUSE_STDPERIPH_DRIVER
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork

CFLAGS += -ffreestanding -nostdlib

ifeq ($(FLOAT_TYPE), hard)
CFLAGS += -fsingle-precision-constant -Wdouble-promotion
CFLAGS += -mfpu=fpv4-sp-d16 -mfloat-abi=hard
else
CFLAGS += -msoft-float
endif

ifdef USE_BOOTLOADER_OFFSET
CFLAGS += -DUSE_BOOTLOADER_OFFSET=$(USE_BOOTLOADER_OFFSET)
else

endif

# Includes
CFLAGS += -Iinclude -ICMSIS/Include -ICMSIS/ST -I../conf

# Sources
SRCS = src/misc.c \
	src/stm32f4xx_adc.c \
	src/stm32f4xx_dma.c \
	src/stm32f4xx_flash.c \
	src/stm32f4xx_tim.c \
	src/stm32f4xx_dac.c \
	src/stm32f4xx_rcc.c \
	src/stm32f4xx_exti.c \
	src/stm32f4xx_rtc.c \
	src/stm32f4xx_crc.c \
	src/stm32f4xx_fsmc.c \
	src/stm32f4xx_gpio.c \
	src/stm32f4xx_spi.c \
	src/stm32f4xx_syscfg.c \
	src/stm32f4xx_usart.c \
	src/stm32f4xx_i2c.c \
	src/stm32f4xx_pwr.c \
	src/system_stm32f4xx.c 
#	src/stm32f4xx_cryp.c \
#	src/stm32f4xx_hash.c \
#	src/stm32f4xx_cryp_des.c \
#	src/stm32f4xx_hash_md5.c \
#	src/stm32f4xx_cryp_tdes.c \
#	src/stm32f4xx_hash_sha1.c  \
#	src/stm32f4xx_rng.c \
#	src/stm32f4xx_can.c \
#	src/stm32f4xx_sdio.c \
#	src/stm32f4xx_cryp_aes.c \
#	src/stm32f4xx_wwdg.c \
#	src/stm32f4xx_dbgmcu.c \
#	src/stm32f4xx_iwdg.c \
#	src/stm32f4xx_dcmi.c \

OBJS = $(SRCS:.c=.o)
LIBNAME = libstm32f4.a

all: $(LIBNAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(LIBNAME): $(OBJS)
	$(AR) -r $@ $(OBJS)

clean:
	rm -f $(OBJS) $(LIBNAME)
	