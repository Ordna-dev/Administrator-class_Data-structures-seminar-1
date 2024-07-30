#ifndef CANCION_H
#define CANCION_H
#include <iostream>

using namespace std;

class Cancion
{
    public:
        Cancion();
        string getNombre() const;
        void setNombre(const string &valor);

        string getArtista() const;
        void setArtista(const string &valor);

        int getFecha() const;
        void setFecha(const int &valor);

        int getLongitud() const;
        void setLongitud(const int &valor);

    protected:

    private:
        string nombre;
        string artista;
        int year;
        int longitud;
};

#endif // CANCION_H
