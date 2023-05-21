#include "User.h"
#include "Passenger.h"
#include <vector>
#include <fstream>
#include <cstring>
#include "Ticket.h"
using namespace std;

class ReservationSystem{

    private:
        string nameBus;
        User user; 
        ResData resData;
    public:

        ReservationSystem();

        void makeReservation();

        void modifiReservation();

        void cancelReservation();

        void searchReservation();

        void exitReservation();

        void setNameBus(string);

        string getNameBus();

};