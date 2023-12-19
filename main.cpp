#include "pch.hpp"

int main() {

  if (!m_memory.getPid())
    return 0;

  const auto module_base = m_memory.getModuleBase(GAME_NAME);

  while (!GetAsyncKeyState(VK_END)) {

    uint32_t local_player = m_memory.read<uint32_t>(module_base.value() + offsets::local_player);

    if (!local_player)
      continue;

    uint32_t entity_list = m_memory.read<uint32_t>(module_base.value() + offsets::entity_list);
    if (!entity_list)
      continue;

    int player_count = m_memory.read<int>(module_base.value() + offsets::player_count);
    if (!player_count)
      continue;

    Entity *entity_local = m_entity.player(local_player);

    if (!entity_local->isAlive())
      continue;
    LOG("ViewAngle %f %f %f", entity_local->getViewAngles().x, entity_local->getViewAngles().y, entity_local->getViewAngles().z);
    ViewMatrix_t local_view_matrix = m_memory.read<ViewMatrix_t>(module_base.value() + offsets::view_matrix);
    LOG("ViewMatrix %f %f %f %f", local_view_matrix.matrix[0][0], local_view_matrix.matrix[0][1], local_view_matrix.matrix[0][2], local_view_matrix.matrix[0][3]);

    for (int i = 0; i < player_count; i++) {
      uint32_t entity = m_memory.read<uint32_t>(entity_list + (i * 0x4));
      if (!entity)
        continue;

      Entity *player = m_entity.player(entity);
      if (!player)
        continue;

      if (player->isAlive()) {
        LOG("Entity %p, Health %d , Armor %d, HeadPos %f %f %f, Position %f %f %f, ViewAngle %f %f %f, Name %s, WeaponType %s, WeaponName %s", player->getEntity(), player->getHealth(),
            player->getArmor(), player->getHeadPos().x, player->getHeadPos().y, player->getHeadPos().z, player->getPosition().x, player->getPosition().y, player->getPosition().z,
            player->getViewAngles().x, player->getViewAngles().y, player->getViewAngles().z, player->getName().c_str(), player->getWeaponType().c_str(), player->getWeaponName().c_str());
      }
    }

    Sleep(1000);
  }

  return 0;
}