CC=arm-none-eabi-gcc
AR=arm-none-eabi-ar

###########################################

vpath %.c src src/peripherals

CFLAGS  = -g -Wall 
CFLAGS += -DUSE_STDPERIPH_DRIVER
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS += -ffreestanding -nostdlib
CFLAGS += -Iperipherals/include -Idiscovery -ICMSIS/Include -ICMSIS/ST -Iinc/core -Iinc/peripherals
#CFLAGS += -O 
#CFLAGS += -mapcs-float use float regs. small increase in code size

SRCS = peripherals/src/misc.c \
	peripherals/src/stm32f4xx_adc.c \
	peripherals/src/stm32f4xx_dma.c \
	peripherals/src/stm32f4xx_tim.c \
	peripherals/src/stm32f4xx_dac.c \
	peripherals/src/stm32f4xx_rcc.c \
	peripherals/src/stm32f4xx_exti.c \
	peripherals/src/stm32f4xx_rng.c \
	peripherals/src/stm32f4xx_rtc.c \
	peripherals/src/stm32f4xx_crc.c \
	peripherals/src/stm32f4xx_fsmc.c \
	peripherals/src/stm32f4xx_sdio.c \
	peripherals/src/stm32f4xx_cryp_aes.c \
	peripherals/src/stm32f4xx_gpio.c \
	peripherals/src/stm32f4xx_spi.c \
	peripherals/src/stm32f4xx_cryp.c \
	peripherals/src/stm32f4xx_hash.c \
	peripherals/src/stm32f4xx_syscfg.c \
	peripherals/src/stm32f4xx_i2c.c \
	peripherals/src/stm32f4xx_wwdg.c \
	peripherals/src/stm32f4xx_dbgmcu.c \
	peripherals/src/stm32f4xx_iwdg.c \
	peripherals/src/stm32f4xx_dcmi.c \
	peripherals/src/stm32f4xx_cryp_des.c \
	peripherals/src/stm32f4xx_flash.c \
	peripherals/src/stm32f4xx_can.c \
	peripherals/src/stm32f4xx_hash_md5.c \
	peripherals/src/stm32f4xx_cryp_tdes.c \
	peripherals/src/stm32f4xx_hash_sha1.c  \
	peripherals/src/stm32f4xx_usart.c \
	peripherals/src/stm32f4xx_pwr.c

	
SRCS += discovery/system_stm32f4xx.c \
	discovery/stm32f4_discovery.c 
	
	


#STM32_USB_OTG_SRC = ../../Libraries/STM32_USB_OTG_Driver/src/usb_dcd_int.c \
#	../../Libraries/STM32_USB_OTG_Driver/src/usb_core.c \
#	../../Libraries/STM32_USB_OTG_Driver/src/usb_dcd.c \

#STM32_USB_DEVICE_SRC = ../../Libraries/STM32_USB_Device_Library/Class/hid/src/usbd_hid_core.c \
#	../../Libraries/STM32_USB_Device_Library/Core/src/usbd_req.c \
#	../../Libraries/STM32_USB_Device_Library/Core/src/usbd_core.c \
#	../../Libraries/STM32_USB_Device_Library/Core/src/usbd_ioreq.c

	

OBJS = $(SRCS:.c=.o)

.PHONY: libstm32f4.a

all: libstm32f4.a

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

libstm32f4.a: $(OBJS)
	$(AR) -r $@ $(OBJS)
	rm -f $(OBJS)
	

clean:
	rm -f $(OBJS) libstm32f4.a
	