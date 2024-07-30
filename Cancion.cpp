#include "Cancion.h"
#include <iostream>

using namespace std;

Cancion::Cancion()
{
    nombre = "";
    artista = "";
    longitud = 0;
    year = 0;
}

void Cancion::setNombre(const string &valor)
{
    nombre = valor;
}

string Cancion::getNombre() const
{
    return nombre;
}

void Cancion::setArtista(const string &valor)
{
    artista = valor;
}

string Cancion::getArtista() const
{
    return artista;
}

void Cancion::setFecha(const int &valor)
{
    year = valor;
}

int Cancion::getFecha() const
{
    return year;
}

void Cancion::setLongitud(const int &valor)
{
    longitud = valor;
}

int Cancion::getLongitud() const
{
    return longitud;
}
