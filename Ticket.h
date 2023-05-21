#ifndef Ticket_h
#define Ticket_h
#include <vector>
#include <string>

using namespace std;

class Ticket{

    private:
        int id;
        
    public:
        Ticket();

        void setId(int);

        int getId();
};

#endif
