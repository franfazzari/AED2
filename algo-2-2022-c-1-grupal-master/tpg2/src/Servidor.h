#ifndef TP_SimCity_SERVIDOR_H
#define TP_SimCity_SERVIDOR_H
#include "SimCity.h"
#include "Tipos.h"
#include "Mapa.h"
#include "string_map.h"

class Servidor {
public:
    //Constructor de Servidor
    Servidor();

    //Destructor
    ~Servidor();

    //Mapa
    Mapa& mapa(Jugador j) const;

    //Funciones que se piden en el servidor de la cátedra
    bool agregarPartida(Jugador j, Mapa& m);

    void agregarConstruccion(Jugador j, pair<Casilla, Construccion>& constr) const;

    void avanzarTurno(Jugador j);

    void unir(Jugador j1, Jugador j2);

    ConstruccionesT& ConstruccionesSV(Jugador j) const;

    Nat& nivel(Jugador j, Casilla c) const;

    bool huboConstruccion(Jugador j) const;

    Nat popularidad(Jugador j) const;

    Nat antiguedad(Jugador j) const;


private:
    string_map<SimCity> _nombres;

};
#endif //TP_SimCity_SERVIDOR_H
