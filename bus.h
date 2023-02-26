#ifndef bus_h
#define bus_h
// #include <iostream>
#include "seat.h"
#include <vector>
class bus
{
protected:
    int seat_num;
    int unavail_seat_num;
public:
    bus();
    std::vector<seat> seats;
    std::vector<int> test;
    void setInit();
    void setSeat_num(int seat){
        this -> seat_num = seat;
    }
    int getSeat_num(){
        return this -> seat_num;
    }
    void setUnavail_seat_num(int none_seat){
        this -> unavail_seat_num = none_seat;
    }
    int getUnavail_seat_num(){
        return this -> unavail_seat_num;
    }
};

bus::bus()
{
    // setSeat_num(10);
    // setUnavail_seat_num(10);
    // for ( int i = 0; i < seat_num; ++i){
    //    // seat Seat = seat(i);
    //     test.push_back(i);
    // }
}
#endif
