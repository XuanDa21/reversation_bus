#include <iostream>
#include "User.h"
#include "ReservationSystem.h"
User::User() {}

void User::setInForPassenger() {
    string name, destination, departure, date, time;
    int ticketNum;
    cout << "Name of passenger: ";
    cin >> name;
    passenger.setNameOfPassenger(name);
    cout << "Departure City:";
    cin >> departure;
    passenger.setDepartureCity(departure);
    cout << "Destination City: ";
    cin >> destination;
    passenger.setDestinationCity(destination);
    cout << "Date of travel: ";
    cin >> date;
    passenger.setDate(date);
    cout << "Time of travel: ";
    cin >> time;
    passenger.setTime(time);
    cout << "Number of tickects: ";
    cin >> ticketNum;
    passenger.setTicketNum(ticketNum);
}

void User::systemBus(){
    ReservationSystem reservationSystem;
    char menuInput;
    string nameBus;
    tryAgain:
    cout << "Enter name of bus: ";
    cin >> nameBus;
    reservationSystem.setNameBus(nameBus);
    while(true){
        cout << "Please select an option from the menu below:" << endl;
        cout << "n -> Make Reservation" << endl;
        cout << "m -> Modify reservation" << endl;
        cout << "c -> Cancel reservation" << endl;
        cout << "s -> Search reservation" << endl;
        cout << "b -> choose another bus" << endl;
        cout << "e -> Exit" << endl;
        char menuInput;
        cout << "-> ";
        cin >> menuInput;
        switch(menuInput){
            case 'n':
                reservationSystem.makeReservation();
                break;
            case 'm': 
                reservationSystem.modifiReservation();
                break;
            case 'c': 
                reservationSystem.cancelReservation();
                break;
            case 's': 
                reservationSystem.searchReservation();
                break;
            case 'b':
                goto tryAgain;
                break;
            case 'e': 
                reservationSystem.exitReservation();
                break;
            default: 
                cout << "You have to choose an option in the menu!!!" << endl;
            }
    }
}

string User::getNameToModify(){
    ResData resData;
    vector<Passenger> ticketData;
    int sizeData = resData.getSizeDataPassenger("reservationData.txt");
    int count = 0;
    ticketData = resData.readFilePassenger("reservationData.txt", sizeData);
    string nameToModify, temNameToModify = ""; 
    cout << "Enter name wanna to modify: ";
    cin >> nameToModify;
    for(int i = 0; i < ticketData.size(); ++i) {
        int x = ticketData[i].getNameOfPassenger().compare(nameToModify);
        if(x != 0) {
            count++;
        }
    }
    if(count == ticketData.size()) {
        cout << "We doesn't have the same name passenger" << endl;
    }
    else {
        temNameToModify.assign(nameToModify);
    }
    return temNameToModify;
}


void User::printInforPassenger(Passenger Passenger) {
    cout<< "Name of passenger: " << Passenger.getNameOfPassenger() << endl;
    cout<< "Departure city: " << Passenger.getDepartureCity() << endl;
    cout<< "Destination city: " << Passenger.getDestinationCity() << endl;
    cout<< "Date: " << Passenger.getDate() << endl;
    cout<< "Time: " << Passenger.getTime() << endl;
    cout<< "Number of Passenger: " << Passenger.getTicketNum() << endl;
    cout<< "Seat of passenger: "; 
    for (int i = 0; i < Passenger.getPositionSeat().size(); ++i){
        cout << Passenger.getPositionSeat().at(i) << ", ";
    }
    cout << endl;
}

string User::getNameToCancel() {
    string name;
    cout << "Enter your name: ";
    cin >> name;
    return  name;
}

vector<int> User::getSeatPassenger(vector<Passenger> tickets) {
    int positionSeat, count = 0;
    vector<int> positionSeats;
    ResData resData;
    Bus bus;
    vector<Seat> seatsRead;
    seatsRead = resData.readFileSeat("seatData.txt");
    for (int i = 0; i < seatsRead.size(); ++i ) {
        if(seatsRead[i].getTake()){
            count++;
        }
    }

    if (tickets.data() -> getTicketNum() > (bus.getSeatNum() - count)) {
        cout << "We doesn't have enough seat now!!!" << endl;
         for (int i = 0; i <= count; ++i) {
            if(seatsRead[i].getTake()) {
                positionSeats.push_back(i);
            }
        }
    }

    else {
        for (int i = 0; i < tickets.data() -> getTicketNum(); ++i) {
            cout << "Seat position want to sit:";
            cin >> positionSeat;
            positionSeats.push_back(positionSeat);
        }
    }
    return positionSeats;
}

vector<string> User::getInforToSearch() {
    vector<string> inforToSearch;
    string name, date;
    char choice;
    int ch = 0;
    cout << "Please select an option from the menu below" << endl;
    cout << "n - search by name" << endl;
    cout << "d - search by date" << endl;
    cout << "-> ";
    cin >> choice;
    switch (choice) {
        case 'n':
            cout << "Enter name wanna search: ";
            cin >> name;
            inforToSearch.push_back(name);
            break;
        case 'd': 
            cout << "Enter date wanna search: ";
            cin >> date;
            inforToSearch.push_back(date);
            break;
        default:
            cout << "Please choose an option in the menu" << endl;
            break;
    }
    return inforToSearch;
}

vector<Passenger> User::getInforPassenger() {
    vector<Passenger> tickets;
    tickets.push_back(passenger);
    return tickets;
}


