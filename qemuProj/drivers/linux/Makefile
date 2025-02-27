# Define the module name
obj-m += qemuDriver.o
qemuDriver-objs := src/main.o 

# Specify the directory containing the kernel source
KDIR := /lib/modules/$(shell uname -r)/build

# Add the "include" directory as an include directory
ccflags-y += -I$(PWD)/include

# Default target
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

# Clean target
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean