#include <string>
#include <list>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>
#include <vector>


namespace py = pybind11;

class Position {
 public:
  Position(int id_position, int currency, int lst_ticker, int mouvement, int portefolio, float cost_basis, int date_creation, int date_execution, float quantite, float tax, float unit_cost);

 std::string toString() const {
   return "[" + std::to_string(id_position) + ", " + std::to_string(currency) + ", " + std::to_string(lst_ticker) + ", " + std::to_string(mouvement) + ", " + std::to_string(portefolio) + ", " + std::to_string(cost_basis) + ", " + std::to_string(date_creation) + ", " + std::to_string(date_execution) + ", " + std::to_string(quantite) + ", " + std::to_string(tax) + ", " + std::to_string(unit_cost) + "]";
 }
  
  int id_position;
  int currency;
  int lst_ticker;
  int mouvement;
  int portefolio;
  float cost_basis;
  int date_creation;
  int date_execution;
  float quantite;
  float tax;
  float unit_cost;
};

class Positions : public Position {
 public:

  Positions();
  void add_position(Position &);
  
  std::vector<Position*> datas;
};
