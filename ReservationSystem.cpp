#include "ReservationSystem.h"
ReservationSystem::ReservationSystem() {
    
}

string ReservationSystem::getNameBus(){
    return this -> nameBus;
}

void ReservationSystem::setNameBus(string nameBus) {
    this -> nameBus = nameBus;
}

void ReservationSystem::makeReservation() {

    vector<Seat> seatData;
    vector<int> positionSeat;
    Ticket ticket;
    vector<Ticket> tickets;
    Passenger passenger;
    srand((unsigned) time(NULL));
    int random = rand();
    vector<Passenger> passengers;
    seatData = resData.readFileSeat("seatData"+getNameBus()+".txt");
    user.setInForPassenger();
    int count = 0;
    for(int i = 0; i < seatData.size(); ++i) {
        if(seatData[i].getTake()) {
            count++;
        }
    }   
    if( (seatData.size() - count) < user.getInforPassenger().data() -> getTicketNum()) {}
    else {
        positionSeat = user.getSeatPassenger(user.getInforPassenger());
        ticket.setId(random);
        passengers = user.getInforPassenger();
        passengers.data() -> setTicket(ticket);
        resData.writeFilePassenger("reservationData"+getNameBus()+".txt", passengers, ios::app);
    }

    for (auto i = positionSeat.begin(); i != positionSeat.end(); ++i) {
        seatData[*i].setTake(true); 
        seatData[*i].setTicket(ticket);
    }
    resData.writeFileSeat("seatData"+getNameBus()+".txt", seatData, ios::out);   
         
}

void ReservationSystem::searchReservation() {

    vector<string> inforToSearch;
    vector<Seat> seatsData;
    vector<Passenger> passengerData;
    vector<int> positionSeats, positionSeatsDate;
    vector<string> namePassenger;
    int x, a, id;
    int sizeResData = resData.getSizeDataPassenger("reservationData"+getNameBus()+".txt");
    seatsData = resData.readFileSeat("seatData"+getNameBus()+".txt");
    passengerData = resData.readFilePassenger("reservationData"+getNameBus()+".txt", sizeResData);
    inforToSearch = user.getInforToSearch();

    for(int i = 0; i < sizeResData; ++i) {
        x = inforToSearch[0].compare(passengerData[i].getNameOfPassenger());
        if(x == 0) {
            id = passengerData[i].getTicket().getId();
            break;
        }
    }

    for (int i = 0; i < sizeResData; ++i) {
        a = inforToSearch[0].compare(passengerData[i].getDate());
        if(a == 0) {
            id = passengerData[i].getTicket().getId();
            break;
        }
    }

    for (int i = 0; i < seatsData.size(); ++i) {
        if(id == (seatsData[i].getTicket().getId())) {
            positionSeats.push_back(seatsData[i].getIndex());
        }
    }

    for(int i = 0; i < sizeResData; ++i) {
        if(id == passengerData[i].getTicket().getId()) {
            passengerData[i].setPositionSeat(positionSeats);
            user.printInforPassenger(passengerData[i]);
        }
    }

}
void ReservationSystem::modifiReservation() {

    string nameToModify;
    Ticket ticket;
    int sizeData = resData.getSizeDataPassenger("reservationData"+getNameBus()+".txt");
    srand((unsigned) time(NULL));
    int random = rand(), id;
    vector<int> positionSeats;
    vector<Passenger> passengerData = resData.readFilePassenger("reservationData"+getNameBus()+".txt", sizeData), passenger;
    vector<Seat> seatData = resData.readFileSeat("seatData"+getNameBus()+".txt");
    nameToModify = user.getNameToModify();
    int x = nameToModify.compare("");
    if(x == 0) {}
    else {
        user.setInForPassenger();
    };
    passenger = user.getInforPassenger();
    positionSeats = user.getSeatPassenger(passenger);

    for(int i = 0; i < passengerData.size(); ++i) {
        int x = nameToModify.compare(passengerData[i].getNameOfPassenger());
        if(x == 0) { 
            id = passengerData[i].getTicket().getId();
            break;
        }
    }

    for(int i = 0; i < passengerData.size(); ++i) {
        if(id == passengerData[i].getTicket().getId()) {
            passengerData[i].setNameOfPassenger(passenger[0].getNameOfPassenger());
            passengerData[i].setDepartureCity(passenger[0].getDepartureCity());
            passengerData[i].setDestinationCity(passenger[0].getDestinationCity());
            passengerData[i].setDate(passenger[0].getDate());
            passengerData[i].setTime(passenger[0].getTime());
            passengerData[i].setTicketNum(passenger[0].getTicketNum());
            ticket.setId(random);
            passengerData[i].setTicket(ticket);
        }
    }

    for(int i = 0; i < seatData.size(); ++i) {
        if(id == seatData[i].getTicket().getId()) {
            seatData[i].setTake(false);
            ticket.setId(0);
            seatData[i].setTicket(ticket);
        }
    }

    for(int i = 0; i < positionSeats.size(); ++i) {
        seatData[positionSeats[i]].setTake(true);
        ticket.setId(random);
        seatData[positionSeats[i]].setTicket(ticket);
    }

    resData.writeFileSeat("seatData"+getNameBus()+".txt", seatData, ios::out);
    resData.writeFilePassenger("reservationData"+getNameBus()+".txt", passengerData, ios::out);
}

void ReservationSystem::cancelReservation() { 

    Passenger passenger;
    vector<Passenger> passengerData;
    string nameToCancel;
    int sizeDataPassenger;
    vector<Seat> seatsData;
    int id;
    Ticket ticket;
    nameToCancel = user.getNameToCancel();
    sizeDataPassenger = resData.getSizeDataPassenger("reservationData"+getNameBus()+".txt");
    passengerData = resData.readFilePassenger("reservationData"+getNameBus()+".txt", sizeDataPassenger);
    seatsData = resData.readFileSeat("seatData"+getNameBus()+".txt");

    for (int i = 0; i < passengerData.size(); ++i) {
        int x = passengerData[i].getNameOfPassenger().compare(nameToCancel);
        if(x == 0) {
            id = passengerData[i].getTicket().getId();
            passengerData.erase(passengerData.begin() + i);
        }
    }
    for (int i = 0; i < seatsData.size(); ++i) {
        if((seatsData[i].getTicket().getId()) == id) {
            seatsData[i].setTake(false);
            ticket.setId(0);
            seatsData[i].setTicket(ticket);
        }
    }
    resData.writeFilePassenger("reservationData"+getNameBus()+".txt", passengerData, ios::out);
    resData.writeFileSeat("seatData"+getNameBus()+".txt", seatsData, ios::out);

}

void ReservationSystem::exitReservation() {
    exit(0);
}
