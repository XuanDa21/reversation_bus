#include "ResData.h"

ResData::ResData() {

}

vector<Seat>  ResData::readFileSeat(string nameFile) {
    int index, id;
    bool take;
    ifstream myfile(nameFile);
    Ticket ticket;
    vector<Seat> seats;
    Bus bus;
    for(int i = 0; i < bus.getSeatNum(); ++i) {
        Seat seat = Seat(i);
        seats.push_back(seat);
        if(myfile >> index >> take >> id) {
            seats[i].setIndex(index);
            seats[i].setTake(take);
            ticket.setId(id);
            seats[i].setTicket(ticket);
        }
    }
    return seats;
}


int ResData::getSizeDataPassenger(string nameFile){
    ifstream myfile(nameFile);
    int count = 0;
    string aLineStr;
    while(getline(myfile, aLineStr)) { 
        count++;
    }
    return count;
}

vector<Passenger> ResData::readFilePassenger(string nameFile, int size) {
    string name, departure, destination, date, time;
    int ticketNum, id;
    ifstream myfile(nameFile);
    Ticket ticket;
    vector<Passenger> Passengers;
    for(int i = 0; i < size; ++i) {
        Passenger passenger = Passenger(i);
        Passengers.push_back(passenger);
        if (myfile >> name >> departure >> destination >> date >> time >> ticketNum >> id) {
            Passengers[i].setNameOfPassenger(name);
            Passengers[i].setDepartureCity(departure);
            Passengers[i].setDestinationCity(destination);
            Passengers[i].setDate(date);
            Passengers[i].setTime(time);
            Passengers[i].setTicketNum(ticketNum);
            ticket.setId(id);
            Passengers[i].setTicket(ticket);
        }
    }
    return Passengers;
}

void ResData::writeFilePassenger(string nameFile, vector<Passenger> tickets, ios_base::openmode mode) {
    string name, departure, destination, date, time;
    int ticketNum;
    fstream revervationData; 
    revervationData.open(nameFile, mode);
    if (!revervationData) {}
    else { 
        for (int i = 0; i < tickets.size(); ++i) {
            revervationData << tickets[i].getNameOfPassenger();
            revervationData << " " << tickets[i].getDepartureCity();       
            revervationData << " " << tickets[i].getDestinationCity();
            revervationData << " " << tickets[i].getDate();
            revervationData << " " << tickets[i].getTime();
            revervationData << " " << tickets[i].getTicketNum();
            revervationData << " " << tickets[i].getTicket().getId() << endl;
        }
        revervationData.close();                   
    }

}

void ResData::writeFileSeat(string nameFile, vector<Seat> seats, ios_base::openmode mode) {
    fstream seatData; 
    seatData.open(nameFile, mode);
    Bus bus;
    if (!seatData) {}
    else {  
        for (int i = 0; i < bus.getSeatNum(); ++i) {
            seatData << seats.at(i).getIndex() << " " << seats.at(i).getTake() << " " << seats.at(i).getTicket().getId() << endl;
        }
        seatData.close();                   
    }
}