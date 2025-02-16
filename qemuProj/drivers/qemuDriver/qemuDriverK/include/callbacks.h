#pragma once

/*

Declarations for specific callbacks to be registered with windows managers
(e.g. PnP)

*/

// All include's declared in precomp.h

DRIVER_INITIALIZE DriverEntry;

EVT_WDF_DRIVER_DEVICE_ADD qemuEvtDeviceAdd;

EVT_WDF_OBJECT_CONTEXT_CLEANUP qemuDriverCleanup;
EVT_WDF_DEVICE_CONTEXT_CLEANUP qemuDeviceCleanup;

EVT_WDF_DEVICE_D0_ENTRY qemuD0Entry;
EVT_WDF_DEVICE_D0_EXIT qemuD0Exit;

EVT_WDF_DEVICE_PREPARE_HARDWARE qemuPrepHW;
EVT_WDF_DEVICE_RELEASE_HARDWARE qemuReleaseHW;

