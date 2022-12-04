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
        Positions getBeforeDate(std::chrono::system_clock::time_point datePortfolio);
        Positions getAfterDate(std::chrono::system_clock::time_point datePortfolio);
        Positions getPositionsByWayAndTicker(int ticker, std::string wayName);
        std::map<int, float> getPositionsByWay(std::string wayName);
        std::string map_to_string();
        Positions positionAdjust(Positions pos, int ticker, float quantity);


        Positions datas_positions;
        const std::chrono::system_clock::time_point date;
    };
}
