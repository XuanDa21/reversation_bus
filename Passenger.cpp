#include "Passenger.h"

Passenger::Passenger(){

}

Passenger::Passenger(int index){
    setNameOfPassenger("");
    setDepartureCity("");
    setDestinationCity("");
    setDate("");
    setTime("");
    setTicketNum(0);
}

Ticket Passenger::getTicket() {
    return this -> ticket;
}

void Passenger::setTicket(Ticket ticket) {
    this -> ticket = ticket;
}

string Passenger::getNameOfPassenger(){
    return this -> nameOfPassenger;
}

string Passenger::getDepartureCity(){
    return this -> departureCity;
}

string Passenger::getDestinationCity(){
    return this -> destinationCity;
}

string Passenger::getDate(){
    return this -> date;
}

string Passenger::getTime(){
    return this -> time;
}

int Passenger::getTicketNum(){
    return this -> ticketNum;
}

vector<int> Passenger::getPositionSeat(){
    return this -> positionSeat;
}

void Passenger::setNameOfPassenger(string nameOfPassenger){
    this -> nameOfPassenger = nameOfPassenger;
}

void Passenger::setDepartureCity(string departureCity){
    this -> departureCity = departureCity;
}

void Passenger::setDestinationCity(string destinationCity){
    this -> destinationCity = destinationCity;
}

void Passenger::setDate(string date){
    this -> date = date;
}

void Passenger::setTime(string time){
    this -> time = time;
}

void Passenger::setTicketNum(int ticketNum){
    this -> ticketNum = ticketNum;
}

void Passenger::setPositionSeat(vector<int> positionSeat){
    this -> positionSeat = positionSeat;
}

