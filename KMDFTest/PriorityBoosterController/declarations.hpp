#pragma once
#include <Windows.h>
#define PRIORITY_BOOSTER_DEVICE 0x8000
#define	IOCTL_SET_BOOSTER_PRIORITY CTL_CODE(PRIORITY_BOOSTER_DEVICE, 0x800, METHOD_NEITHER, FILE_ANY_ACCESS)

struct ThreadData
{
	ULONG ThreadId;
	int Priority;
};