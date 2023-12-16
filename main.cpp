#include "pch.hpp"

int main() {
  LOG("PID: %d", m_memory.getPid());

  const auto module_base = m_memory.getModuleBase(GAME_NAME);
  uint32_t local_player = m_memory.read<uint32_t>(module_base.value() + 0x017E360);
  if (local_player) {
    int health = m_memory.read<int>(local_player + 0xEC);
    std::string name = m_memory.read<std::string>(local_player + 0x205);

    LOG("Entity %p, health %d, name %s", local_player, health, name.c_str());
  }

  uint32_t entity_list = m_memory.read<uint32_t>(module_base.value() + 0x18AC04);
  int player_count = m_memory.read<int>(module_base.value() + 0x18AC0C);
  LOG("Entity list %p, player count %d", entity_list, player_count);

  for (uint32_t i = 0; i < 4; i++) {
    uint32_t entity = m_memory.read<uint32_t>(entity_list + ( i * 0x4));
    if (!entity)
      continue;

    int health = m_memory.read<int>(entity + 0xEC);
    std::string name = m_memory.read<std::string>(entity + 0x205);
    LOG("Entity %p, health %d, name %s", entity, health, name.c_str());
  }

  return 0;
}