# **maindev - Mark Hileman**
Hi! Welcome in.  I made coffee at some point in the last three days, it's here somewhere. This is a generic repo holding some personal projects of mine.

## Projects:
### qemuProj
Trying to implement top-to-bottom, end user to PCI device, functional device emulation in windows and linux. I'm using Qemu to emulate a windows VM with an attached generic PCI device.  I plan to implement a custom PCI device, kernel and user-mode drivers.  Check out the in-folder docs for more info :) 

### stm32CanProj
Looking into possibly emulating an ABS solenoid with an stm32, eventually to remove said solenoid from a motorcycle.  Need to grab and spoof CAN messages to avoid the ECU freaking out. Practical? No. Safe? Also...no.
As of February 1st 2025 this project is stalled since I accidentally bought an stm32 without a CAN controller.  I'm making $11/hr.  RIP

### Idea - AI-powered "danger" meter for motorcyclists
While autonomous driving is a big deal, I had the (not so) bright idea of making some kind of estimated danger quantifier for motorcyclists. We could scrape for motorcycle gopro crash footage (no pun intended), to train for a likelihood of an accident.  It'd be cool if I didn't have to do annotation...
