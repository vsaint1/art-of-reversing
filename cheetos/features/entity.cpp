#include "../../pch.hpp"

Entity *Entity::player(uint32_t address) {

  if (!address)
    return nullptr;

  this->entity = address;

  this->headPos = m_memory.read<Vector3>(address + offsets::head_pos);
  this->position = m_memory.read<Vector3>(address + offsets::position);
  this->viewAngles = m_memory.read<Vector3>(address + offsets::view_angles);
  this->health = m_memory.read<uint32_t>(address + offsets::health);
  this->armor = m_memory.read<uint32_t>(address + offsets::armor);
  this->secondaryClipAmmo = m_memory.read<uint32_t>(address + offsets::secondary_clip_ammo);
  this->primaryClipAmmo = m_memory.read<uint32_t>(address + offsets::primary_clip_ammo);
  this->secondaryCurrentAmmo = m_memory.read<uint32_t>(address + offsets::secondary_current_ammo);
  this->primaryCurrentAmmo = m_memory.read<uint32_t>(address + offsets::primary_current_ammo);
  this->grenade = m_memory.read<uint32_t>(address + offsets::grenade);
  this->knifeDelay = m_memory.read<uint32_t>(address + offsets::knife_delay);
  this->secondaryGunWaitTime = m_memory.read<uint32_t>(address + offsets::secondary_gun_wait_time);
  this->primaryGunWaitTime = m_memory.read<uint32_t>(address + offsets::primary_gun_wait_time);
  this->secondaryShootsfired = m_memory.read<uint32_t>(address + offsets::secondary_shoots_fired);
  this->primaryShootsFired = m_memory.read<uint32_t>(address + offsets::primary_shoots_fired);
  this->killCount = m_memory.read<uint32_t>(address + offsets::kill_count);
  std::string temp_name = m_memory.read<std::string>(address + offsets::name);

  uint32_t inventory = m_memory.read<uint32_t>(address + offsets::inventory);
  if (inventory) {
    uint32_t weapon = m_memory.read<uint32_t>(inventory + 0xC);
    if (weapon) {

      std::string temp_weapon_type_str = m_memory.read<std::string>(weapon + 0x0);
      if (temp_weapon_type_str.empty())
        this->weapon_type_str = "Unknown_type";
      else
        this->weapon_type_str = temp_weapon_type_str;

      std::string temp_weapon_name_str = m_memory.read<std::string>(weapon + 0x17);
      if (temp_weapon_name_str.empty())
        this->weapon_name_str = "Unknown_name";
      else
        this->weapon_name_str = temp_weapon_name_str;
    }
  }

  if (temp_name.empty())
    this->name_str = "Unknown_player";
  else
    this->name_str = temp_name;

  return this;
}