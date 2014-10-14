#include <stdlib.h>

#include <core/os.h>
#include <core/object.h>
#include <core/device.h>

static CAST
nv_rvram(struct nouveau_object *device, u64 addr)
{
	if (nv_device(device)->card_type >= NV_50 &&
	    nv_device(device)->card_type <= NV_E0) {
		CAST data;
		u32 pmem = nv_ro32(device, 0x001700);
		nv_wo32(device, 0x001700, 0x00000000 | (addr >> 16));
		data = RVRAM(device, 0x700000 + (addr & 0xffffULL));
		nv_wo32(device, 0x001700, pmem);
		return data;
	} else {
		printk("unsupported chipset\n");
		exit(1);
	}
}

#define READ(o) nv_rvram(device, (o))
#define ENABLE  (NV_DEVICE_DISABLE_MMIO | NV_DEVICE_DISABLE_IDENTIFY)
#include "nv_rdfunc.h"
