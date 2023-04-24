/*  nombre: Ticket
    contribuidores: David Emmanuel Santana Romero
    fecha: 23 de abril de 2023
*/

#ifndef TICKET_TICKETMASTER_H
#define TICKET_TICKETMASTER_H

#include <string>
#include <array>
using namespace std;

class Ticket {
    private:
        static int objectCount;
        int ID;
        bool VIP;
        string artist;
        array <string, 4> at; // country, state, city, event place
        array <int, 4> time; // year, month, day, hour (24h)
        string catchphrase;
    public:
        Ticket (string, array <string, 4>, array <int, 4>, bool, string);
        //      <artist>, <at>, <time>, [VIP = assumed false], [catchphrase = assumed empty]
        ~Ticket ();

        void setID (int);
        void setVIP (bool);
        void setArtist (string);
        void setAtCountry (string);
        void setAtState (string);
        void setAtCity (string);
        void setAtEventPlace (string);
        void setYear (int);
        void setMonth (int);
        void setDay (int);
        void setHour (int);
        void setCatchphrase (string);

        int getID () const;
        bool getVIP () const;
        string getArtist () const;
        string getAtCountry () const;
        string getAtState () const;
        string getAtCity () const;
        string getAtEventPlace () const;
        int getYear () const;
        int getMonth () const;
        int getDay () const;
        int getHour () const;
        string getDate () const;
        string getCatchphrase () const;

        void use ();

};

#include "ticket.cpp"
#endif