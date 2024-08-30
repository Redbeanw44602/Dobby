#pragma once

// __has_feature is only supported in clang or gcc >= 14.0. To avoid compilation failure in lower versions
// of gcc, please should not use this extension directly in project.
#if defined(__has_feature)
// ptrauth_calls is only implemented in Apple Clang.
#if __has_feature(ptrauth_calls) // Do not use && directly, it will cause gcc < 14.0 to fail to compile
#define __has_ptrauth_calls (1)
#endif
#endif

#if defined(__APPLE__) && __arm64e__
#if __has_ptrauth_calls
#include <ptrauth.h>
#endif
#endif

#if defined(BUILDING_KERNEL)
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stddef.h>
#include <math.h>
#include <machine/limits.h>
#else
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <assert.h>
#if defined(__linux__) || defined(__APPLE__)
#include <unistd.h>
#include <syslog.h>
#endif
#endif

#if defined(BUILDING_KERNEL)
#include "kernel_mode_header.h"
#endif

#if defined(BUILDING_KERNEL)
#define abs(a) ((a) < 0 ? -(a) : (a))
#define llabs(a) (((long long)a) < 0 ? -((long long)a) : ((long long)a))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#ifdef __cplusplus
#define abs(a) ((a) < 0 ? -(a) : (a))
#endif
#else
#endif

#ifdef __cplusplus
#include "TINYSTL/vector.h"
#include "TINYSTL/unordered_map.h"
#endif