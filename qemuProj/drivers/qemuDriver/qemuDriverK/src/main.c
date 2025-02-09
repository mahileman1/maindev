// Finally, some code


#include <ntddk.h>
#include <wdf.h>


DRIVER_INITIALIZE DriverEntry;
EVT_WDF_DRIVER_DEVICE_ADD KmdfEvtQemuDeviceAdd;

// DriverObject -> Pointer to driver object
// RegistryPath -> pointer to path (string) to driver-specific registry key
NTSTATUS
DriverEntry(
    _In_ PDRIVER_OBJECT     DriverObject,
    _In_ PUNICODE_STRING    RegistryPath
)
{
    NTSTATUS status = STATUS_SUCCESS;
    // Allocate the driver configuration object
    WDF_DRIVER_CONFIG config;

    // Initialize the driver configuration with callback
    WDF_DRIVER_CONFIG_INIT(&config, qemuEvtDeviceAdd);

    status = WdfDriverCreate(
        DriverObject,
        RegistryPath,
        WDF_NO_OBJECT_ATTRIBUTES,
        &config,
        WDF_NO_HANDLE
    );

    return status;
}

// EvtDeviceAdd is called by the framework in response to AddDevice
// call from the PnP manager.Here the driver should register all the
// PNP, power and Io callbacks, register interfaces and allocate other
// software resources required by the device.The driver can query
// any interfaces or get the config space information from the bus driver
// but cannot access hardware registers or initialize the device.

NTSTATUS
qemuEvtDeviceAdd(
    _In_    WDFDRIVER       Driver,
    _Inout_ PWDFDEVICE_INIT DeviceInit
)
{
    UNREFERENCED_PARAMETER(Driver);

    NTSTATUS status = STATUS_SUCCESS;

    // Allocate the device object
    WDFDEVICE device;

    // Print "Hello World"
    KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "KmdfHelloWorld: KmdfHelloWorldEvtDeviceAdd\n"));

    // Create the device object
    status = WdfDeviceCreate(&DeviceInit,
        WDF_NO_OBJECT_ATTRIBUTES,
        &device
    );
    return status;
}