#include "Reproductor.h"
#include "Cancion.h"
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

Reproductor::Reproductor()
{

}

void Reproductor::agregarCanciones()
{
    Cancion s;
    string nombre;
    string artista;
    int year;
    int longitud;

    cout<<"Nombre: ";
    getline(cin, nombre);
    cout<<"Artista: ";
    getline(cin, artista);
    cout<<"Year: ";
    cin>> year;
    cout<<"Duracion (segundos): ";
    cin>> longitud;

    s.setNombre(nombre);
    s.setArtista(artista);
    s.setFecha(year);
    s.setLongitud(longitud);

    canciones.push_back(s);
    cout<<"\nCancion agregada con exito"<<endl<<endl;
}

void Reproductor::mostrarCanciones() const
{
    for (size_t i(0);i < canciones.size();++i)
    {
        cout<<canciones.at(i).getNombre()<<" - "<<canciones.at(i).getArtista()<<"("
             <<canciones.at(i).getFecha() <<") : "<<canciones.at(i).getLongitud()<<" segundos"<<endl
              <<".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.-.-.-"<<endl;
    }
}

void Reproductor::buscarCanciones() const
{
    string patron;
    int coincidencias = 0;
    vector<Cancion>::const_iterator it = canciones.begin();

    cout<<"Nombre: ";
    getline(cin, patron);

    while(it != canciones.end())
    {
        it = find_if(it, canciones.end(), [&patron](Cancion s) -> bool
        {
                return s.getNombre().find(patron, 0) < s.getNombre().length();
    });
        if(it != canciones.end())
        {
            cout<<(*it).getNombre()<<" - "<<(*it).getArtista()<<"("
                 <<(*it).getFecha() <<") : "<<(*it).getLongitud()<<" segundos"<<endl
                  <<".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.-.-.-"<<endl;
            ++it;
            ++coincidencias;
        }
    }
    if(coincidencias == 0)
    {
        cout<<"\nNo se encontro la cancion."<<endl;
    }
    cout<<endl;
}

void Reproductor::eliminarCancion()
{
    size_t posicion;

        for (size_t i(0); i < canciones.size(); ++i)
        {
            cout<<i+1<<") "<<canciones.at(i).getNombre()<<" - "<<canciones.at(i).getArtista()<<"("
                 <<canciones.at(i).getFecha() <<") : "<<canciones.at(i).getLongitud()<<" segundos"<<endl
                  <<".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.-.-.-"<<endl;
        }
        cout <<"Selecciona una cancion (0 cancelar): ";
        cin>>posicion;

        if(0 < posicion && posicion <= canciones.size())
        {
            canciones.erase(canciones.begin() + posicion - 1);
            if(0 < posicion && posicion <= playlist.size())
            {
                playlist.erase(playlist.begin() + posicion - 1);
            }
            cout<<"\nCancion eliminada con exito."<<endl<<endl;
        }
        else if(posicion == 0)
        {
            cout<<"\nNo se eliminara ninguna cancion."<<endl<<endl;
        }
        else
        {
            cout<<"\nNo existe la cancion"<<endl<<endl;
        }
}

void Reproductor::agregarPlaylist()
{
    size_t ubicacion;
        for (size_t i(0);i < canciones.size();++i)
        {
            cout<<i+1<<") "<<canciones.at(i).getNombre()<<" - "<<canciones.at(i).getArtista()<<"( "
                 <<canciones.at(i).getFecha() <<") : "<<canciones.at(i).getLongitud()<<" segundos"<<endl
                  <<".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.-.-.-"<<endl;
        }
    cout <<"Selecciona una cancion para ponerla en la lista de reproduccion(0 cancelar): ";
    cin>>ubicacion;

        if(0 < ubicacion && ubicacion <= canciones.size())
        {
            playlist.insert(playlist.end(), canciones.at(ubicacion - 1));
            cout<<"\nCancion agregada a la playlist"<<endl<<endl;
        }
        else if(ubicacion == 0)
        {
            cout<<"\nNo se agregara ninguna cancion"<<endl<<endl;
        }
        else
        {
            cout<<"\nNo existe la cancion"<<endl<<endl;
        }
}

void Reproductor::mostrarPlaylist() const
{
    for (size_t i(0);i < playlist.size();++i)
    {
        cout<<playlist.at(i).getNombre()<<" - "<<playlist.at(i).getArtista()<<"( "
         <<playlist.at(i).getFecha() <<") : "<<playlist.at(i).getLongitud()<<" segundos"<<endl
          <<".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.-.-.-"<<endl;
    }
}

void Reproductor::eliminarPlaylist()
{
    size_t position;

    for(size_t i(0); i < playlist.size(); ++i)
    {
        cout<<i+1<<") "<<playlist.at(i).getNombre()<<" - "<<playlist.at(i).getArtista()<<" ("
             <<playlist.at(i).getFecha()<<") : "<<playlist.at(i).getLongitud()<<" segundos"<<endl
              <<".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.-.-.-"<<endl;
    }
    cout<<"Selecciona una cancion a eliminar de la lista de reproduccion (0 cancelar): ";
    cin>>position;

    if(0 < position && position <= playlist.size())
    {
        playlist.erase(playlist.begin() + position - 1);
    }
    else if(position == 0)
    {
        cout<<"\nNo se eliminara ninguna cancion de la playlist."<<endl<<endl;
    }
    else
    {
        cout<<"\nNo existe la cancion"<<endl<<endl;
    }
}

