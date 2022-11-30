#pragma once
#include "positions.h"

class Portfolio {
  public:

    Portfolio(std::chrono::system_clock::time_point date);
    void set_position(Positions & pos);
    std::string toString();
    std::string getDate();


    Positions datas_positions;
    const std::chrono::system_clock::time_point date;
};
