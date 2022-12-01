#pragma once
#include <string>
#include <list>
#include <vector>
#include <ctime>
#include <chrono>
#include <iomanip> 
#include <time.h>

namespace cpp_library{

  class Position {
  public:
    Position(int id_ticker, std::chrono::system_clock::time_point date_creation, std::chrono::system_clock::time_point date_execution, std::string way, float cost_basis, float quantite, float tax, float unit_cost);

    std::string toString() const;
    std::string getDate(std::chrono::system_clock::time_point date) const;
    
    int id_ticker;
    std::chrono::system_clock::time_point date_creation;
    std::chrono::system_clock::time_point date_execution;
    std::string way;
    float cost_basis;
    float quantite;
    float tax;
    float unit_cost;
  };

}

