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
#include <map> // map dictionnary

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

cpp_library::Positions cpp_library::Portfolio::getBeforeDate(std::chrono::system_clock::time_point datePortfolio){
  cpp_library::Positions pos = cpp_library::Positions();

  for(auto& p : this->getPositionsData()){
    if (p->date_execution <= this->getDate()){
      pos.add_position(*p);
    }
  }

  return pos;
}

cpp_library::Positions cpp_library::Portfolio::getAfterDate(std::chrono::system_clock::time_point datePortfolio){
  cpp_library::Positions pos = cpp_library::Positions();

  for(auto& p : this->getPositionsData()){
    if (p->date_execution >= this->getDate()){
      pos.add_position(*p);
    }
  }

  return pos;
}

cpp_library::Positions cpp_library::Portfolio::getPositionsByWayAndTicker(int ticker, std::string wayName){
  cpp_library::Positions pos = cpp_library::Positions();

  for(auto& p : this->getPositionsData()){
    if ((p->id_ticker == ticker) && (p->way == wayName)){
      pos.add_position(*p);
    }
  }

  return pos;
}

std::map<int, float> cpp_library::Portfolio::getPositionsByWay(std::string wayName){
  std::map<int, float> sales;

  for(auto& p : this->getPositionsData()){
    if (p->way == wayName){
      if (sales.find(p->id_ticker) == sales.end()){
        // not found
        sales[p->id_ticker] = p->quantite;
      } else {
        // found
        sales[p->id_ticker] += p->quantite;
      }
    }
  }
  return sales;
}

cpp_library::Positions cpp_library::Portfolio::positionAdjust(cpp_library::Positions pos, int ticker, float quantity){
  cpp_library::Positions posDf = cpp_library::Positions();
  cpp_library::Positions posBuy = this->getPositionsByWayAndTicker(ticker, "BUY");
  std::sort(posBuy.datas.begin(), posBuy.datas.end(), cpp_library::Position::before);

  for(auto& p : posBuy.getDatas()){
    if (p->quantite <= quantity){
      quantity -= p->quantite;
      p->quantite = 0;
    } else {
      p->quantite -= quantity;
      quantity -= p->quantite;
    }
  }
  
  posBuy.datas.erase(
    std::remove_if(posBuy.datas.begin(), posBuy.datas.end(),
      [] (const cpp_library::Position* p) { return p->quantite == 0; } ),
      posBuy.datas.end());
  return posBuy;
}


cpp_library::Portfolio cpp_library::Portfolio::setActivePortfolio(){
  cpp_library::Portfolio ptf = Portfolio(this->date);
  cpp_library::Positions posBefore = this->getBeforeDate(this->getDate());
  cpp_library::Positions posAfter = this->getAfterDate(this->getDate());
  cpp_library::Positions posDf = cpp_library::Positions();
  std::map<int, float> sales = this->getPositionsByWay("SELL.FIFO");

  for (const auto& [key, value] : sales) {
    posDf = this->positionAdjust(posBefore, key, value);
  }

  ptf.set_position(posDf);

  return ptf;
}

std::string cpp_library::Portfolio::map_to_string() {
  std::map<int, float> m = this->getPositionsByWay("SELL.FIFO");

	std::ostringstream stream;

	for (const auto& [key, value] : m){
    stream << '[' << key << "] = " << value << "; ";
  }

  return stream.str();
}