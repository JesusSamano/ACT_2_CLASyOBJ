#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <exception>

using namespace std;

template<class T>
class Paqueteria  //  LISTA SIMPLEMENTE LIGADA  //
{
    private:
        class Nodo{  // CLASE NODO //;
            private:
                T dato;
                Nodo *sig; // Sig = Siguiente
            public:
                Nodo():sig(nullptr){};
                friend class Paqueteria; // Nodo y listaSL Clases amigas
                };

        Nodo* ancla; // cabecera


        bool posicionValida( Nodo* )const;

    public:
        class Exception : public std::exception{
            private:
                std::string msg;
                public:
                    explicit Exception(const char* message) : msg(message){}

                    explicit Exception(const std::string& message) : msg(message){}

                    virtual ~Exception() throw (){}

                    virtual const char* what() const throw(){
                        return msg.c_str();
                        }
                };


        Paqueteria():ancla(nullptr){}; //Nulo = nullptr / incializar en nulo
        virtual ~Paqueteria(){
        anula();
        };
        //ListaSL():cont(0) {};// Inicializa

        // Metodos
        bool vacia()const; //no modifica atributos de la clase constante
        void inserta(T, Nodo*); //Puntero nodo
        bool elimina(Nodo*);
        Nodo* anterior(Nodo*)const;
        Nodo* primero()const;
        Nodo* ultimo()const;
        Nodo* siguiente(Nodo*)const;
        Nodo* localiza(T)const;
        void recupera(Nodo*)const;
        void anula();
        void imprime()const;
        void guardar()const;

};



//   IMPLEMENTACION   //
/*
ListaSL::ListaSL(){
    anula();
}
*/
template <class T>
bool Paqueteria<T>::posicionValida(Nodo* pos) const {
    Nodo* aux(ancla);

    while(aux != nullptr){
        if(aux == pos){
            return true;
        }

        aux = aux ->sig;
    }
    return false;
}


template<class T>
bool Paqueteria<T>::vacia()const{
    if(ancla == nullptr)
        return true;
    return false;
}

template<class T>
void Paqueteria<T>::inserta(T elem, Nodo* pos)
{
    Nodo* aux=new Nodo; //Crea nuevo nodo con new
    aux -> dato = elem; //Pase por valor
    if(pos==nullptr) // Inserta al principio
    {
        aux -> sig = ancla;
        ancla = aux;
        cout<< "\nCaptura de datos EXITANTE";
    }


    else // Inserta en cualquier otro lugar
    {
        aux -> sig = pos -> sig;
        pos -> sig = aux;
        cout<< "\nCaptura de datos EXITANTE";
    }

}

template<class T>
bool Paqueteria<T>::elimina(Nodo* pos){
    if(vacia() || pos==nullptr) // Valida posicion
    {
        cout<<"\nIrror";
        return false;
    }
    if(pos==ancla) // Elimina al principio
    {
        ancla=ancla->sig;

    }
    else // Elimina en cualquier otro lugar
        anterior(pos)->sig=pos->sig;
    //free
    delete(pos);
    //cout<<"\nSocio eliminado";
    return true;
}

template<class T>
typename Paqueteria<T>::Nodo* Paqueteria<T>::anterior(Nodo* pos)const
{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    Nodo* aux=ancla;
    while(aux!=nullptr && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}


template<class T>
typename Paqueteria<T>::Nodo* Paqueteria<T>::primero()const
{
    return ancla;
}

template<class T>
typename Paqueteria<T>::Nodo* Paqueteria<T>::ultimo()const

{
    if(vacia()){
        return nullptr;
    }
    Nodo* aux=ancla;
    while(aux->sig!=nullptr){ //Recorre
        aux=aux->sig;
    }
    return aux;
}

template<class T>
typename Paqueteria<T>::Nodo* Paqueteria<T>::siguiente(Nodo* pos)const{
    if(vacia() || pos==nullptr)
        return nullptr;
    return pos->sig;
}

template<class T>
typename Paqueteria<T>::Nodo* Paqueteria<T>::localiza(T elem)const{
    Nodo* aux=ancla;
    while(aux!=nullptr && aux->dato!=elem){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
void Paqueteria<T>::recupera(Nodo* pos)const{
    if(!posicionValida(pos)){
        throw Exception ("Posicion invalida");
    }
    cout<<"\nSocio encontrado: \n"<<pos->dato;
        //Excepciones
}


template<class T>
void Paqueteria<T>::anula(){
    Nodo* aux;
    while(ancla != nullptr){
        aux= ancla;
        ancla= ancla->sig;
        delete(aux);
    }
}

template<class T>
void Paqueteria<T>::imprime()const{
    if(vacia()){
        cout<<"\nRegistro sin datos";
        return;}

    Nodo* aux =ancla;
    while(aux!=nullptr){
        std::cout<<aux->dato<<"\n";
        aux=aux->sig;
    }
}





#endif // NODO_H
