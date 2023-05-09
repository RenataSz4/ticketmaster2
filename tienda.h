/*  nombre: Tienda
    contribuidores: David Emmanuel Santana Romero
    fecha: 9 de mayo de 2023
*/

#ifndef TIENDA_TICKETMASTER_H
#define TIENDA_TICKETMASTER_H

#include <string>
#include <vector>
#include "ticket.h"
#include "cliente.h"
using namespace std;

class Tienda : public Holder {
    public:
        Tienda ();
        ~Tienda ();
        
        void display (Cliente &);
};

#include "tienda.cpp"
#endif