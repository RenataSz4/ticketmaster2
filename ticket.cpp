/*  nombre: Ticket
    contribuidores: David Emmanuel Santana Romero
    fecha: 23 de abril de 2023
*/

#include "ticket.h"
#include <iostream>
#include <string>
#include <array>
using namespace std;

int Ticket :: objectCount = 0;

Ticket :: Ticket (string artist, bool VIP = false, float price = 50.00, string catchphrase = "♫", array <int, 4> time = {2023, 6, 9, 12}, array <string, 4> at = {"México", "Baja California", "Tijuana", "Estadio de los Xolos"}) {
    this -> artist = artist;
    this -> VIP = VIP;
    this -> price = price;
    this -> catchphrase = catchphrase;
    this -> time = time;
    this -> at = at;

    setID(++objectCount);
}

Ticket :: Ticket () {
    price = 50;
    artist = "Chayanne";
    VIP = false;
    catchphrase = "Quiero ser torero";
    time = {2023, 6, 9, 12};
    at = {"México", "Baja California", "Tijuana", "Estadio de los Xolos"};
    setID(++objectCount);
}

Ticket :: ~Ticket () {
    artist = "";
    VIP = false;
    catchphrase = "";
    time = {0, 0, 0, 0};
    at = {"", "", "", ""};
}

void Ticket :: setID (int x) {
    ID = x;
}
void Ticket :: setPrice (float x) {
    price = x;
}
void Ticket :: setVIP (bool x) {
    VIP = x;
}
void Ticket :: setArtist (string x) {
    artist = x;
}
void Ticket :: setAtCountry (string x) {
    at[0] = x;
}
void Ticket :: setAtState (string x) {
    at[1] = x;
}
void Ticket :: setAtCity (string x) {
    at[2] = x;
}
void Ticket :: setAtEventPlace (string x) {
    at[3] = x;
}
void Ticket :: setYear (int x) {
    if (x < 1) {
        cout << "ERROR | OUT OF RANGE YEAR" << endl;
        return;
    }
    time[0] = x;
}
void Ticket :: setMonth (int x) {
    if (x < 1 || x > 12) {
        cout << "ERROR | OUT OF RANGE MONTH" << endl;
        return;
    }
    time[1] = x;
}
void Ticket :: setDay (int x) {
    if (    x < 1 // no month has day 0, nor does it have negative days
        ||  x > 31 // no month has over 31 days
            // non leap year february cannot have over 28 days
        ||  (time[1] == 2 && !(time[0]%4 == 0 && (time[0]%100 != 0 || time[0]%400 == 0)) && x > 28)
            // february never does have more than 29 days ... actually, there was a february 30, in sweden 1712
        ||  (time[1] == 2 && x > 29)
            // some months are 30 days long
        ||  (!(time[1] == 1 || time[1] == 3 || time[1] == 5 || time[1] == 7 || time[1] == 8 || time[1] == 10 || time[1] == 12) && x > 30)
    ) {
        cout << "ERROR | OUT OF RANGE DAY" << endl;
        return;
    }
    time[2] = x;
}
void Ticket :: setHour (int x) {
    if (x < 0 || x > 23) {
        cout << "ERROR | OUT OF RANGE HOUR" << endl;
        return;
    }
    time[3] = x;
}
void Ticket :: setCatchphrase (string x) {
    catchphrase = x;
}

int Ticket :: getID () const {
    return ID;
}
float Ticket :: getPrice () const {
    return price;
}
bool Ticket :: getVIP () const {
    return VIP;
}
string Ticket :: getArtist () const {
    return artist;
}
string Ticket :: getAtCountry () const {
    return at[0];
}
string Ticket :: getAtState () const {
    return at[1];
}
string Ticket :: getAtCity () const {
    return at[2];
}
string Ticket :: getAtEventPlace () const {
    return at[3];
}
int Ticket :: getYear () const {
    return time[0];
}
int Ticket :: getMonth () const {
    return time[1];
}
int Ticket :: getDay () const {
    return time[2];
}
int Ticket :: getHour () const {
    return time[3];
}
string Ticket :: getDate () const {
    return (to_string(time[0]) + "-" + to_string(time[1]) + "-" + to_string(time[2]) + " " + to_string(time[3]) + "h");
}
string Ticket :: getCatchphrase () const {
    return catchphrase;
}

void Ticket :: use () {
    cout << catchphrase << endl;
    cout << "BOLETO CON ID " << ID << " UTILIZADO." << endl;
}

void Ticket :: display () {
    cout << "[BOLETO] ID: " << getID () << ", VIP: " << (getVIP () ? "Sí" : "No") << ", Artista: " << getArtist () << endl;
    cout << "\tLugar: " << getAtCountry () << ", " << getAtState () << ", " << getAtCity () << ", " << getAtEventPlace () << endl;
    cout << "\tFecha: " << getDate () << endl;
    cout << endl;
}