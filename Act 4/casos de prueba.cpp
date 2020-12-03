/*
*   Rutas de autobus - casos de prueba
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
    int partida, llegada, resp;
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

        cout<<"Seleccionar una opcion:\n";
        cout<<"1) Mostrar rutas\n";
        cout<<"2) Mostrar camino de un punto a otro\n";
        cout<<"3) Mostrar camino mas corto de un punto a otro\n";
        cout<<"4) Salir\n";
        cout<<endl;

        // Mostrar las rutas
        cout<<"----------Ruta de camiones----------"<<endl<<endl;
        cout<<graph.printAdjList()<<endl<<endl;
        cout<<"Desea imprimir las rutas?\n";
        cout<<"1- Si\n2- No\n";
        cout<<"1\n";
        ofstream escribe ("Ruta de camiones.txt");
        escribe<<graph.printAdjList();
        cout<<"Se han guardado las rutas en el archivo Ruta de camiones.txt\n\n";

        // Camino de un punto a otro
        cout<<"----------Camino de un punto a otro----------\n\n";
        cout<<"0 Queretaro\n";
        cout<<"1 Zacatecas\n";
        cout<<"2 Aguascalientes\n";
        cout<<"3 San Luis Potosi\n";
        cout<<"4 CDMX\n";
        cout<<"5 Hidalgo\n\n";
        cout<<"Punto de partida: ";
        partida=0;
        cout<<"0 \n";
        cout<<"Punto de llegada: ";
        llegada=1;
        cout<<"1 \n";
        cout<<graph.DFS(partida,llegada);
        cout<<endl<<endl;

        // Camino de un punto a otro mas rapido
        cout<<"----------Camino de un punto a otro mas rapido----------\n\n";
        cout<<"0 Queretaro\n";
        cout<<"1 Zacatecas\n";
        cout<<"2 Aguascalientes\n";
        cout<<"3 San Luis Potosi\n";
        cout<<"4 CDMX\n";
        cout<<"5 Hidalgo\n\n";
        cout<<"Punto de partida: ";
        partida=0;
        cout<<"0 \n";
        cout<<"Punto de llegada: ";
        llegada=1;
        cout<<"1 \n";
        cout<<graph.BFS(partida,llegada);
        cout<<endl<<endl;

        // Salida del programa
        cout<<"Ha salido del menu"<<endl;


}
