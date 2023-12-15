#ifndef PCH_HPP
#define PCH_HPP


#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <string>
#include <optional>
#include <vector>

#define GAME_NAME "ac_client.exe"

#ifdef _DEBUG
#define LOG(fmt, ...)\
{\
  const auto filename = strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__;\
  printf("[%s:%d] - " fmt "\n", filename, __LINE__, __VA_ARGS__);\
}
#else
#define LOG(fmt, ...)\
{\
  printf("[aor] - " fmt "\n", __VA_ARGS__);\
}
#endif

#include "memory/memory.hpp"


#endif // PCH_HPP