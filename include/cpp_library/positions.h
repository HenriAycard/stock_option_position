#pragma once
#include "position.h"

class Positions {
 public:

  Positions();
  void add_position(Position & pos);
  std::string toString();
  
  std::vector<const Position*> datas;
};