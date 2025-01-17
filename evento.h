#ifndef TICKETMASTER2_EVENTO_H
#define TICKETMASTER2_EVENTO_H

#include <string>

class evento {
private:
    std::string nombre;
    std::string lugar;
    int dia, mes, anio;
    std::string artista;
    std::string direccion;
    int hora, minuto;
public:

    std::string getNombre() const;

    void setNombre(const std::string &nombre);

    std::string getLugar() const;

    void setLugar(const std::string &lugar);

    void setFecha(int dia, int mes, int anio);

    std::string getFecha() const;

    std::string getArtista() const;

    void setArtista(const std::string &artista);

    std::string getDireccion() const;

    void setDireccion(const std::string &direccion);

    void setHorario(int hora, int minuto);

    std::string getHorario() const;

};


#endif //TICKETMASTER2_EVENTO_H
