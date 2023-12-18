#include "pch.hpp"

int main() {
  LOG("PID: %d", m_memory.getPid());

  const auto module_base = m_memory.getModuleBase(GAME_NAME);
  uint32_t local_player = m_memory.read<uint32_t>(module_base.value() + 0x017E254);

  uint32_t entity_list = m_memory.read<uint32_t>(module_base.value() + 0x18AC04);
  int player_count = m_memory.read<int>(module_base.value() + 0x18AC0C);
  LOG("Entity list %p, player count %d", entity_list, player_count);

  while (!GetAsyncKeyState(VK_END)) {
    Entity *entity_local = m_entity.player(local_player);
    if (!entity_local->isAlive())
      continue;

    for (int i = 0; i < player_count; i++) {
      uint32_t entity = m_memory.read<uint32_t>(entity_list + (i * 0x4));
      if (!entity)
        continue;

      Entity *player = m_entity.player(entity);
      if (!player)
        continue;

      if (player->isAlive()) {
        LOG("Entity %p, Health %d , Armor %d, HeadPos %f %f %f, Position %f %f %f, ViewAngle %f %f %f, Name %s", player->getEntity(), player->getHealth(), player->getArmor(), player->getHeadPos().x,
            player->getHeadPos().y, player->getHeadPos().z, player->getPosition().x, player->getPosition().y, player->getPosition().z, player->getViewAngles().x, player->getViewAngles().y,
            player->getViewAngles().z, player->getName().c_str());
      }
    }

    Sleep(1000);
  }

  return 0;
}