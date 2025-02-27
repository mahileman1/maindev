# Define the module name
obj-m += qemuDriver.o
qemuDriver-objs := src/main.o 

# Specify the directory containing the kernel source
KDIR := /lib/modules/$(shell uname -r)/build

# Add the "include" directory as an include directory
ccflags-y += -I$(PWD)/include

BUILD_DIR := $(PWD)/bin
BUILD_DIR_MAKEFILE := $(BUILD_DIR)/Makefile


# Default target
all: $(BUILD_DIR_MAKEFILE)
	$(MAKE) -C $(KDIR) M=$(BUILD_DIR) modules

$(BUILD_DIR):
	mkdir -p "$@"

$(BUILD_DIR_MAKEFILE): $(BUILD_DIR)	
	touch "$@"

# Clean target
clean:
	$(MAKE) -C $(KDIR) M=$(BUILD_DIR) clean