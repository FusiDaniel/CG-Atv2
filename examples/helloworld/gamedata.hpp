#ifndef GAMEDATA_HPP_
#define GAMEDATA_HPP_

#include <bitset>

enum class KeyBoardInput { R_Plus, R_Minus, G_Plus, G_Minus, B_Plus, B_Minus };
enum class MouseInput { Brush };

struct GameData {
  std::bitset<6> keyboard_input;
  std::bitset<1> mouse_input;
};

#endif