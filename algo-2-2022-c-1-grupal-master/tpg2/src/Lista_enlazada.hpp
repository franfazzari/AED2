#include "Lista_enlazada.h"

template <class T>
Lista<T>::Lista() : _length(0), head(nullptr), tail(nullptr) {}

template <class T>
Lista<T>::~Lista() {
    while(this->_length > 0) {
        this->eliminar(0);
    }
}



template <class T>
void Lista<T>::agregarAtras(T* elem) {
    Node *node = new Node(elem);
    if (this->tail == nullptr && this->head == nullptr)
        this->head = node;
    else
        this->tail->next = node;
    this->tail = node;
    this->_length++;
}

template <class T>
void Lista<T>::eliminar(unsigned int i) {
    Node* prev;
    Node* act = this->head;
    for (int x=0;x<i;x++) {
        prev = act;
        act = act->next;
    }
    if (this->head == act && this->tail == act) {
        this->head = nullptr;
        this->tail = nullptr;
    } else {
        if (this->head == act || this->tail == act)
            this->head == act ? (this->head = act->next) : (this->tail = prev);
        else
            prev->next = act->next;
    }
    T* val = act->data;
    act->data = nullptr;
    delete val;
    delete act;
    this->_length--;
}

template <class T>
T& Lista<T>::iesimo(unsigned int i) {
    Node* act = this->head;
    for (int x=0;x<i;x++) {
        act = act->next;
    }
    return *act->data;
}

template<class T>
void Lista<T>::agregarNodoAtras(Lista::Node* nod) {
    if (this->tail == nullptr && this->head == nullptr)
        this->head = nod;
    else
        this->tail->next = nod;
    this->tail = nod;
    this->_length++;
}

template<class T>
void Lista<T>::softDelPrep() {
    _length = 0;
}
