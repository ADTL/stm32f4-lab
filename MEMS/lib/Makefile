# Build all libraries

# Check for valid float argument
ifneq ($(FLOAT_TYPE), hard)
ifneq ($(FLOAT_TYPE), soft)
override FLOAT_TYPE = hard
#override FLOAT_TYPE = soft
endif
endif

all:
	$(MAKE) -C stm32f4 FLOAT_TYPE=$(FLOAT_TYPE)


clean:
	$(MAKE) clean -C stm32f4

