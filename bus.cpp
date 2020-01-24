#include "bus.h"
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>


bus::bus()
:bus_no{0},arrival_time{0},departure{0},driver_name{'\0'},from{'\0'},to{'\0'},vec(32,"empty")
{

}

bus::bus(int busno,std::string arrival,std::string depart,std::string driver,std::string fro,std::string t,std::vector<std::string> vec)
:bus_no{busno},arrival_time{arrival},departure{depart},driver_name{driver},from{fro},to{t},vec{vec}
{

}



std::ostream &operator<<(std::ostream &os,const bus &obj){

   os<<std::setw(15)<<std::left<<"Bus number: "<<std::setw(15)<<std::left<<obj.bus_no<<std::setw(15)<<std::left<<"arrival time: "<<std::setw(15)<<std::left<<obj.arrival_time<<"departure: "<<obj.departure<<std::endl<<
   std::setw(15)<<std::left<<"Driver name: "<<std::setw(15)<<std::left<<obj.driver_name<<std::setw(15)<<std::left<<"from: "<<std::setw(15)<<std::left<<obj.from<<"To: "<<obj.to<<std::endl;
   int cnt=0,i=0;

   for(i=0;i<32;i++){

       if(cnt==4){

            std::cout<<std::endl;
            cnt=0;

        }
        os<<i+1<<"-"<<std::setw(10)<<std::left<<obj.vec.at(i)<<"\t\t\t";

    cnt+=1;

   }
 return os;
}

std::istream &operator>>(std::istream &is,bus &obj){

   std::cout<<"Bus number: ";
   is>>obj.bus_no;
   std::cout<<"arrival time: ";
   is>>obj.arrival_time;
   std::cout<<"departure: ";
   is>>obj.departure;
   std::cout<<"Driver name: ";
   is>>obj.driver_name;
   std::cout<<"from: ";
   is>>obj.from;
   std::cout<<"To: ";
   is>>obj.to;

  return is;
}

//check if this bus exists
bool bus::show(std::set<bus> &b1,int &no){

  for(auto c: b1){

    if(c.bus_no==no){
        return true;
    }

  }
 return false;
}

//print information of a bus
void bus::display(std::set<bus> &b1,int &no){

  for(auto c:b1){

    if(c.bus_no==no){

      std::cout<<c;
      break;

    }

  }
 return;
}

//reserve a seat in bus and check if the seat exists and empty
bool bus::seat(std::set<bus> &b1,int &bno,int &seatno){

    std::string name;
    std::cout<<"enter passenger's name: ";
    std::cin>>name;

     for(auto &c: b1){

      if(c.bus_no==bno){

         if(seatno>0 && seatno<33 && c.vec.at(seatno-1)=="empty"){

           c.vec.at(seatno-1)=name;
           return true;

         }
      }

     }
     return false;
 }

 //print information of all available buses
void  bus::display_buses(std::set<bus> &bb){

  for(auto &c:bb){

    std::cout<<c<<std::endl;

  }

 }


