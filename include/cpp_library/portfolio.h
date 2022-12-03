#pragma once
#include <chrono>
#include "positions.h"

namespace cpp_library{

    class Portfolio {
    public:

        Portfolio(std::chrono::system_clock::time_point date);

        void set_position(Positions & pos);
        Portfolio setActivePortfolio();
        std::string toString();
        std::string getDateToString();
        std::chrono::system_clock::time_point getDate();
        std::vector<Position*> getPositionsData();
        Portfolio getBeforeDate(std::chrono::system_clock::time_point datePortfolio);
        Portfolio getAfterDate(std::chrono::system_clock::time_point datePortfolio);



        Positions datas_positions;
        const std::chrono::system_clock::time_point date;
    };
}
