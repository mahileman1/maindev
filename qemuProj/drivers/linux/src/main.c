#include <linux/module.h>
#include <linux/pci.h>
#include <linux/kernel.h>

#include "qemuDevice.h"

#define VENDOR_ID 0x1234
#define DEVICE_ID 0x11E8

static int my_pci_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
    printk(KERN_INFO "PCI device found: vendor=0x%x, device=0x%x\n", id->vendor, id->device);
    return 0;
}

static void my_pci_remove(struct pci_dev *dev)
{
    printk(KERN_INFO "PCI device removed\n");
}

static const struct pci_device_id my_pci_ids[] = {
    { PCI_DEVICE(VENDOR_ID, DEVICE_ID) },
    { 0, }
};

MODULE_DEVICE_TABLE(pci, my_pci_ids);

static struct pci_driver my_pci_driver = {
    .name = "my_pci_driver",
    .id_table = my_pci_ids,
    .probe = my_pci_probe,
    .remove = my_pci_remove,
};

static int __init my_pci_init(void)
{
    return pci_register_driver(&my_pci_driver);
}

static void __exit my_pci_exit(void)
{
    pci_unregister_driver(&my_pci_driver);
}

MODULE_AUTHOR("Mark Hileman");
MODULE_DESCRIPTION("PCI Driver for Qemu edu device");
MODULE_VERSION("0.1");

module_init(my_pci_init);
module_exit(my_pci_exit);