void Reproductor::reproducirPlaylist() const
{
    for(size_t i(0); i < playlist.size(); ++i)
    {
        cout<<"Reproduciendo: "<<playlist.at(i).getNombre()<<" - "<<playlist.at(i).getArtista()<<" ("
             <<playlist.at(i).getFecha()<<") : "<<playlist.at(i).getLongitud()<<" segundos"<<endl; //la creatividad no es lo mio xD
    }
}

void Reproductor::menu2()
{
    int opcion;

    do
    {
        cout<<"\n                        Lista de Reproduccion\n"<<endl
             <<OPC_AGREGARLISTA<<") Agregar cancion"<<endl
              <<OPC_MOSTRARLISTA<<") Mostrar lista de reproduccion"<<endl
               <<OPC_BORRARPLAYLIST<<") Borrar cancion"<<endl
                <<OPC_REPRODUCIRPLAYLIST<<") Reproducir lista"<<endl
                 <<OPC_VOLVERALMENU<<") Volver al menu principal"<<endl
                 <<"Selecciona una opcion: ";
                 cin>>opcion;
                 cin.ignore();

                switch(opcion)
                {
                    case OPC_AGREGARLISTA:
                        cout<<"                        Agregar cancion a la lista de reproduccion\n"<<endl;
                        agregarPlaylist();
                        break;
                    case OPC_MOSTRARLISTA:
                        cout<<"                        Mostrar lista de reproduccion\n"<<endl;
                        if(playlist.size() > 0)
                        {
                            mostrarPlaylist();
                        }
                        else
                        {
                            cout<<"\nNo hay canciones en tu lista de reproduccion"<<endl;
                        }
                        break;
                    case OPC_BORRARPLAYLIST:
                        cout<<"                        Eliminar cancion de la lista de reproduccion\n"<<endl;
                        if(playlist.size() > 0)
                        {
                            eliminarPlaylist();
                        }
                        else
                        {
                            cout<<"\nNo hay canciones en tu lista de reproduccion"<<endl;
                        }
                        break;
                    case OPC_REPRODUCIRPLAYLIST:
                        cout<<"                        Reproducir lista de reproduccion\n"<<endl;
                        if(playlist.size() > 0)
                        {
                            reproducirPlaylist();
                        }
                        else
                        {
                            cout<<"\nNo hay canciones en tu lista de reproduccion"<<endl;
                        }
                        break;
                    case OPC_VOLVERALMENU: cout<<"\nVolviendo al menu";break;
                    default: cout<<"\nOpcion no valida"<<endl;break;
                }
    }while(opcion != OPC_VOLVERALMENU);
}

void Reproductor::menu()
{
    int opc;

    do
    {
        cout<<"                        Reproductor"<<endl<<endl
             <<OPC_AGREGAR<<") Agregar cancion"<<endl
              <<OPC_MOSTRAR<<") Mostrar canciones"<<endl
               <<OPC_BUSCAR<<") Buscar cancion"<<endl
                <<OPC_BORRAR<<") Borrar cancion"<<endl
                 <<OPC_PLAYLIST<<") Playlist"<<endl
                  <<OPC_SALIR<<") Salir"<<endl
                  <<"Selecciona una opcion: ";
                 cin>>opc;
                 cin.ignore();

                 switch(opc)
                 {
                 case OPC_AGREGAR:
                    cout<<"\n                        Agregar Cancion\n"<<endl;
                    agregarCanciones();
                    break;
                 case OPC_MOSTRAR:
                    cout<<"\n                        Mostrar Canciones\n"<<endl;
                    if(canciones.size() > 0)
                    {
                        mostrarCanciones();
                    }
                    else
                    {
                        cout<<"No hay canciones registradas."<<endl<<endl;
                    }
                    break;
                 case OPC_BUSCAR:
                    cout<<"\n                        Buscar Cancion\n"<<endl;
                    if(canciones.size() > 0)
                    {
                        buscarCanciones();
                    }
                    else
                    {
                        cout<<"No hay canciones registradas."<<endl<<endl;
                    }
                    break;
                 case OPC_BORRAR:
                    cout<<"\n                        Eliminar Cancion\n"<<endl;
                    if(canciones.size() > 0)
                    {
                        eliminarCancion();
                    }
                    else
                    {
                        cout<<"No hay canciones registradas."<<endl<<endl;
                    }
                    break;
                 case OPC_PLAYLIST:
                    if(canciones.size() > 0)
                    {
                        menu2();
                    }
                    else
                    {
                        cout<<"\nNo hay canciones registradas.";
                    }
                 case OPC_SALIR:
                    cout<<""<<endl<<endl;
                    break;
                 default:
                    cout<<"\nOpcion no valida.\n"<<endl;
                    break;
                 }
    }while(opc != OPC_SALIR);
}
