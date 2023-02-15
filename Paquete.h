#ifndef PAQUETE_H
#define PAQUETE_H
#include <iostream>

using namespace std;


class Paquete
{
    private://Atributos
        int Id;
        string Origen;
        string Destino;
        string Peso;


    public://Metodos
        Paquete();
        Paquete(const Paquete& s);
    friend ostream& operator<<(ostream& ,Paquete&);
    friend istream& operator>>(istream& ,Paquete&);


};

#endif // PAQUETE_H
