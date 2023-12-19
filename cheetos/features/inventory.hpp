#pragma once

class Inventory {
  char pad_0000[12];         // 0x0000
  class Weapon *weapon;      // 0x000C
  char pad_0010[52];         // 0x0010
  uint32_t inventoryAddress; // 0x00368
public:
  Weapon *getWeapon() { return weapon; }
  Inventory *inventory() { return this; }

}; // Size: 0x0044