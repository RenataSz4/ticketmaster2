/*  nombre: Cliente
    contribuidores: David Emmanuel Santana Romero
    fecha: 23 de abril de 2023
*/

#ifndef CLIENTE_TICKETMASTER_H
#define CLIENTE_TICKETMASTER_H

#include <string>
#include <vector>
#include "ticket.h"
using namespace std;

class Cliente {
    private:
        static int objectCount;
        int ID;
        string password;
        vector <Ticket> inventario;
    public:
        Cliente (string);
        ~Cliente ();

        void setID (int);
        void setPassword (string);
        void setInventario (vector <Ticket>);
        void addTicket (Ticket);
        void deleteTicket (int);

        int getID () const;
        string getPassword () const;
        Ticket getTicket (int);

        void useTicket (int);
};

#include "cliente.cpp"
#endif