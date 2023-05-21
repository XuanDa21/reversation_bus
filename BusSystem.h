#ifndef BusSystem_h
#define BusSystem_h
#include <vector>
#include "User.h"
using namespace std;

class BusSystem{

    private:
        int busNum;

    public:
        BusSystem();

        int getBusNum();

        void getBusNum(int);

        void setBus();
};

#endif