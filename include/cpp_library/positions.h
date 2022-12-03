#pragma once
#include "position.h"

namespace cpp_library{

    class Positions {
    public:

    Positions();
    void add_position(Position & pos);
    std::string toString();
    std::vector<Position*> getDatas();
    
    std::vector<Position*> datas;
    };

}