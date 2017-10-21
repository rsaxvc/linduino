#ifndef INTERRUPT_SHIM_H
#define INTERRUPT_SHIM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <signal.h>

static unsigned xt_rsil(unsigned level )
{
}

static void xt_wsr_ps(unsigned state)
{
}

#ifdef __cplusplus
}
#endif

#endif INTERRUPT_SHIM_H
