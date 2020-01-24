#include <iostream>
#include <iomanip>
#include <set>
#include <algorithm>
#include "bus.h"
#include <string>
#include <cstring>
#include <vector>

using namespace std;


int main()
{
    set<bus> buses;
    bus BB;

    int no;
    cout<<"1-add bus"<<endl<<"2-reserve a bus"<<endl<<"3-show a bus"<<endl<<"4-buses available"<<endl<<"5-exit"<<endl;
    cout<<"choose a selection"<<endl;
    cin>>no;
    if(isdigit(no)){
       cout<<"digit\n";
    }
    while(1){

    if(no==1){

        bus b1;
        cin>>b1;
        buses.insert(b1);

    }else if(no==2){

      int B_no,seat_no;
      cout<<"enter bus number: " ;
      cin>>B_no;
      //check if this bus exists
      bool check=BB.show(buses,B_no),reserved=false;

      if(check==true){

        cout<<"enter seat number: ";
        cin>>seat_no;
        //check if seat number exists and empty
        reserved=BB.seat(buses,B_no,seat_no);

        if(reserved==true){

          cout<<"seat reserved successfully"<<endl;

        }else{

          cout<<"Sorry this seat is unavailable"<<endl;

       }
      }else{

        cout<<"Sorry this bus currently unavailable"<<endl;

      }


    }else if(no==3){

      int B_no;
      cout<<"enter bus number: " ;
      cin>>B_no;

      //check if this bus exists
      if(!BB.show(buses,B_no)){

            cout<<"Sorry this bus currently unavailable"<<endl;
            cout<<"enter another number: ";
            cin>>B_no;

        while(!BB.show(buses,B_no)){

            cout<<"Sorry this bus currently unavailable"<<endl;
            cout<<"enter another number: ";
            cin>>B_no;

        }

        BB.display(buses,B_no);

      }else{

      BB.display(buses,B_no);

      }
    }else if(no==4){

     //display information of all buses available
     BB.display_buses(buses);

    }else if(no==5){

     cout<<"your are done"<<endl;
     break;

    }else{

    cout<<"please enter valid selection"<<endl;

    }

    cout<<endl<<endl;
    cout<<"1-add bus"<<endl<<"2-reserve a bus"<<endl<<"3-show a bus"<<endl<<"4-buses available"<<endl<<"5-exit"<<endl;
    cout<<"choose a selection"<<endl;
    cin>>no;

    }
    return 0;
}

