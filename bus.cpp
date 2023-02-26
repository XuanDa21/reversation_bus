#include "bus.h"
void bus::setInit(){
    setSeat_num(10);
    setUnavail_seat_num(10);
    for ( int i = 0; i < seat_num; ++i){
       // seat Seat = seat(i);
        test.push_back(i);
    }
}