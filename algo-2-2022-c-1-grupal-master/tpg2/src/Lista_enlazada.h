#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

#include <string>
#include <ostream>

using namespace std;

template <class T>
class Lista {
public:
    Lista();
    ~Lista();
    void agregarAtras(T* elem);
    void eliminar(unsigned int i);
    int _length;
    T& iesimo(unsigned int i);
    void softDelPrep();
    struct Node {
        Node(T* elem): next(nullptr) {
            data = elem;
        };
        T* data;
        Node* next;
    };
    Node* head;
    Node* tail;
    void agregarNodoAtras(Node* nod);
};
#include "Lista_enlazada.hpp"

#endif
