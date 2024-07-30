#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "Cancion.h"

using namespace std;

class Reproductor
{
    public:
        Reproductor();
        void agregarCanciones();
        void mostrarCanciones() const;
        void buscarCanciones() const;
        void eliminarCancion();
        void menu();
        void menu2();
        void agregarPlaylist();
        void mostrarPlaylist() const;
        void eliminarPlaylist();
        void reproducirPlaylist() const;

    protected:

    private:
        vector<Cancion> canciones;
        vector<Cancion> playlist;
        enum{
        OPC_SALIR,
        OPC_AGREGAR,
        OPC_MOSTRAR,
        OPC_BUSCAR,
        OPC_BORRAR,
        OPC_PLAYLIST
        };
        enum{
        OPC_VOLVERALMENU,
        OPC_AGREGARLISTA,
        OPC_MOSTRARLISTA,
        OPC_BORRARPLAYLIST,
        OPC_REPRODUCIRPLAYLIST
        };
};

#endif
