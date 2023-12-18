#include "../pch.hpp"

Memory::Memory(const std::string_view &processName) {
  // resolve at runtime
  this->NtReadVirtualMemory = reinterpret_cast<pNtReadVirtualMemory>(GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtReadVirtualMemory"));
  this->NtWriteVirtualMemory = reinterpret_cast<pNtWriteVirtualMemory>(GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtWriteVirtualMemory"));

  this->pid = this->getProcessId().has_value() ? this->getProcessId().value() : 0;

  if (this->pid == 0) {
    LOG("The game is not running, please start the game first.");
    return;
  }

  this->handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, this->pid);

  if (!this->handle) {
    LOG("Failed to open process handle.");
    return;
  }

  LOG("Opened a handle %p to process %d.", this->handle, this->pid);
}

uintptr_t Memory::traceAddress(const uintptr_t address, const std::vector<uintptr_t> &offsets) const {
  uintptr_t result = address;

  for (const auto &offset : offsets) {
    result = this->read<uintptr_t>(result + offset);
  }

  return result;
}

std::optional<uintptr_t> Memory::getModuleBase(const std::string_view &moduleName) const {
  MODULEENTRY32 entry;
  entry.dwSize = sizeof(MODULEENTRY32);

  HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, this->pid);

  if (snapshot == INVALID_HANDLE_VALUE)
    return {};

  for (Module32First(snapshot, &entry); Module32Next(snapshot, &entry);) {

    if (moduleName.compare(entry.szModule) == 0) {
      LOG("Found module %s at %p.", moduleName.data(), entry.modBaseAddr);

      CloseHandle(snapshot);
      return reinterpret_cast<uintptr_t>(entry.modBaseAddr);
    }
  }

  CloseHandle(snapshot);
  return {};
}

std::optional<int> Memory::getProcessId() const {
  PROCESSENTRY32 entry;
  entry.dwSize = sizeof(PROCESSENTRY32);

  HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

  if (snapshot == INVALID_HANDLE_VALUE)
    return {};

  for (Process32First(snapshot, &entry); Process32Next(snapshot, &entry);) {
    if (std::string(entry.szExeFile).compare(GAME_NAME) == 0) {
      CloseHandle(snapshot);
      return entry.th32ProcessID;
    }
  }

  CloseHandle(snapshot);
  return {};
}

Memory::~Memory() {
  if (this->handle) {
    CloseHandle(this->handle);
  }
}