# Define the module name
obj-m += qemuDriver.o

# Specify the directory containing the kernel source
KDIR := /lib/modules/$(shell uname -r)/build

# Specify the directory containing the source files
PWD := $(shell pwd)

# Add the "include" directory as an include directory
EXTRA_CFLAGS += -I$(PWD)/include

# Default target
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

# Clean target
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean