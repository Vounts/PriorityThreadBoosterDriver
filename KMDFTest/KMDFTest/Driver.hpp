#pragma once
#include <ntifs.h>

#define PRIORITY_BOOSTER_DEVICE 0x8000
#define	IOCTL_SET_BOOSTER_PRIORITY CTL_CODE(PRIORITY_BOOSTER_DEVICE, 0x800, METHOD_NEITHER, FILE_ANY_ACCESS)

UNICODE_STRING deviceName = RTL_CONSTANT_STRING(L"\\Device\\PriorityBooster");
PDEVICE_OBJECT deviceObject;
UNICODE_STRING symLink = RTL_CONSTANT_STRING(L"\\??\\PriorityBooster");

extern "C"
NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath);
void DriverUnloadRoutine(PDRIVER_OBJECT pDriverObject);
NTSTATUS DriverCreateClose(PDEVICE_OBJECT pDeviceObject, PIRP Irp);
NTSTATUS DriverDeviceIoControl(PDEVICE_OBJECT pDeviceObject, PIRP Irp);

struct ThreadData
{
	ULONG ThreadId;
	int Priority;
};