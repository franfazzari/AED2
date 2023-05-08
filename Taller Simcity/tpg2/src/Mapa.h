#ifndef TP_SimCity_MAPA_H
#define TP_SimCity_MAPA_H
#include "Tipos.h"
using namespace std;
class Mapa {

public:
// Constructor por defecto de Mapa.
    Mapa(Lista<int>& set1, Lista<int>& set2);

// Destructor de la clase Mapa.
    ~Mapa();

    //Auxiliar del destructor de mapa.
    void destruir();

    // Devuelve los Horizontales del Mapa.
    Lista<int>& Horizontales();

    // Devuelve los Verticales del Mapa.
    Lista<int>& Verticales();

    //Une los rios de
    Mapa& unirRios(Mapa &mapa);



private:
    Lista<int>* _horizontales;
    Lista<int>* _verticales;
};
#endif //TP_SimCity_MAPA_H