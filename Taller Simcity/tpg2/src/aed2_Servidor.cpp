#include "aed2_Servidor.h"

aed2_Servidor::aed2_Servidor() : _servidor() {}

void aed2_Servidor::nuevaPartida(Jugador j, set<int> horizontales , set<int> verticales) {
    auto* hor = new Lista<int>();
    auto* ver = new Lista<int>();
    for(int i : horizontales) {
        hor->agregarAtras(new int(i));
    }
    for(int i : verticales) {
        ver->agregarAtras(new int(i));
    }
    Mapa* m = new Mapa(*hor, *ver);
    _servidor.agregarPartida(j, *m);
}


void aed2_Servidor::agregarCasa(Jugador j, Casilla c) {
    auto* casa = new pair<Casilla, string>(c, "casa");
    _servidor.agregarConstruccion(j, *casa);
    delete casa;
}

void aed2_Servidor::agregarComercio(Jugador j, Casilla c) {
    auto* com = new pair<Casilla, string>(c, "comercio");
    _servidor.agregarConstruccion(j, *com);
    delete com;
}

void aed2_Servidor::avanzarTurno(Jugador j) {
    _servidor.avanzarTurno(j);
}

void aed2_Servidor::unir(Jugador j1, Jugador j2) {
    _servidor.unir(j1, j2);
}

set<int> aed2_Servidor::riosHorizontales(Jugador j) const {
    Lista<int>& riosVs = _servidor.mapa(j).Horizontales();
    set<int> res;
    for(int i=0;i<riosVs._length;i++){
        res.insert(riosVs.iesimo(i));
    }
    return res;
}

set<int> aed2_Servidor::riosVerticales(Jugador j) const {
    Lista<int>& riosVs = _servidor.mapa(j).Verticales();
    set<int> res;
    for(int i=0;i<riosVs._length;i++) {
        res.insert(riosVs.iesimo(i));
    }
    return res;
}

set<Casilla> aed2_Servidor::casas(Jugador j) const {
    ConstruccionesT& construcciones = _servidor.ConstruccionesSV(j);
    set<Casilla> res;
    for(int i = 0;i < construcciones._length;i++){      // si encuentro una casa, la agrego
        if(get<0>(construcciones.iesimo(i)) == "casa"){
            res.insert(get<1>(construcciones.iesimo(i)));
        }
    }
    return res;
}

set<Casilla> aed2_Servidor::comercios(Jugador j) const {
    ConstruccionesT& construcciones = _servidor.ConstruccionesSV(j);
    set<Casilla> res;
    for(int i = 0;i < construcciones._length;i++){    // si encuentro un comercio, lo agrego
        if(get<0> (construcciones.iesimo(i)) == "comercio"){
            res.insert(get<1>(construcciones.iesimo(i)));}
    }
    return res;
}

Nat& aed2_Servidor::nivel(Jugador j, Casilla c) const {
    return _servidor.nivel(j, c);
}

Nat aed2_Servidor::popularidad(Jugador j) const {
    return _servidor.popularidad(j);
}

Nat aed2_Servidor::antiguedad(Jugador j) const {
    return _servidor.antiguedad(j);
}

bool aed2_Servidor::huboConstruccion(Jugador j) const {
    return _servidor.huboConstruccion(j);
}

aed2_Servidor::~aed2_Servidor() {}
