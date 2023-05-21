#ifndef Seat_h
#define Seat_h
#include <vector>
#include <string>
#include "Ticket.h"

using namespace std;

class Seat{

    private:
        int index;
        bool take;
        Ticket ticket;
    public:
        Seat();

        Seat(int);

        int getIndex();

        Ticket getTicket();

        void setTicket(Ticket);

        bool getTake();

        void setIndex(int);

        void setTake(bool);
};

#endif
