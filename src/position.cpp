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

Position::Position(int id_position, int currency, int lst_ticker, int mouvement, int portefolio, float cost_basis, int date_creation, int date_execution, float quantite, float tax, float unit_cost)
  : id_position(id_position)
  , currency(currency)
  , lst_ticker(lst_ticker)
  , mouvement(mouvement)
  , portefolio(portefolio)
  , cost_basis(cost_basis)
  , date_creation(date_creation)
  , date_execution(date_execution)
  , quantite(quantite)
  , tax(tax)
  , unit_cost(unit_cost)
{ }


Positions::Positions(){ }

void Positions::add_position(Position & pos){
  datas.push_back(&pos);
}

std::string Positions::toString(){
  std::ostringstream stream;
   for (auto& elem : datas) {
     stream << elem->toString() << "\n";
   }
   stream << '\n';
   return stream.str();
}

Portfolio::Portfolio(std::chrono::system_clock::time_point date) : date(date) { }
  
std::string Portfolio::toString(){
  std::ostringstream stream;
  stream << "Date:" << getDate() << "\n";
  stream << "Position:" << "\n";
  stream << datas_positions.toString() << "\n";
  return stream.str();

}

std::string Portfolio::getDate() {
	//std::chrono::time_point<std::chrono::system_clock> timepoint = date;
	const std::time_t time_now_t = std::chrono::system_clock::to_time_t(date);
  return std::ctime(&time_now_t);
}

void Portfolio::set_position(Positions & pos){
  datas_positions = pos;
}
