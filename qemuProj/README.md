Added Febrary 1st, 2025:

The intent of this project is to make an easy to follow implementation of a top-to-bottom, hardware to user, programmable PCI device in Windows and RHEL. I'll be using a basic build of Qemu with a custom PCI device injected to start up either a Windows or RHEL VM.  I'll be tracking general details here, see log for building details/tutorials

Using teamviewer for windows remote desktop, since remote desktop isn't available for windows home. Still figuring out RHEL access. 

Project specific qemu install params (and help) is in the devices folder

As of February 18th, I'm switching priorities over to Linux, to be focused more towards the defense industry. 

TODO:

[x] Get qemu building 
[x] Add generic qemu PCI device to image
[ ] Add custom PCI device to image
[x] Add basic windows kernel driver
[x] Attach kernel driver to qemu device
[ ] Establish user to device interactions

Windows:
[x] Get win64 image loading/running/accessible via remote desktop
[x] Add generic qemu PCI device to image
[ ] Add custom PCI device to image
[x] Add basic windows kernel driver
[x] Attach kernel driver to qemu device
[ ] Communicate kernel driver -> qemu device, via I/O
[x] Add windows user-mode driver
[ ] Connect to and use user-mode driver
[ ] Connect user-mode and kernel driver

Linux: 
[ ] Get RHEL image loading/running/accessible
[x] Add generic qemu PCI device to image
[ ] Add custom device to image
[ ] Add basic kernel module
[ ] Attach kernel module to qemu device
[ ] Communicate kernel driver -> qemu device, via I/O

Other possibilities?
[ ] Python library
[ ] Debugging tools (symbol production, link source)
[ ] VM Infrastructure/management tools
[ ] Scripts for easy install/configuration
