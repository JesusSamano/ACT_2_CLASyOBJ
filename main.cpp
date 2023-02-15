#include <iostream>
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Paqueteria.h"
#include "Paquete.h"
using namespace std;

int main(){ // MENU
    int opc;
    Paqueteria<Paquete> lista;
    Paquete objeto, aux;

    do{


        cout<<"                                             MENU                                 ";
        cout<<"\n 1.- Agregar Inicio \n 2.- Agregar fianl \n 3.- Mostrar \n 4.- Salir ";
        cin>>opc;
        switch(opc){

            case 1:
                cin>>objeto;
                lista.inserta(objeto,lista.anterior(lista.primero()));
                break;

            case 2:
                cin>>objeto;
                lista.inserta(objeto,lista.ultimo());
                break;

            case 3:
                lista.imprime();
                break;
        }

    }while(opc!=5);


}
