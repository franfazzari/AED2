#include "Mapa.h"
#include "Tipos.h"
#ifndef TP_SimCity_SimCity_H
#define TP_SimCity_SimCity_H



class SimCity {
public:

    /**
     * Constructor por defecto de la clase SimCity.
     */
    SimCity(Mapa& mapa);

    /**
     * Destructor de la clase SimCity
     */

    ~SimCity();

    /**
    * Mapa del SimCity
    */
    Mapa& mapa() const;

    /**
     * Turno
     */
    int Turno() const;


    /**
     * Funciones para agregar de a 1 casa y de a 1 comercio (muy probablemente nos convenga tenerlas en SimCity)
     */
    void agregarConstruccion(pair<Casilla, Construccion>& constr);

    /**
     * Popularidad del SimCity
     */
    Nat popularidad();

    /**
     * Unir de la clase SimCity
     */
    void unirSC(SimCity& sim);

    /**
     * avanzar turno: aumenta el turno y el nivel de todas las casas y comercios. Al encargarse Comercios de los niveles manhattan, aca no se chequean en caso de union.
     */
    void avanzarTurno();

    /**
     * Funcion que nos da el total de construcciones, en reemplazo a casas y comercios
     */
    ConstruccionesT& Construcciones() const;

    /**
     * Funcion que me ordena las  construcciones (sirve para la union de 2 simcities)
     */
    void ordenarConstrucciones();

    /**
     * Funcion que aumenta el nivel de los comercios en base a las casas que tiene a distancia manhattan <= 3.
     */
    void UpdateNivel();

    /**
     * Funcion que devuelve si hubo alguna construccion
     */
    bool huboConstruccion();


    /**
     * Funcion que me da el mayor nivel entre todas las casas cercanas a una casilla
     */
    Nat mayorNivelDeCasas(Casilla);

    /**
     * Funcion que me dice si una casilla se encuentra a distancia manhattan 3 de otra
     */
    bool esDistManTres(Casilla& pos1, Casilla& pos2);

    /**
     * Funcion que me devuelve el nivel de una casilla
     */
     Nat nivel(Casilla c);


    bool _habilitado;       //Funcion que me dice si un SimCity esta habilitado para que se le agreguen más construcciones o se le unan otros simcities
private:
    Mapa* _mapa;
    ::ConstruccionesT* _constr;
    Nat _popularidad;
    int _turno;
    bool _huboConstruccion;



};
#endif //TP_SimCity_SimCity_H