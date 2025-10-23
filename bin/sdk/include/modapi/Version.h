#pragma once

// clang-format off
#define MODAPI_VERSION_MAJOR         0
#define MODAPI_VERSION_MINOR         2
#define MODAPI_VERSION_PATCH         1
/* #undef MODAPI_VERSION_PRERELEASE */
#define MODAPI_VERSION_COMMIT_SHA    405465a
// clang-format on

#define MODAPI_VERSION_TO_STRING_INNER(ver) #ver
#define MODAPI_VERSION_TO_STRING(ver)       MODAPI_VERSION_TO_STRING_INNER(ver)

#ifdef MODAPI_VERSION_PRERELEASE
#define MODAPI_FILE_VERSION_FLAG VS_FF_DEBUG
#define MODAPI_FILE_VERSION_STRING                                                                                     \
    MODAPI_VERSION_TO_STRING(MODAPI_VERSION_MAJOR)                                                                     \
    "." MODAPI_VERSION_TO_STRING(MODAPI_VERSION_MINOR) "." MODAPI_VERSION_TO_STRING(MODAPI_VERSION_PATCH               \
    ) "-" MODAPI_VERSION_PRERELEASE "+" MODAPI_VERSION_TO_STRING(MODAPI_VERSION_COMMIT_SHA)
#else
#define MODAPI_FILE_VERSION_FLAG 0x00000000L
#define MODAPI_FILE_VERSION_STRING                                                                                     \
    MODAPI_VERSION_TO_STRING(MODAPI_VERSION_MAJOR)                                                                     \
    "." MODAPI_VERSION_TO_STRING(MODAPI_VERSION_MINOR) "." MODAPI_VERSION_TO_STRING(MODAPI_VERSION_PATCH               \
    ) "+" MODAPI_VERSION_TO_STRING(MODAPI_VERSION_COMMIT_SHA)
#endif
