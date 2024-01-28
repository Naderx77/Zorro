#pragma once

#ifdef ZR_PLATFORM_WINDOWS
  #ifdef ZR_BUILD_DLL
    #define ZORRO_API __declspec(dllexport)
  #else
    #define ZORRO_API __declspec(dllimport)
  #endif
#else
  #error Zorro only supports windows
#endif

#define BIT(X) (1 << X)