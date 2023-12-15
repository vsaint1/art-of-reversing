#pragma once

typedef NTSTATUS(NTAPI *pNtReadVirtualMemory)(HANDLE, PVOID, PVOID, ULONG, PULONG);
typedef NTSTATUS(NTAPI *pNtWriteVirtualMemory)(HANDLE, PVOID, PVOID, ULONG, PULONG);

class Memory {
private:
  void *handle;
  int pid;

  pNtReadVirtualMemory NtReadVirtualMemory;
  pNtWriteVirtualMemory NtWriteVirtualMemory;

public:
  explicit Memory(const std::string_view &processName);
  Memory(const Memory &) = delete;
  ~Memory();

  int getPid() const { return pid; }

  std::optional<int> getProcessId() const;
  std::optional<uintptr_t> getModuleBase(const std::string_view &moduleName) const;

  template <typename T> T read(const uintptr_t address) const {
    T buffer{};
    this->NtReadVirtualMemory(this->handle, reinterpret_cast<void *>(address), &buffer, sizeof(T), nullptr);
    return buffer;
  }

  template <typename T> T read(const uintptr_t address, const T &out) const {
    T buffer{};
    if (this->NtReadVirtualMemory(this->handle, reinterpret_cast<void *>(address), &buffer, sizeof(T), nullptr) == 0)
      return buffer;
    return out;
  }
  template <> std::string read<std::string>(const uintptr_t address) const {
    size_t size = 64;
    std::vector<char> buffer(size);
    this->NtReadVirtualMemory(this->handle, reinterpret_cast<void *>(address), buffer.data(), size, nullptr);
    return std::string(buffer.data());
  }

  template <typename T> bool write(const uintptr_t address, const T &buffer) const { 
    return this->NtWriteVirtualMemory(this->handle, reinterpret_cast<void *>(address), &buffer, sizeof(T), nullptr) == 0;
  }
  
};

inline Memory m_memory(GAME_NAME);