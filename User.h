#ifndef User_h
#define User_h
#include "ResData.h"
#include "Passenger.h"
#include "Seat.h"
#include "Bus.h"
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class User{

    private:
        Passenger passenger;

    public:
            User();

            void setInForPassenger();

            void systemBus();

            void printInforPassenger(Passenger ticket);

            string getNameToCancel();

            string getNameToModify();

            vector<int> getSeatPassenger(vector<Passenger>);

            vector<string> getInforToSearch();

            vector<Passenger> getInforPassenger();

};

#endif