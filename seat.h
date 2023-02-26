#ifndef seat_h
#define seat_h
class seat
{
private:
    int index;
    bool taken;
public:
    seat();

    void setIndex(int i){
        this -> index = i; 
    }
    int getIndex(){
        return this -> index;
    }
    void setTaken(bool b){
        this -> taken = b;
    }
    bool getTaken(){
        return this -> taken;
    }
};

seat::seat()
{
    setIndex(0);
    setTaken(false);
}
#endif


