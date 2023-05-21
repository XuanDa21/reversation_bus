#include "BusSystem.h"


BusSystem::BusSystem(){
    getBusNum(2);
}

int BusSystem::getBusNum(){
    return this -> busNum;
}

void BusSystem::getBusNum(int busNum){
    this -> busNum = busNum;
}

void BusSystem::setBus(){
    User user;
    user.selectBus();
}
