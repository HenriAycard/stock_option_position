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
