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

#include "cpp_library/positions.h"

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