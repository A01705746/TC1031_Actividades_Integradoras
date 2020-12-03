/*
*   Estructura extra
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
#include "rsort.h"

using namespace std;

string ToString(int *array) {
	stringstream aux;
	for (int h = 0; h < 10; h++) {
		aux << array[h] << ",";
	}
	return aux.str();
}

int main() {
    Rsort redix;
    int op;
    bool salida=false;
    cout<<"----------Redix Sort----------"<<endl;
    cout<<endl;

    while(salida==false){
        cout<<"Seleccionar una opcion:\n";
        cout<<"1) Prueba manual\n";
        cout<<"2) Lectura de archivo\n";
        cout<<"3) Casos de prueba\n";
        cout<<"4) Salir\n";
        cin>>op;
        cout<<endl;

        switch(op){
        case 1:
            {
                // Prueba manual
                cout<<"----------Prueba manual----------"<<endl;
                int n, max;
                cout << "Numero de elementos en el arreglo: ";
                cin >> n;
                cout << "Digitos maximos en los elementos: ";
                cin >> max;
                int arr[n]; //crea el arreglo con el numero de elementos
                cout << "Introduzca los elementos:" << endl;
                for(int i = 0; i<n; i++) {
                        cin >> arr[i];
                }
                cout << "Datos desordenados: ";
                redix.display(arr, n);
                redix.radixSort(arr, n, max);
                cout << "Datos ordenados: ";
                redix.display(arr, n);
                cout<<endl;
            }
            break;
        case 2:
            {
                // Lectura de archivo
                cout<<"----------Lectura de archivo----------"<<endl;
                ifstream lee("Prueba.csv");
                string line, p1[10], r;
                int p2[10],j, val;
                while(getline(lee,line)){
                    stringstream s(line);
                    for(j=0 ; j<10 ; j++){
                        getline(s,p1[j],',');
                        val=stoi(p1[j]);
                        p2[j]=val;
                    }
                }
                lee.close();
                cout << "Datos desordenados: ";
                redix.display(p2, 10);
                redix.radixSort(p2, 10, 4);
                cout << "Datos ordenados: ";
                redix.display(p2, 10);
                ofstream escribe ("Prueba ordenada.txt");
                for(j=0 ; j<10 ; j++){
                    escribe<<p2[j]<<',';
                }
                cout<<endl<<"Se ha guardado el archivo con el nombre Prueba ordenada.txt"<<endl<<endl;
            }
            break;
        case 3:
            {
                // Casos de prueba
                cout<<"----------Casos de prueba----------"<<endl;
                string ans1="2,24,54,120,253,365,484,543,661,870,";
                string ans2="3,8,31,67,74,78,80,87,94,98,";
                string ans3="1,111,222,333,444,555,666,777,888,900,";
                string ans4="1,1,1,2,2,2,3,3,3,4,";
                string ans5="0,1,2,3,4,5,6,7,8,9,";
                int m = 10;
                int t1[]={484,120,543,253,2,870,24,661,54,365};
                int t2[]={98,31,74,94,3,87,8,67,78,80};
                int t3[]={444,111,888,1,900,333,777,555,222,666};
                int t4[]={4,3,1,2,3,1,2,1,3,2};
                int t5[]={5,8,6,1,3,9,0,2,4,7};

                redix.radixSort(t1, m, 3);
                ToString(t1);
                cout << " 1 " << (!ans1.compare(ToString(t1)) ? "success\n" : "fail\n");
                redix.radixSort(t2, m, 2);
                cout << " 2 " << (!ans1.compare(ToString(t1)) ? "success\n" : "fail\n");
                redix.radixSort(t3, m, 3);
                cout << " 3 " << (!ans1.compare(ToString(t1)) ? "success\n" : "fail\n");
                redix.radixSort(t4, m, 1);
                cout << " 4 " << (!ans1.compare(ToString(t1)) ? "success\n" : "fail\n");
                redix.radixSort(t5, m, 1);
                cout << " 5 " << (!ans1.compare(ToString(t1)) ? "success\n" : "fail\n");
                cout<<endl;
            }
            break;
        case 4:
            {
                // Salida del programa
                cout<<"Ha salido del programa"<<endl;
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
