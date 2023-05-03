//
// Created by Braulio on 5/3/2023.
//

#include <iostream>
#include "evento.h"

std::string evento::getNombre() const {
    return nombre;
}

void evento::setNombre(const std::string &nombre) {
    evento::nombre = nombre;
}

std::string evento::getLugar() const {
    return lugar;
}

void evento::setLugar(const std::string &lugar) {
    evento::lugar = lugar;
}

std::string evento::getFecha() const {
    return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio);
}

void evento::setFecha(int dia, int mes, int anio) {
    if (anio < 2023) {
        std::cerr << "El anio tiene que ser despues de 2023.";
        return;
    }

    if (mes < 1 || mes > 12) {
        std::cerr << "El mes tiene que ser entre 1 y 12";
        return;
    }

    if (dia < 1 || dia > 31) {
        std::cerr << "El dia tiene que ser entre 1 y 31";
        return;
    }

    this -> dia = dia;
    this -> mes = mes;
    this -> anio = anio;
}

std::string evento::getArtista() const {
    return artista;
}

void evento::setArtista(const std::string &artista) {
    evento::artista = artista;
}

std::string evento::getDireccion() const {
    return direccion;
}

void evento::setDireccion(const std::string &direccion) {
    evento::direccion = direccion;
}

void evento::setHorario(int hora, int minuto) {
    if (hora < 0 || hora > 24) {
        std::cerr << "Las horas del horario tienen que estar entre 0 y 24 horas";
        return;
    }
    if (minuto < 0 || minuto > 60) {
        std::cerr << "Los minutos del horario tienen que estar entre 0 y 60 minutos";
        return;
    }
}

std::string evento::getHorario() const {
    return std::to_string(hora) + ":" + std::to_string(minuto);
}
