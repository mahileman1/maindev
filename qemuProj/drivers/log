All of my research indicated that the easiest path forward was to just use Visual Studio to initialize the kernel driver project.   Let it be known that I wanted to write it from scratch :)

I initially followed Microsoft's doc:
https://learn.microsoft.com/en-us/windows-hardware/drivers/gettingstarted/writing-a-very-small-kmdf--driver

At first I tried the non-empty "skeleton" kernel template, never got the dependencies to line up.  I stayed with just the empty "Hello World" driver noted on that page.

1. Install latest Visual Studio
2. Install packages:
- Desktop Development
(Individual Components)
MSVC v143 - VS 2022 C++ ARM64/ARM64EC Spectre-mitigated libs (Latest)
MSVC v143 - VS 2022 C++ x64/x86 Spectre-mitigated libs (Latest)
C++ ATL for latest v143 build tools with Spectre Mitigations (ARM64/ARM64EC)
C++ ATL for latest v143 build tools with Spectre Mitigations (x86 & x64)
C++ MFC for latest v143 build tools with Spectre Mitigations (ARM64/ARM64EC)
C++ MFC for latest v143 build tools with Spectre Mitigations (x86 & x64)
Windows Driver Kit

VS's intaller is hard to parse through, I suggest searching "c++ latest spectre" and check everything

I then directly installed latest:
Windows SDK https://developer.microsoft.com/en-us/windows/downloads/windows-sdk/
WDK https://learn.microsoft.com/en-us/windows-hardware/drivers/download-the-wdk

Yes, WDK is re-downloaded.  

I also added this to vc++ directories
C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\km;C:\Program Files (x86)\Windows Kits\10\Include\wdf\kmdf\1.33

I added the build folders to .gitignore for portability

Starting with this guide for now:
https://learn.microsoft.com/en-us/windows-hardware/drivers/pci/

It points to this example:
https://github.com/microsoft/windows-driver-samples/tree/main/general/PLX9x5x

2-16-2025
I've been working on structuring the driver to attach to the device, I found a couple very useful sources:
For driver install definitions, i.e. how to define your driver and attach which devices to attach to, the fields in this sections are useful:
https://learn.microsoft.com/en-us/windows-hardware/drivers/install/inf-version-section

Also, found a new driver sample in that same git directory that is also very helpful
https://github.com/microsoft/Windows-driver-samples/tree/main/general/pcidrv

With those two examples, I was able to piece together something that compiles and attaches!

I transferred over the entire "Debug" folder to VM in qemuProj/drivers/qemuDriver/x64/
Then, in qemuDriverK, right click qemuDriverK.inf and install.  It should show up in device manager now :) 
