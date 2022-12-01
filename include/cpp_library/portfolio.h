#pragma once
#include "positions.h"

namespace cpp_library{

    class Portfolio {
    public:

        Portfolio(std::chrono::system_clock::time_point date);
        void set_position(Positions & pos);
        std::string toString();
        std::string getDate();


        Positions datas_positions;
        const std::chrono::system_clock::time_point date;
    };
}
