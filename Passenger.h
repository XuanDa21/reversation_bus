#ifndef Passenger_h
#define Passenger_h
#include <string>
#include <vector>
#include "Ticket.h"
using namespace std;

class Passenger {

    private:
        string nameOfPassenger, departureCity, destinationCity, date, time;
        int ticketNum;
        vector<int> positionSeat;
        Ticket ticket;
    public:
        Passenger();

        Passenger(int);

        string getNameOfPassenger();

        Ticket getTicket();

        void setTicket(Ticket);

        string getDepartureCity(); 

        string getDestinationCity();

        string getDate();

        string getTime();

        vector<int> getPositionSeat();

        int getTicketNum();

        void setNameOfPassenger(string);

        void setDepartureCity(string); 

        void setDestinationCity(string);

        void setDate(string);

        void setTime(string);

        void setTicketNum(int);

        void setPositionSeat(vector<int>);
        
};

#endif