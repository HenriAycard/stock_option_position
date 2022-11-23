#include <string>
#include <list>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/chrono.h>
#include <vector>
#include <sstream> // ostringstream
#include <ctime> // for std::time_t
#include <chrono> // for system_clock
#include <iomanip> // for put_time
#include <time.h>
#include <cerrno>
#include <iostream>

#include "position.h"


namespace py = pybind11;


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

PYBIND11_MODULE(position, m) {
	py::class_<Position>(m, "Position")
	  .def(py::init<int, int, int, int, int, float, int, int, float, float, float>())
	  .def("__repr__", &Position::toString);
	py::class_<Positions>(m, "Positions")
	  .def(py::init<>())
	  .def("add_position", &Positions::add_position)
	  .def("__repr__", &Positions::toString);
  py::class_<Portfolio>(m, "Portfolio")
    .def(py::init<std::chrono::system_clock::time_point>())
    .def("set_position", &Portfolio::set_position)
    .def("__repr__", &Portfolio::toString);
}
