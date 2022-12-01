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

#include "cpp_library/portfolio.h"

cpp_library::Portfolio::Portfolio(std::chrono::system_clock::time_point date) : date(date) { }
  
std::string cpp_library::Portfolio::toString(){
  std::ostringstream stream;
  stream << "Date:" << getDate() << "\n";
  stream << "Position:" << "\n";
  stream << datas_positions.toString() << "\n";
  return stream.str();

}

std::string cpp_library::Portfolio::getDate() {
	//std::chrono::time_point<std::chrono::system_clock> timepoint = date;
	const std::time_t time_now_t = std::chrono::system_clock::to_time_t(date);
  return std::ctime(&time_now_t);
}

void cpp_library::Portfolio::set_position(Positions & pos){
  datas_positions = pos;
}