/*  nombre: Cliente
    contribuidores: David Emmanuel Santana Romero
    fecha: 23 de abril de 2023
*/

#include "cliente.h"
#include <string>
#include <vector>
#include "ticket.h"
#include <iostream>
using namespace std;

int Cliente :: objectCount = 0;

Cliente :: Cliente (string pswd) {
    password = pswd;
    setID(++objectCount);
    cout << "ID: " << ID << endl;
}
Cliente :: ~Cliente () {
    inventario = {};
    cout << "Cliente con ID " << ID << " eliminado." << endl;

}
void Cliente :: setID (int x) {
    ID = x;
}
void Cliente :: setPassword (string x) {
    if (x.size() < 8 || x.size() > 30) {
        cout << "ERROR | PASSWORD MUST BE 8 TO 30 CHARACTERS LONG";
        return;
    }
    password = x;
}
void Cliente :: setInventario (vector <Ticket> x) {
    inventario = x;
}
void Cliente :: addTicket (Ticket x) {
    inventario.push_back(x);
}
void Cliente :: deleteTicket (int x) {
    if (x < 1 || x > inventario.size()) {
        cout << "ERROR | OUT OF INVENTORY RANGE (1 TO " << inventario.size() << ")" << endl;
        return;
    }
    inventario.erase(inventario.begin() + --x);
}
int Cliente :: getID () const {
    return ID;
}
string Cliente :: getPassword () const {
    return password;
}
Ticket Cliente :: getTicket (int x) const {
    if (x < 1 || x > inventario.size()) {
        cout << "ERROR | OUT OF INVENTORY RANGE (1 TO " << inventario.size() << ")" << endl;
        Ticket sample;
        return sample;
    }
    return inventario[--x];
}
void Cliente :: useTicket (int x) {
    if (x < 1 || x > inventario.size()) {
        cout << "ERROR | OUT OF INVENTORY RANGE (1 TO " << inventario.size() << ")" << endl;
        return;
    }
    inventario[--x].use();
}