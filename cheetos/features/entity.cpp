#include "../../pch.hpp"

Entity *Entity::player(uint32_t address) {

  if (!address)
    return nullptr;

  this->entity = address;

  this->headPos = m_memory.read<Vector3>(address + 0x4);
  this->position = m_memory.read<Vector3>(address + 0x28);
  this->viewAngles = m_memory.read<Vector3>(address + 0x34);
  this->health = m_memory.read<uint32_t>(address + 0xEC);
  this->armor = m_memory.read<uint32_t>(address + 0xF0);
  this->secondaryClipAmmo = m_memory.read<uint32_t>(address + 0x108);
  this->primaryClipAmmo = m_memory.read<uint32_t>(address + 0x11C);
  this->secondaryCurrentAmmo = m_memory.read<uint32_t>(address + 0x12C);
  this->primaryCurrentAmmo = m_memory.read<uint32_t>(address + 0x140);
  this->grenade = m_memory.read<uint32_t>(address + 0x144);
  this->knifeDelay = m_memory.read<uint32_t>(address + 0x14C);
  this->secondaryGunWaitTime = m_memory.read<uint32_t>(address + 0x150);
  this->primaryGunWaitTime = m_memory.read<uint32_t>(address + 0x164);
  this->secondaryShootsfired = m_memory.read<uint32_t>(address + 0x174);
  this->primaryShootsFired = m_memory.read<uint32_t>(address + 0x188);
  this->killCount = m_memory.read<uint32_t>(address + 0x1DC);
  std::string temp_name = m_memory.read<std::string>(address + 0x205);

  if (!temp_name.empty())
    this->name_str = "Unknown";
  else
    this->name_str = temp_name;

  return this;
}