#include <string>
#include <list>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>
#include <pybind11/chrono.h>
#include <vector>
#include <ctime>
#include <chrono>
#include <iomanip> 
#include <time.h>


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

class Positions {
 public:

  Positions();
  void add_position(Position & pos);
  std::string toString();
  
  std::vector<const Position*> datas;
};

class Portfolio {
  public:

    Portfolio(std::chrono::system_clock::time_point date);
    void set_position(Positions & pos);
    std::string toString();
    std::string getDate();


    Positions datas_positions;
    const std::chrono::system_clock::time_point date;
};
