// Created with vsantos1.NET 1.2 by vsantos1
#pragma once

// the size isnt correct since i added some stuff to it
class Entity {

  uint32_t entity;
  std::string name_str;
  std::string weapon_type_str;
  std::string weapon_name_str;
  uint32_t inventoryAddress;

  char pad_0000[4];              // 0x0000
  Vector3 headPos;               // 0x0004
  char pad_0010[24];             // 0x0010
  Vector3 position;              // 0x0028
  Vector3 viewAngles;            // 0x0034
  char pad_0040[172];            // 0x0040
  uint32_t health;               // 0x00EC
  int32_t armor;                 // 0x00F0
  char pad_00F4[20];             // 0x00F4
  uint32_t secondaryClipAmmo;    // 0x0108
  char pad_010C[16];             // 0x010C
  uint32_t primaryClipAmmo;      // 0x011C
  char pad_0120[12];             // 0x0120
  uint32_t secondaryCurrentAmmo; // 0x012C
  char pad_0130[16];             // 0x0130
  uint32_t primaryCurrentAmmo;   // 0x0140
  uint32_t grenade;              // 0x0144
  char pad_0148[4];              // 0x0148
  uint32_t knifeDelay;           // 0x014C
  uint32_t secondaryGunWaitTime; // 0x0150
  char pad_0154[16];             // 0x0154
  uint32_t primaryGunWaitTime;   // 0x0164
  char pad_0168[12];             // 0x0168
  uint32_t secondaryShootsfired; // 0x0174
  char pad_0178[16];             // 0x0178
  uint32_t primaryShootsFired;   // 0x0188
  char pad_018C[80];             // 0x018C
  int32_t killCount;             // 0x01DC
  char pad_01E0[36];             // 0x01E0
  char player_name[16];                 // 0x0205
  char pad_0208[352];            // 0x0208
  char pad_036C[240];            // 0x036C
  char weapon_type[16];     // 0x0000
  char pad_0004[12]; // 0x0004
  char weapon_name[16];     // 0x0017
  char pad_0014[48]; // 0x0014

public:
  uint32_t getEntity() { return entity; }

  int getHealth() { return health; }

  int getArmor() { return armor; }

  std::string getName() { return name_str; }

  Vector3 getPosition() { return position; }

  Vector3 getHeadPos() { return headPos; }

  Vector3 getViewAngles() { return viewAngles; }

  std::string getWeaponType() { return weapon_type_str; }

  std::string getWeaponName() { return weapon_name_str; }


  bool isAlive() { return this->getHealth() > 0 && this->getHealth() <= 100; }

  Entity *player(uint32_t address);

}; // Size: 0x045C

inline Entity m_entity{};
