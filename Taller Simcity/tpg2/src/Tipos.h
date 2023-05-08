#ifndef TIPOS_H
#define TIPOS_H

#include <cstdlib>
#include <cassert>
#include <iostream>
#include <tuple>
#include <map>
#include <list>
#include <set>
#include <vector>
#include "Lista_enlazada.h"
#include "string_map.h"

using namespace std;

using Nat = unsigned int;

using Casilla = pair<int, int>;

using Construccion = string;

using Jugador = string;

using ConstruccionesT = Lista<tuple<Construccion, Casilla, Nat>>;


#endif // TIPOS_H


