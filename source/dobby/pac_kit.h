#pragma once

#include <stdint.h>

#include "platform_features.h"

#ifndef PAC_KIT
#define PAC_KIT
#if __has_ptrauth_calls
#include <ptrauth.h>
#endif

static inline void *pac_strip(void *addr) {
  if (addr == NULL) {
    return NULL;
  }
#if __has_ptrauth_calls
  addr = ptrauth_strip(addr, ptrauth_key_asia);
#endif
  return addr;
}

static inline void *pac_sign(void *addr) {
  if (addr == NULL) {
    return NULL;
  }
#if __has_ptrauth_calls
  addr = ptrauth_sign_unauthenticated((void *)addr, ptrauth_key_asia, 0);
#endif
  return addr;
}

static inline void *pac_strip_and_sign(void *addr) {
  return pac_sign(pac_strip(addr));
}

#endif