#pragma once
/*

 Source for defining various needed structures, macros, data for this driver

*/

// All include's declared in precomp.h

// Example structure for register space, meaningless for now
typedef struct exampleRegs {
	USHORT reg1;
	USHORT reg2;
	USHORT reg3;
	
	// TODO: I'm really more comfortable with ctypes, but stdint throws warnings?
	// at the moment
	//uint32_t signature;
	//uint32_t crc;
	//uint32_t status;
	//uint32_t abunch[16];
} exampleRegs;


// Extension of WDF device, feilds are meaningless for now
typedef struct deviceExtension {
	WDFDEVICE device;
	exampleRegs regs;
	PUCHAR regsBase;
	ULONG regsLength;
} DEVICE_EXTENSION;

//  This will generate the function to be used for retreiving 
//  the DEVICE_EXTENSION pointer.
WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(DEVICE_EXTENSION, qemuGetDeviceContext);

//	Attempting to define an interface guid? 
//DEFINE_GUID (GUID_QEMU, );