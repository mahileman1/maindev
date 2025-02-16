/*

This file is meant to contain all the callback methods for generic driver 
interactions.  This structure will likely change as the project needs change.

*/

#include "precomp.h"

NTSTATUS qemuPrepHW(
	WDFDEVICE device,
	WDFCMRESLIST resources,
	WDFCMRESLIST resourcesTranslated
)
{
	UNREFERENCED_PARAMETER(device);
	UNREFERENCED_PARAMETER(resources);
	UNREFERENCED_PARAMETER(resourcesTranslated);
	return STATUS_SUCCESS;
}

NTSTATUS qemuReleaseHW(
	IN WDFDEVICE device,
	IN WDFCMRESLIST resourcesTranslated
)
{
	UNREFERENCED_PARAMETER(device);
	UNREFERENCED_PARAMETER(resourcesTranslated);
	return STATUS_SUCCESS;
}

NTSTATUS qemuD0Entry(
	IN WDFDEVICE device,
	IN WDF_POWER_DEVICE_STATE prevState
)
{
	UNREFERENCED_PARAMETER(device);
	UNREFERENCED_PARAMETER(prevState);
	return STATUS_SUCCESS;
}

NTSTATUS qemuD0Exit(
	IN WDFDEVICE device,
	IN WDF_POWER_DEVICE_STATE targetState
)
{
	UNREFERENCED_PARAMETER(device);
	UNREFERENCED_PARAMETER(targetState);
	return STATUS_SUCCESS;
}

VOID qemuDeviceCleanup(
	_In_ WDFOBJECT device
)
{
	UNREFERENCED_PARAMETER(device);
}


VOID qemuDriverCleanup(
	IN WDFOBJECT driver
)
{
	UNREFERENCED_PARAMETER(driver);
}