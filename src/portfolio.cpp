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
#include <algorithm> // std::copy_if, std::distance

#include "cpp_library/portfolio.h"

cpp_library::Portfolio::Portfolio(std::chrono::system_clock::time_point date) : date(date) { }

std::string cpp_library::Portfolio::toString(){
  std::ostringstream stream;
  stream << "Date:" << getDateToString() << "\n";
  stream << "Position:" << "\n";
  stream << datas_positions.toString() << "\n";
  return stream.str();
}

std::string cpp_library::Portfolio::getDateToString() {
	//std::chrono::time_point<std::chrono::system_clock> timepoint = date;
	const std::time_t time_now_t = std::chrono::system_clock::to_time_t(date);
  return std::ctime(&time_now_t);
}

void cpp_library::Portfolio::set_position(Positions & pos){
  datas_positions = pos;
}

std::chrono::system_clock::time_point cpp_library::Portfolio::getDate(){
  return this->date;
};

std::vector<cpp_library::Position*> cpp_library::Portfolio::getPositionsData(){
  return this->datas_positions.getDatas();
};

cpp_library::Portfolio cpp_library::Portfolio::getBeforeDate(std::chrono::system_clock::time_point datePortfolio){
  cpp_library::Portfolio ptf = Portfolio(datePortfolio);
  cpp_library::Positions pos = cpp_library::Positions();

  for(auto& p : this->getPositionsData()){
    if (p->date_execution <= this->getDate()){
      pos.add_position(*p);
    }
  }
  ptf.set_position(pos);

  return ptf;
}

cpp_library::Portfolio cpp_library::Portfolio::getAfterDate(std::chrono::system_clock::time_point datePortfolio){
  cpp_library::Portfolio ptf = Portfolio(datePortfolio);
  cpp_library::Positions pos = cpp_library::Positions();

  for(auto& p : this->getPositionsData()){
    if (p->date_execution >= this->getDate()){
      pos.add_position(*p);
    }
  }
  ptf.set_position(pos);

  return ptf;
}

cpp_library::Portfolio cpp_library::Portfolio::setActivePortfolio(){
  cpp_library::Portfolio ptfBefore = this->getBeforeDate(this->getDate());
  cpp_library::Portfolio ptfAfter = this->getAfterDate(this->getDate());

  return ptfBefore;
}
