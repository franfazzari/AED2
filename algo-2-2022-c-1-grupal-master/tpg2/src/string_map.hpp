template <typename T>
string_map<T>::string_map() : raiz(nullptr), _size(0) {}

// Provisto por la catedra: utiliza el operador asignacion para realizar la copia.
template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; }

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    if(d.raiz == nullptr) {
        this->raiz = nullptr;
        this->_size = 0;
        return *this;
    }
    Nodo *nodo = new Nodo();
    nodo->copiar(d.raiz);
    this->raiz = nodo;
    this->_size = d._size;
}

template <typename T>
string_map<T>::~string_map(){
    if(this->raiz == nullptr)
        return;
    for(int i=0;i<256;i++)
        if(this->raiz->siguientes[i] != NULL)
            this->raiz->destruir(i);
    if(this->raiz != nullptr) {
        Nodo *actual = raiz;
        raiz = nullptr;
        delete actual;
    }
}

template <typename T>
void string_map<T>::insert(string key, T* val) {
    if(raiz == nullptr) {
        Nodo *nodo = new Nodo();
        raiz = nodo;
    }
    Nodo *actual = raiz;
    for(char i : key) {
        if(actual->siguientes[int(i)] == NULL) {
            Nodo *nodo = new Nodo();
            actual->siguientes[int(i)] = nodo;
        }
        actual = actual->siguientes[int(i)];
    }
    actual->definicion = val;
    this->_size++;
}

template <typename T>
int string_map<T>::count(const string& key) const{
    if(raiz == nullptr)
        return 0;
    Nodo *actual = raiz;
    for(unsigned char let : key) {
        if(actual->siguientes[int(let)] == NULL)
            return 0;
        actual = actual->siguientes[int(let)];
    }
    return actual->definicion != NULL;
}

template <typename T>
T& string_map<T>::at(const string& key) const {
    Nodo *actual = raiz;
    for(unsigned char let : key)
        actual = actual->siguientes[int(let)];
    return *actual->definicion;
}

template <typename T>
T& string_map<T>::at(const string& key) {
    Nodo *actual = raiz;
    for(unsigned char let : key)
        actual = actual->siguientes[int(let)];
    return *actual->definicion;
}

template <typename T>
void string_map<T>::erase(const string& key) {
    Nodo *actual = raiz;
    for(unsigned char let : key)
        actual = actual->siguientes[int(let)];
    actual->definicion = nullptr;
    for(int i=key.length()-1;i>=0;i--) {
        Nodo *actual = raiz;
        for(int x=0;x<i;x++)
            actual = actual->siguientes[int(key[x])];
        if(!actual->borrar(int(key[i])))
            break;
    }
    this->_size--;
    if(this->_size == 0) {
        Nodo *actual = raiz;
        raiz = nullptr;
        delete actual;
    }
}

template <typename T>
int string_map<T>::size() const{ return _size; }

template <typename T>
bool string_map<T>::empty() const{ return _size == 0; }

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
}
