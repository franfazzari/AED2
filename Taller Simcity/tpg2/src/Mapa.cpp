#include "Mapa.h"

Mapa::~Mapa() {
    Lista<int>* h = _horizontales;
    _horizontales = nullptr;
    delete h;
    Lista<int>* v = _verticales;
    _verticales = nullptr;
    delete v;
}

Lista<int>& Mapa::Horizontales() {
    return *_horizontales;
}

Lista<int>& Mapa::Verticales() {
    return *_verticales;
}

Mapa::Mapa(Lista<int>& list1, Lista<int>& list2) {
    _horizontales = &list1;
    _verticales = &list2;

}
Mapa& Mapa::unirRios(Mapa &mapa) {
    _horizontales->agregarNodoAtras(mapa._horizontales->head);
    _horizontales->tail = mapa._horizontales->tail;
    _horizontales->_length += mapa._horizontales->_length-1;
    _verticales->agregarNodoAtras(mapa._verticales->head);
    _verticales->tail = mapa._verticales->tail;
    _verticales->_length += mapa._verticales->_length-1;
    return *this;
}

void Mapa::destruir() {
    Lista<int>* h = _horizontales;
    _horizontales = nullptr;
    h->softDelPrep();
    delete h;
    Lista<int>* v = _verticales;
    _verticales = nullptr;
    v->softDelPrep();
    delete v;
}