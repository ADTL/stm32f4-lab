TARGET=main.hex
EXECUTABLE=main.elf

CC=arm-none-eabi-gcc
#LD=arm-none-eabi-ld 
LD=arm-none-eabi-gcc
AR=arm-none-eabi-ar
AS=arm-none-eabi-as
CP=arm-none-eabi-objcopy
OD=arm-none-eabi-objdump

BIN=$(CP) -O ihex 

DEFS = -DUSE_STDPERIPH_DRIVER -DSTM32F4XX -DMANGUSTA_DISCOVERY -DUSE_USB_OTG_FS -DHSE_VALUE=8000000

MCU = cortex-m4
MCFLAGS = -mcpu=$(MCU) -mthumb -mlittle-endian -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb-interwork -std=c99

STM32_INCLUDES = -Istm32f4/discovery \
	-Istm32f4/CMSIS/Include/ \
	-Istm32f4/CMSIS/ST/ \
	-Istm32f4/peripherals/inc/
	
FREERTOS_INCLUDES = -Ifreertos/include -Ifreertos/portable/GCC/ARM_CM4F


OPTIMIZE       = -Os

CFLAGS	= $(MCFLAGS)  $(OPTIMIZE)  $(DEFS) -I./ $(STM32_INCLUDES) $(FREERTOS_INCLUDES) -Wl,-T,stm32_flash.ld
AFLAGS	= $(MCFLAGS)
 
#-mapcs-float use float regs. small increase in code size

#STM32_USB_OTG_SRC = ../../Libraries/STM32_USB_OTG_Driver/src/usb_dcd_int.c \
#	../../Libraries/STM32_USB_OTG_Driver/src/usb_core.c \
#	../../Libraries/STM32_USB_OTG_Driver/src/usb_dcd.c \

#STM32_USB_DEVICE_SRC = ../../Libraries/STM32_USB_Device_Library/Class/hid/src/usbd_hid_core.c \
#	../../Libraries/STM32_USB_Device_Library/Core/src/usbd_req.c \
#	../../Libraries/STM32_USB_Device_Library/Core/src/usbd_core.c \
#	../../Libraries/STM32_USB_Device_Library/Core/src/usbd_ioreq.c

SRC = src/main.c \
	stm32f4/discovery/system_stm32f4xx.c \
	stm32f4/discovery/stm32f4_discovery.c \
	stm32f4/peripherals/src/stm32f4xx_syscfg.c \
	stm32f4/peripherals/src/misc.c \
	stm32f4/peripherals/src/stm32f4xx_gpio.c \
	stm32f4/peripherals/src/stm32f4xx_rcc.c \
	stm32f4/peripherals/src/stm32f4xx_exti.c \
	stm32f4/peripherals/src/stm32f4xx_usart.c \
	stm32f4/peripherals/src/stm32f4xx_i2c.c \
	stm32f4/peripherals/src/stm32f4xx_spi.c \
	freertos/tasks.c \
	freertos/queue.c \
	freertos/list.c \
	freertos/croutine.c \
	freertos/timers.c \
	freertos/portable/MemMang/heap_2.c \
	freertos/portable/GCC/ARM_CM4F/port.c 

#	stm32f4/discovery/stm32f4xx_it.c \
#	stm32f4/discovery/stm32f4_discovery_lis302dl.c \
#	stm32f4/discovery/stm32f4_discovery_audio_codec.c \
#	stm32f4/peripherals/src/stm32f4xx_adc.c \
#	stm32f4/peripherals/src/stm32f4xx_dma.c \
#	stm32f4/peripherals/src/stm32f4xx_flash.c \
#	stm32f4/peripherals/src/stm32f4xx_tim.c \
#	stm32f4/peripherals/src/stm32f4xx_dac.c \



STARTUP = startup_stm32f4xx.S

OBJDIR = .
OBJ = $(SRC:%.c=$(OBJDIR)/%.o) 
OBJ += Startup.o

all: $(TARGET)

$(TARGET): $(EXECUTABLE)
	$(CP) -O ihex $^ $@

$(EXECUTABLE): $(SRC) $(STARTUP)
	$(CC) $(CFLAGS) $^ -lm -lc -lnosys -o $@

clean:
	rm -f Startup.lst  $(TARGET)  $(TARGET).lst $(OBJ) $(AUTOGEN)  $(TARGET).out  $(TARGET).hex  $(TARGET).map \
	 $(TARGET).dmp  $(TARGET).elf
