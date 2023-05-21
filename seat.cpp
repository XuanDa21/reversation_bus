#include "Seat.h"
Seat::Seat(){
    
}

Seat::Seat(int index){
    setIndex(index);
    setTake(false);
}

void Seat::setTake(bool take){
    this -> take = take;
}

int Seat::getIndex(){
    return this -> index;
}


bool Seat::getTake(){
    return this -> take;
}

void Seat::setIndex(int index){
    this -> index = index;
}

Ticket Seat::getTicket() {
    return this -> ticket;
}

void Seat::setTicket(Ticket ticket) {
    this -> ticket = ticket;
}