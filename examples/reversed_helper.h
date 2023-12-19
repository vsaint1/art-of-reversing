// Created with vsantos1.NET 1.2 by vsantos1

// since the size isnt 100% correct, we can use this to pad the struct
// https://en.wikipedia.org/wiki/Data_structure_alignment

#define STR_MERGE_IMPL(a, b) a##b
#define STR_MERGE(a, b) STR_MERGE_IMPL(a, b)
#define MAKE_PAD(size) STR_MERGE(_pad, __COUNTER__)[size]
#define DEFINE_MEMBER_T(type, name, offset) struct { type name; char MAKE_PAD(offset - sizeof(type));}

namespace offsets {
std::ptrdiff_t local_player = 0x18AC00;
std::ptrdiff_t entity_list = 0x0191FCC;
std::ptrdiff_t player_count = 0x18AC0C;
std::ptrdiff_t view_matrix = 0x017DFFC;

}; // namespace offsets

struct Vector3 {
  float x, y, z;
};

class Weapon {
public:
  wchar_t* type[16];     // 0x0000
  char pad_0004[12]; // 0x0004
  wchar_t* name[16];     // 0x0010
  char pad_0014[48]; // 0x0014
};                   // Size: 0x0044

class Inventory {
public:
  char pad_0000[12];    // 0x0000
  class Weapon *weapon; // 0x000C
  char pad_0010[52];    // 0x0010
};                      // Size: 0x0044

class Entity {
public:
  char pad_0000[4];             // 0x0000
  Vector3 headPos;              // 0x0004
  char pad_0010[24];            // 0x0010
  Vector3 position;             // 0x0028
  Vector3 viewAngle;            // 0x0034
  char pad_0040[172];           // 0x0040
  uint32_t health;              // 0x00EC
  int32_t armor;                // 0x00F0
  char pad_00F4[20];            // 0x00F4
  int32_t secondaryClipAmmo;    // 0x0108
  char pad_010C[16];            // 0x010C
  int32_t primaryClipAmmo;      // 0x011C
  char pad_0120[12];            // 0x0120
  int32_t secondaryCurrentAmmo; // 0x012C
  char pad_0130[16];            // 0x0130
  int32_t primaryCurrentAmmo;   // 0x0140
  int32_t grenade;              // 0x0144
  char pad_0148[4];             // 0x0148
  int32_t knifeDelay;           // 0x014C
  char pad_0150[140];           // 0x0150
  int32_t killCount;            // 0x01DC
  char pad_01E0[36];            // 0x01E0
  wchar_t* player_name[16];                // 0x0205
  char pad_0208[352];           // 0x0208
  class Inventory *Inventory;   // 0x0368
  char pad_036C[240];           // 0x036C
};                              // Size: 0x045C
