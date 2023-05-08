#include "SimCity.h"

SimCity::SimCity(Mapa& m) : _turno(0) , _popularidad(0), _huboConstruccion(false), _habilitado(true) {
    auto* l = new Lista<tuple<Construccion, Casilla, Nat>>();  // constructor de lista enlazada
    _constr = l;
    _mapa = &m;
}

void SimCity::avanzarTurno() {
    ordenarConstrucciones();
    UpdateNivel();
    _turno++;
    _huboConstruccion = false;
}

void SimCity::ordenarConstrucciones() {
    for (int i = 0; i < _constr->_length - 1; i++){
        for (int k = i + 1; k < _constr->_length; k++){
            if (get<1>(_constr->iesimo(i)) == get<1>(_constr->iesimo(k))) {
                if (get<0>(_constr->iesimo(i)) == get<0>(_constr->iesimo(k))){
                    if(get<2>(_constr->iesimo(i)) > get<2>(_constr->iesimo(k))) {
                        _constr->eliminar(k);
                    } else {
                        _constr->eliminar(i);
                    }
                } else {
                    if(get<0>(_constr->iesimo(i)) == "casa") {
                        _constr->eliminar(k);
                    } else {
                        _constr->eliminar(i);
                    }
                    k--;
                }
            }
        }
    }
}


void SimCity::agregarConstruccion(pair<Casilla, Construccion>& constr) {
    Nat nivelAAgregar = 0;
    if (constr.second == "comercio") {
        nivelAAgregar = 0;
    }
    auto* t = new tuple<Construccion, Casilla, Nat>(constr.second, constr.first, nivelAAgregar);
    _constr->agregarAtras(t);
    _huboConstruccion = true;
}

int SimCity::Turno() const{
    return _turno;
}


Nat SimCity::popularidad(){
    return _popularidad;
}

Mapa& SimCity::mapa() const{
    return *_mapa;
}
ConstruccionesT& SimCity::Construcciones() const{
    return *_constr;
}

void SimCity::unirSC(SimCity &sim) {
    _constr->agregarNodoAtras(sim._constr->head);
    _constr->tail = sim._constr->tail;
    _constr->_length += sim._constr->_length-1;
    _mapa->unirRios(sim.mapa());
    _huboConstruccion = _huboConstruccion || sim.huboConstruccion();
    _turno = max(_turno, sim.Turno());
    _popularidad += sim.popularidad() + 1;
    sim._habilitado = false;
}



void SimCity::UpdateNivel() {
    for(int i=0;i < _constr->_length;i++){
        get<2>(_constr->iesimo(i))++;
    }
}

bool SimCity::esDistManTres(Casilla &pos1, Casilla &pos2) {
    return (abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second)) <= 3;
}

Nat SimCity::mayorNivelDeCasas(Casilla pos){ // devuelve el nivel de la casa con la distMan mayor
    Nat res = 0;
    for(int x = 0;x < _constr->_length;x++){
        if(get<0>(_constr->iesimo(x)) == "casa" && esDistManTres(pos, get<1>(_constr->iesimo(x))) && get<2>(_constr->iesimo(x)) > res){
            res = get<2>(_constr->iesimo(x));
        }
    }
    return res;
}

bool SimCity::huboConstruccion(){
    return _huboConstruccion;
}

SimCity::~SimCity() {
    ::ConstruccionesT* c = _constr;
    _constr = nullptr;
    Mapa* m = _mapa;
    _mapa = nullptr;
    if(!_habilitado) {
        m->destruir();
        c->_length = 0;
    }
    delete c;
    delete m;
}


