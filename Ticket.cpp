#include "Ticket.h"

Ticket::Ticket() {
    this -> id = 0;
}

void Ticket::setId(int id) {
    this -> id = id;
}

int Ticket::getId() {
    return this -> id;
}
