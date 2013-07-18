CC=arm-none-eabi-gcc
AR=arm-none-eabi-ar

###########################################

vpath %.c src src/peripherals

CFLAGS  = -g -O -Wall -DUSE_STDPERIPH_DRIVER
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS += -ffreestanding -nostdlib
CFLAGS += -Iinclude -Iportable/GCC/ARM_CM4F

SRCS = 	tasks.c \
	queue.c \
	list.c \
	croutine.c \
	timers.c \
	portable/MemMang/heap_2.c \
	portable/GCC/ARM_CM4F/port.c 

OBJS = $(SRCS:.c=.o)

.PHONY: libfreertos.a

all: libfreertos.a

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

libfreertos.a: $(OBJS)
	$(AR) -r $@ $(OBJS)
	rm -f $(OBJS)
	

clean:
	rm -f $(OBJS) libfreertos.a
	