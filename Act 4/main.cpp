/*
*   Rutas de autobus
*   Autor: Enrique Santos Fraire
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include "graph.h"
using namespace std;

int main(){
    // Objetos para clases
    Graph graph;

    // Declaración de variables
    int op, partida, llegada, resp;
    bool salida=false;

    graph.loadGraphList("rutas.txt", 6, 6);

    cout<<"----------Rutas de Autobus----------"<<endl;
    cout<<endl;
    cout<<"0 Queretaro\n";
    cout<<"1 Zacatecas\n";
    cout<<"2 Aguascalientes\n";
    cout<<"3 San Luis Potosi\n";
    cout<<"4 CDMX\n";
    cout<<"5 Hidalgo\n\n";

    while(salida==false){
        cout<<"Seleccionar una opcion:\n";
        cout<<"1) Mostrar rutas\n";
        cout<<"2) Mostrar camino de un punto a otro\n";
        cout<<"3) Mostrar camino mas corto de un punto a otro\n";
        cout<<"4) Salir\n";
        cin>>op;
        cout<<endl;

        switch(op){
        case 1:
            {
                // Mostrar las rutas
                cout<<"----------Ruta de camiones----------"<<endl<<endl;
                cout<<graph.printAdjList()<<endl<<endl;
                cout<<"Desea imprimir las rutas?\n";
                cout<<"1- Si\n2- No\n";
                cin>>resp;
                if(resp==1){
                    ofstream escribe ("Ruta de camiones.txt");
                    escribe<<graph.printAdjList();
                    cout<<"Se han guardado las rutas en el archivo Ruta de camiones.txt\n\n";
                }
            }
            break;
        case 2:
            {
                // Camino de un punto a otro
                cout<<"----------Camino de un punto a otro----------\n\n";
                cout<<"0 Queretaro\n";
                cout<<"1 Zacatecas\n";
                cout<<"2 Aguascalientes\n";
                cout<<"3 San Luis Potosi\n";
                cout<<"4 CDMX\n";
                cout<<"5 Hidalgo\n\n";
                cout<<"Punto de partida: ";
                cin>>partida;
                cout<<"Punto de llegada: ";
                cin>>llegada;
                cout<<graph.DFS(partida,llegada);
                cout<<endl<<endl;
            }
            break;
        case 3:
            {
                // Camino de un punto a otro mas rapido
                cout<<"----------Camino de un punto a otro mas rapido----------\n\n";
                cout<<"0 Queretaro\n";
                cout<<"1 Zacatecas\n";
                cout<<"2 Aguascalientes\n";
                cout<<"3 San Luis Potosi\n";
                cout<<"4 CDMX\n";
                cout<<"5 Hidalgo\n\n";
                cout<<"Punto de partida: ";
                cin>>partida;
                cout<<"Punto de llegada: ";
                cin>>llegada;
                cout<<graph.BFS(partida,llegada);
                cout<<endl<<endl;
            }
            break;
        case 4:
            {
                // Salida del programa
                cout<<"Ha salido del menu"<<endl;
                salida=true;
            }
            break;
        default:
            {
                cout<<"Opcion invalida, intente de nuevo"<<endl;
            }
            break;
        }
    }
}
