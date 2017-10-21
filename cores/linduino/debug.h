#ifndef ARD_DEBUG_H
#define ARD_DEBUG_H

#include <stdint.h>
#include <assert.h>

#ifdef DEBUG_ESP_CORE
#define DEBUGV(...) printf(__VA_ARGS__)
#endif

#ifndef DEBUGV
#define DEBUGV(...)
#endif

#define panic() assert(0)

#endif//ARD_DEBUG_H
