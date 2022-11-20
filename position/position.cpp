#include <string>
#include <list>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>
#include <sstream>

#include "position.h"

namespace py = pybind11;


Position::Position(int id_position, int currency, int lst_ticker, int mouvement, int portefolio, float cost_basis, int date_creation, int date_execution, float quantite, float tax, float unit_cost) : id_position(id_position), currency(currency), lst_ticker(lst_ticker), mouvement(mouvement), portefolio(portefolio), cost_basis(cost_basis), date_creation(date_creation), date_execution(date_execution), quantite(quantite), tax(tax), unit_cost(unit_cost) {}


Positions::Positions(){}

Positions::add_position(Position::Position &pos){
  datas.push_back(&pos);
}
    
  

PYBIND11_MODULE(position, m) {
	py::class_<Position>(m, "Position")
	  .def(py::init<int, int, int, int, int, float, int, int, float, float, float>())
	  .def("__repr__", &Position::toString);
	py::class_<Positions>(m, "Positions")
	  .def(py::init<>())
	  .def("add_position", &Positions::add_position);
}
