#include "Servidor.h"
#include "SimCity.h"

Servidor::Servidor() : _nombres() {}

bool Servidor::agregarPartida(Jugador j, Mapa &m) {
    if(_nombres.count(j) > 0) {
        return false;
    }
    auto* s = new SimCity(m);
    _nombres.insert(j, s);
    return true;
}

void Servidor::avanzarTurno(Jugador j) {
    _nombres.at(j).avanzarTurno();
}

void Servidor::unir(Jugador j1, Jugador j2) {
    if(_nombres.at(j1)._habilitado && _nombres.at(j2)._habilitado) {
        _nombres.at(j1).unirSC(_nombres.at(j2));
        _nombres.at(j2)._habilitado = false;
    }
    _nombres.at(j1).ordenarConstrucciones();
    ::ConstruccionesT& constr = _nombres.at(j1).Construcciones();
    for(int i = 0;i < constr._length;i ++) {
        if (get<0>(constr.iesimo(i)) == "comercio"){
            get<2>(constr.iesimo(i)) = max(get<2>(constr.iesimo(i)), _nombres.at(j1).mayorNivelDeCasas(get<1>(constr.iesimo(i))));
        }
    }
}


Nat& Servidor::nivel(Jugador j, Casilla c) const {
    ::ConstruccionesT& constr = _nombres.at(j).Construcciones();
    for(int i=0;i<constr._length;i++){
        if(get<1>(constr.iesimo(i)) == c) {
            if (get<0>(constr.iesimo(i)) == "comercio" &&
                get<2>(constr.iesimo(i)) < _nombres.at(j).mayorNivelDeCasas(c)){
                get<2>(constr.iesimo(i)) = _nombres.at(j).mayorNivelDeCasas(c);
                return get<2>(constr.iesimo(i));
            }

            else {
                return get<2>(constr.iesimo(i));
            }

        }
    }
    return *new Nat(0);
}


Nat Servidor::antiguedad(Jugador j) const{
    return _nombres.at(j).Turno();
}

Nat Servidor::popularidad(Jugador j) const{
    return _nombres.at(j).popularidad();
}

Mapa& Servidor::mapa(Jugador j) const{
    return _nombres.at(j).mapa();
}

ConstruccionesT& Servidor::ConstruccionesSV(Jugador j) const{
    SimCity& s = _nombres.at(j);
    ::ConstruccionesT& c = s.Construcciones(); // por alguna razon tira error si no pongo los ::
    return c;
}

void Servidor::agregarConstruccion(Jugador j, pair<Casilla, Construccion>& constr) const{
    _nombres.at(j).agregarConstruccion(constr);
}

bool Servidor::huboConstruccion(Jugador j) const {
    return _nombres.at(j).huboConstruccion();
}

Servidor::~Servidor() {};