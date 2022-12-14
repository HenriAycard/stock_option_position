#include <string>
#include <list>
#include <vector>
#include <sstream> // ostringstream
#include <ctime> // for std::time_t
#include <chrono> // for system_clock
#include <iomanip> // for put_time
#include <time.h>
#include <cerrno>
#include <iostream>

#include "cpp_library/position.h"

cpp_library::Position::Position(int id_ticker, std::chrono::system_clock::time_point date_creation, std::chrono::system_clock::time_point date_execution, std::string way, float cost_basis, float quantite, float tax, float unit_cost)
  : id_ticker(id_ticker)
  , date_creation(date_creation)
  , date_execution(date_execution)
  , way(way)
  , cost_basis(cost_basis)  
  , quantite(quantite)
  , tax(tax)
  , unit_cost(unit_cost)
{ }

cpp_library::Position::Position(const cpp_library::Position*& pos)
  : id_ticker(pos->id_ticker)
  , date_creation(pos->date_creation)
  , date_execution(pos->date_execution)
  , way(pos->way)
  , cost_basis(pos->cost_basis)  
  , quantite(pos->quantite)
  , tax(pos->tax)
  , unit_cost(pos->unit_cost)
{ }

std::string cpp_library::Position::toString() const {
  return "[" 
    + std::to_string(id_ticker) + ", " 
    + getDate(date_creation) + ", " 
    + getDate(date_execution) + ", " 
    + way + ", " 
    + std::to_string(cost_basis) + ", " 
    + std::to_string(quantite) + ", " 
    + std::to_string(tax) + ", " 
    + std::to_string(unit_cost) + "]";
}

std::string cpp_library::Position::getDate(std::chrono::system_clock::time_point date) const {
	char s[1000];
  const std::time_t time_now_t = std::chrono::system_clock::to_time_t(date);
  struct tm * p = localtime(&time_now_t);
  strftime(s, 1000, "%A, %B %d %Y", p);
  return s;
}