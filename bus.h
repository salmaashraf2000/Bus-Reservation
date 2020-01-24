#ifndef BUS_H
#define BUS_H
#include <string>
#include "bus.h"
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

 class bus
{
    friend std::ostream &operator<<(std::ostream &os,const bus &obj);
    friend std::istream &operator>>(std::istream &is,bus &obj);

    private:
        int bus_no;
        std::string arrival_time;
        std::string departure;
        std::string driver_name;
        std::string from;
        std::string to;
        mutable std::vector<std::string> vec;


    public:

       bus();
       bus(int busno,std::string arrival,std::string depart,std::string driver,std::string fro,std::string t,std::vector<std::string> vec);

        bool operator<(const bus &rhs)const
        {
        return this->bus_no<rhs.bus_no;
        }

        bool operator==(const bus &rhs)const
        {
        return this->bus_no==rhs.bus_no;
        }

        bool show(std::set<bus> &b1,int &no);
        void display(std::set<bus> &b1,int &no);
        bool seat(std::set<bus> &b1,int &bno,int &seatno);
        void display_buses(std::set<bus> &bb);


};

#endif // BUS_H
