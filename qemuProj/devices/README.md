# Qemu Notes #

It really is just easier building and launching qemu on ubuntu.  I tried windows on windows, windows on ubuntu on windows.  Eventually just dug out an old laptop to image.  Whatever latest ubuntu release should work.  

- Handy bunch of libraries, some (all?) are required
(sudo) apt install \
    build-essential \
    meson \
    ninja-build \
    pkg-config \
    diffutils \
    python3 \
    python3-venv \
    libglib2.0-dev \
    libusb-1.0-0-dev \
    libncursesw5-dev \
    libpixman-1-dev \
    libepoxy-dev \
    libv4l-dev \
    libpng-dev \
    libsdl2-dev \
    libsdl2-image-dev \
    libgtk-3-dev \
    libgdk-pixbuf2.0-dev \
    libasound2-dev \
    libpulse-dev \
    libx11-dev \
    libslirp-dev # needed for configuring network via virtio

Or, here's the list in one line
sudo apt install build-essential meson ninja-build pkg-config diffutils python3 python3-venv libglib2.0-dev libusb-1.0-0-dev libncursesw5-dev libpixman-1-dev libepoxy-dev libv4l-dev libpng-dev libsdl2-dev libsdl2-image-dev libgtk-3-dev libgdk-pixbuf2.0-dev libasound2-dev libpulse-dev libx11-dev 

I'm using a PDF detailing the steps to compile and add device for qemu windows instance.  It's an ebook written by Apriorit Inc. called "How to Develop Embedded Software Using the QEMU Machine Emulator".  Not including it here since it looks copyright-y.
The book assumes a stable qemu branch, ubuntu OS for build/launching qemu.

Qemu configuration details start on page 28 for my PDF. Here's the short versions of the commands:
./configure \
--target-list=x86_64-softmmu \
--enable-sdl \
--enable-debug \
--extra-ldflags="`pkg-config --libs openssl`" \
--enable-slirp

make

Note - Use the curly apostrophe for ldflgs args (non-shift tilda key)

From here, the windows and linux (RHEL) install diverge.

-------------------------------------------------------------------------------
--------------------------   WINDOWS VM SETUP ---------------------------------
-------------------------------------------------------------------------------

You'll have to create a qemu hard drive for windows.  Use qemu-img (in the build folder) to create an image of appropriate size. 

qemu-img create -f qcow2 windowsDev.img 60G

Then, start your first qemu-system-x86_64 with the windows 10 bootable ISO (google), add argument as -cdrom /<path>/WindowsImage.iso

Should look something like...
./build/qemu-system-x86_64 \
 -enable-kvm \
 -m 4G \ 
 -cpu host \
 -smp cpus=4,cores=4,threads=1,sockets=1 \
 -hda /<path>/windowsDev.img \
 -cdrom /<path>/windowsImage.iso 

Do NOT use the snapshot option as noted in the guide, it's used to throw away all changes to the drive, opposite of what we're trying to do 

Go through windows installation, then you can remove the -cdrom option and just use your windowsDev.img drive. 

Next up, loading virtio network devices so that you can enable network connection on the VM.  We'll need to load the virtio ISO the same way we loaded the windows ISO.  I installed the drivers from the ISO, then added the virtio network card, but it might be able to be done all at once.  Here's the process separated:

Virtio ISO download:
https://fedorapeople.org/groups/virt/virtio-win/direct-downloads/stable-virtio/virtio-win.iso

./build/qemu-system-x86_64 \
 -enable-kvm \
 -m 4G \ 
 -cpu host \
 -smp cpus=4,cores=4,threads=1,sockets=1 \
 -hda /<path>/windowsDev.img \
 -cdrom /<path>/virtioDownload.iso

Hop into vm, open disk, install, shutdown.  Then, use virtio network card

./build/qemu-system-x86_64 \
 -enable-kvm \
 -m 4G \ 
 -cpu host \
 -smp cpus=4,cores=4,threads=1,sockets=1 \
 -hda /<path>/windowsDev.img \
 -nic user,model=virtio-net-pci

At this point, you should have a connected windows VM.

--------------------- END WINDOWS VM INSTALL -----------------------------


--------------------------------------------------------------------------
--------------------- LINUX (RHEL) VM INSTALL ----------------------------
--------------------------------------------------------------------------

You'll have to create a qemu hard drive for RHEL.  Use qemu-img (in the build folder) to create an image of appropriate size. 

qemu-img create -f qcow2 rhel.img 50G

Then, start your first qemu-system-x86_64 with the RHEL ISO (google), add argument as -cdrom /<path>/rhel-download.iso

Should look something like...
./build/qemu-system-x86_64 \
 -enable-kvm \
 -m 4G \ 
 -cpu host \
 -smp cpus=4,cores=4,threads=1,sockets=1 \
 -hda /<path>/rhel.img \
 -cdrom /<path>/rhel-download.iso 
 -nic user,model=virtio

Hop into the VM, pick software packages and install.  DO NOT USE -snapshot, as noted in the guide.  Once installation is done, you can remove the -cdrom option

Network configuration is a little tricky with ubuntu, ping doesn't work because ICMP is not supported.  After burning half a day trying all sorts of linux trickery, I found this "answer":
https://stackoverflow.com/questions/67163568/cant-ping-linux-image-running-on-qemu

So, short answer is that internet access is easy and set up by default, but ssh and basic protocols are tricky.  Oof. I think, all things considered, if I can use internet/cloud based interactions (e.g. linux equivalent of teamviewer), that'd be the best solution for now.  

TODO: Machine access

------------------- END LINUX VM INSTALL ---------------------------------


Next up, devices...

By default, qemu has a well documented blank PCI device, you can enable it by adding '-device edu' to the executable.  In the windows VM -> device manager, it should show up under "Other Devices", with no attached driver.

Currently looking into the best way to integrate adding a new device without modifying the qemu submodule, for portability...



-------------------------- OLD NOTES -----------------------------------

* The below notes are old news, kept in case I try again to use Windows to build another Windows instance. I think it's possible, but almost all documentation is tailored towards ubuntu, translating it is beyond my knowledge.  Have seen some recent comments say it isn't possible. *
- Download the qemu source on whatever OS you're compiling it on - cloning the repo in windows will screw with the venv loading in ubuntu
- Enable windows HyperVisor to use whpx
- Ran into issues with my windows desktop running ubuntu 24.04.1 in VMWare, went with 24.10.  24.04.1 works on my laptop *shrug* 

https://superuser.com/questions/1707218/why-qemu-cant-detect-a-whpx-hyper-v-accelerator
https://github.com/xqemu/xqemu/issues/112

B. Quick note, but no details: https://www.qemu.org/docs/master/about/build-platforms.html#windows

C. More details, using msys2: https://wiki.qemu.org/Hosts/W32#Native_builds_with_MSYS2

D. For above, some corrections based on random googling:
- Instead of opening ucrt64.exe after package installations, open MSYS2 mingw_64 in administrator
- I may or may not have had to add the following two lines:
pacman -S mingw-w64-x86_64-python3 
pacman -S mingw-w64-x86_64-meson




