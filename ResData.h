#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Passenger.h"
#include "Bus.h"
#include "Seat.h"
#include <cstdlib>
#include "Ticket.h"
using namespace std;

class ResData{
    
    private:
    
    public:

        ResData();

        vector<Seat> readFileSeat(string);

        vector<Passenger> readFilePassenger(string, int);

        int getSizeDataPassenger(string);
      
        void writeFilePassenger(string, vector<Passenger>, ios_base::openmode);

        void writeFileSeat(string, vector<Seat>, ios_base::openmode);

};