#include <iostream>
#include "bus.h"
int main(){
    bus a;
    int b = a.getUnavail_seat_num();
    std::cout << b <<std::endl;
    return 0;
}