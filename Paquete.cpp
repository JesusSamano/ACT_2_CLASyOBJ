#include "Paquete.h"
#include <iostream>
#include <string>
using namespace std;

// Constructores Paquete //

Paquete::Paquete(){}

Paquete::Paquete(const Paquete& s)
{
    Id = s.Id;
    Origen = s.Origen;
    Destino = s.Destino;
    Peso = s.Peso;

};


//Regresa Datos
ostream& operator << (ostream& o,Paquete& s2)
{
    cout<<"\nId : ";
    o<<s2.Id;
    cout<<"\nOrigen: ";
    o<<s2.Origen;
    cout<<"\nDestino: ";
    o<<s2.Destino;
    cout<<"\nPeso: ";
    o<<s2.Peso;
    cout<<endl;
    return o;


}


//Imprime datos
istream& operator>>(istream& o,Paquete& s2)
{
    cout<<endl;
    cout<<"Ingresa ID: ";
    o>>s2.Id;
    fflush(stdin);
    cout<<"Ingresa Origen: ";
    getline(o, s2.Origen);
    fflush(stdin);
    cout<<"Ingresa destino: ";
    getline(o, s2.Destino);
    cout<<"Ingresa peso: ";
    o>>s2.Peso;
    return o;

}
