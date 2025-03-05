/*

 Source for defining various needed structures, macros, data for this driver

*/

// Taken from qemu source -> qemu/hw/misc/edu.c
typedef struct readRegs {
	unsigned int deviceID;	 // [0x00]
	unsigned int addr4;		 // [0x04]
	unsigned int fact;		 // [0x08]
	unsigned int space0[3];  // [0x12 - 0x16]
	unsigned int status;	 // [0x20]
	unsigned int irqStatus;	 // [0x24]
	unsigned int space1[14]; // [0x28 - 0x76]
	unsigned int dmaSrc;	 // [0x80]
	unsigned int space2;     // [0x84]
	// edu goes from 0x88 -> 0x90 for some reason
	unsigned short int dmaDst;	 // [0x88]
	unsigned int dmaCnt;	 // [0x90]
	unsigned int space3;     // [0x94]
	unsigned int dmaCmd;	 // [0x98]
} readRegs;

typedef struct writeRegs {
	unsigned int space0;	// [0x00]
	unsigned int addr4;		// [0x04]
	unsigned int fact;		// [0x08]
	unsigned int space1[3]; // [0x12 - 0x16]
	unsigned int status;	// [0x20]
	unsigned int space2[9]; // [0x24 - 0x56]
	unsigned int raiseIrq;	// [0x60]
	unsigned int lowerIrq;	// [0x64]
	unsigned int space3[3]; // [0x68 - 0x76]
	unsigned int dmaSrc;	// [0x80]
	unsigned int space4;    // [0x84]
	// edu goes from 0x88 -> 0x90 for some reason
	unsigned short int dmaDst;	// [0x88]
	unsigned int dmaCnt;	// [0x90]
	unsigned int space5;    // [0x94]
	unsigned int dmaCmd;	// [0x98]
} writeRegs;

//  !!  -- Union -- !!
// Trying this out just to have an excuse to use a union for once
// Just using it to separate out read-enabled and write-enabled registers
typedef union qemuDeviceRegs {
	readRegs read;
	writeRegs write;
} qemuDeviceRegs;

