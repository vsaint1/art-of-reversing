#pragma once

namespace offsets {
inline std::ptrdiff_t local_player = 0x017E254;
inline std::ptrdiff_t entity_list = 0x18AC04;
inline std::ptrdiff_t player_count = 0x18AC0C;
inline std::ptrdiff_t view_matrix = 0x017DFFC;
inline std::ptrdiff_t health = 0x00EC;
inline std::ptrdiff_t armor = 0x00F0;
inline std::ptrdiff_t secondary_clip_ammo = 0x0108;
inline std::ptrdiff_t primary_clip_ammo = 0x011C;
inline std::ptrdiff_t secondary_current_ammo = 0x012C;
inline std::ptrdiff_t primary_current_ammo = 0x0140;
inline std::ptrdiff_t grenade = 0x0144;
inline std::ptrdiff_t knife_delay = 0x014C;
inline std::ptrdiff_t secondary_gun_wait_time = 0x0150;
inline std::ptrdiff_t primary_gun_wait_time = 0x0164;
inline std::ptrdiff_t secondary_shoots_fired = 0x0174;
inline std::ptrdiff_t primary_shoots_fired = 0x0188;
inline std::ptrdiff_t kill_count = 0x01DC;
inline std::ptrdiff_t name = 0x0205;
inline std::ptrdiff_t position = 0x0030;
inline std::ptrdiff_t head_pos = 0x0004;
inline std::ptrdiff_t view_angles = 0x0034;


} // namespace offsets

namespace settings {

namespace aimbot {
inline bool enabled = true;
};

namespace esp {
inline bool enabled = true;
};
}; // namespace settings