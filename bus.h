#ifndef Bus_h
#define Bus_h
#include <vector>
#include "Seat.h"

using namespace std;

class Bus{

    private:
        int seatNum;
    public:
        Bus();

        int getSeatNum();

        void setSeatNum(int);

        void start();

};

#endif