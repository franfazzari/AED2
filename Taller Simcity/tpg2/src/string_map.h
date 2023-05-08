#ifndef STRING_MAP_H_
#define STRING_MAP_H_

#include <string>

using namespace std;

template<typename T>
class string_map {
public:
    string_map();
    string_map(const string_map<T>& aCopiar);
    string_map& operator=(const string_map& d);
    ~string_map();
    void insert(string key, T* val);
    int count(const string& key) const;
    T& at(const string& key) const;
    T& at(const string& key);
    void erase(const string& key);
    int size() const;
    bool empty() const;

    /** OPTATIVO
    * operator[]
    * Acceso o definición de pares clave/valor
    **/
    T &operator[](const string &key);

private:

    struct Nodo {
        vector<Nodo*> siguientes;
        T* definicion;

        Nodo(): siguientes(256, nullptr), definicion(nullptr) {};
        int hijos() {
            for(int i=0;i<256;i++)
                if(this->siguientes[i] != NULL)
                    return 1;
            return 0;
        };
        Nodo& copiar(const Nodo* nod) {
            if(nod->definicion != NULL)
                this->definicion = nod->definicion;
            for(int i=0;i<256;i++) {
                if(nod->siguientes[i] != NULL) {
                    if(nod->siguientes[i]->hijos() == 0) {
                        Nodo *nodo = new Nodo();
                        nodo->definicion = nod->siguientes[i]->definicion;
                        this->siguientes[i] = nodo;
                    } else {
                        Nodo *nodo = new Nodo();
                        nodo->copiar(nod->siguientes[i]);
                        this->siguientes[i] = nodo;
                    }
                }
            }
            return *this;
        };
        bool borrar(int let) {
            Nodo* del = this->siguientes[let];
            if(del->hijos() == 0) {
                this->siguientes[int(let)] = NULL;
                delete del;
                return true;
            }
            return false;
        };
        void destruir(int let) {
            Nodo* del = this->siguientes[let];
            for(int i=0;i<256;i++)
                if(del->siguientes[i] != NULL)
                    del->destruir(i);
            this->siguientes[int(let)] = NULL;
            delete del;
        };
        ~Nodo() {
            T* e = definicion;
            definicion = nullptr;
            delete e;
        };
    };

    Nodo* raiz;
    int _size;
};

#include "string_map.hpp"

#endif // STRING_MAP_H_
