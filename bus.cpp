#include "Bus.h"
#include "User.h"
Bus::Bus(){
    setSeatNum(10);
}

int Bus::getSeatNum(){
    return this -> seatNum;
}

void Bus::setSeatNum(int seatNum){
    this -> seatNum = seatNum;
}

void Bus::start() {
    User user;
    user.systemBus();
}

