#define FMTADDR    "0x%06lx"
#define FMTDATA    "0x%08x"
#define NAME       "nv_wr32"
#define CAST       u32
#define WRITE(o,v) nv_wo32(device, (o), (v))
#define MAIN       main
#include "nv_wrfunc.h"
