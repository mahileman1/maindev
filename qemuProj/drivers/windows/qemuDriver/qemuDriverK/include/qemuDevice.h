#pragma once
/*

 Source for defining various needed structures, macros, data for this driver

*/

// All include's declared in precomp.h

// Extension of WDF device, feilds are meaningless for now
typedef struct deviceExtension {
	WDFDEVICE device;
	qemuDeviceRegs regs; // defined in qemuProj/common/qemuStructs.h
	PUCHAR regsBase;
	ULONG regsLength;
} qemuDeviceExtension;

//  This will generate the function to be used for retreiving 
//  the DEVICE_EXTENSION pointer.
WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(qemuDeviceExtension, qemuGetDeviceContext);

//	Attempting to define an interface guid? 
//DEFINE_GUID (GUID_QEMU, );