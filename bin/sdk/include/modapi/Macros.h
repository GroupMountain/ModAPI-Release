#pragma once
#include <ll/api/base/CompilerPredefine.h>

#ifdef MODAPI_EXPORTS
#define MOD_API [[maybe_unused]] LL_SHARED_EXPORT
#else
#define MOD_API [[maybe_unused]] LL_SHARED_IMPORT
#endif

#define MOD_NDAPI [[nodiscard]] MOD_API

#define MOD_CAPI   extern "C" MOD_API
#define MOD_NDCAPI [[nodiscard]] MOD_CAPI