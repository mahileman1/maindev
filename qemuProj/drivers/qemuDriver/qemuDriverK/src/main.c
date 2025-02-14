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
    WDFDEVICE device;

    WDF_PNPPOWER_EVENT_CALLBACKS pnpCallbacks;
    WDF_OBJECT_ATTRIBUTES attributes;
    // Specifying data buffer methods - can use buffered, undefined, max? 
    WdfDeviceInitSetIoType(DeviceInit, WdfDeviceIoDirect);

    // Clean slate
    WDF_PNPPOWER_EVENT_CALLBACKS_INIT(&pnpCallbacks);

    // Prep HW - called after PnP has assigned HW resources
    pnpCallbacks.EvtDevicePrepareHardware = qemuPrepHW;
    // Release HW - called after framework has stopped sending I/O
    // request, interrupts have been disabled, device has been turned off
    pnpCallbacks.EvtDeviceReleaseHardware = qemuReleaseHW;

    // D0 state when:
    // - Device is enumerated (plugged in, system reboot)
    // - Devices return from low-power state
    // - PnP manager redistributes HW resources
    pnpPowerCallbacks.EvtDeviceD0Entry = qemuD0Entry;
    pnpPowerCallbacks.EvtDeviceD0Exit = qemuD0Exit;

    WdfDeviceInitSetPnpPowerEventCallbacks(DeviceInit, &pnpCallbacks);
    // PnP stuff set
    // Clean slate
    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&attributes, DEVICE_EXTENSION);

    // Took this from mic's example - TODO I don't understand this
    // By opting for SynchronizationScopeDevice, we tell the framework to
    // synchronize callbacks events of all the objects directly associated
    // with the device. In this driver, we will associate queues and
    // and DpcForIsr. By doing that we don't have to worrry about synchronizing
    // access to device-context by Io Events and DpcForIsr because they would
    // not concurrently ever. Framework will serialize them by using an
    // internal device-lock.
    //
    attributes.SynchronizationScope = WdfSynchronizationScopeDevice;

    attributes.EvtCleanupCallback = qemuCleanup;

    status = WdfDeviceCreate(&DeviceInit,
        &attributes,
        &device
    );

    PDEVICE_EXTENSION devExtension = qemuGetDeviceContext(device);
    devExtensions->device = device;

    status = WdfDeviceCreateDeviceInterface(
        device,
        /**/, // GUID? 
        NULL
    );


    return status;
}