#pragma once

class Weapon {
  char type[16];     // 0x0000
  char pad_0004[12]; // 0x0004
  char name[16];     // 0x0017
  char pad_0014[48]; // 0x0014
public:
  std::string getName() { return name; }
  std::string getType() { return type; }

}; // Size: 0x0044
