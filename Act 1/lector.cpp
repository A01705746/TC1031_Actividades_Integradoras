#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include "sorts.h"
using namespace std;

int main(){
    //reading from a text file
    Sorts<int> sorts;
    int roll2, contar = 0,i=0, op, temp,lim=0;
    string line, word, song, song2; // variable vacía de texto
    vector <string> row;
    vector <string> ordenado;
    vector <int> duracion;
    vector<int> v;

    cout<<"----------Biblioteca de musica----------"<<endl;
    cout<<endl;
    cout<<"Cancion     |     Album     |     Artista     |     Duracion(s)"<<endl;
    ifstream lee ("Musica.csv");
    if (lee.is_open()){
        while(getline(lee,line)){
            row.clear();
            cout<<line<<"\n";
            stringstream s(line);
            while(getline(s,word,',')){
                row.push_back(word);
            }
            roll2 = std::stoi(row[3]);
            duracion.push_back(roll2);
            i++;
        }
        cout<<endl;
        bool salida=false;
        while(salida==false){
            temp=i;
            contar=i;
            cout<<"Seleccionar una opcion:\n";
            cout<<"1) Ordenar por duracion\n";
            cout<<"2) Buscar una cancion\n";
            cout<<"3) Salir\n";
            cin>>op;
            cout<<endl;

            switch(op){
            case 1:
                {
                    ofstream escribe ("lista ordenada.txt");
                    v=sorts.mergeSort(duracion);
                    for(temp=temp-1;temp>=0;temp--){
                        escribe<<v[temp]<<"\n";
                    }
                    for(contar=contar-1;contar>=0;contar--){
                        cout<<v[contar]<<"\n";
                    }
                    cout<<"Se ha guardado el archivo con el nombre lista ordenada.txt"<<endl<<endl;
                }
                break;
            case 2:
                {
                    ifstream lee2 ("Musica.csv");
                    cout<< "Introducir nombre de cancion ";
                    cin >> song;
                    while(getline(lee2,line)){
                        row.clear();
                        stringstream s(line);
                        while(getline(s,word,',')){
                            row.push_back(word);
                        }
                        song2 = row[0];
                        if (song2 == song) {
                            lim = 1;
                            cout << "Cancion: " << row[0] << "\n";
                            cout << "Album: " << row[1] << "\n";
                            cout << "Artista: " << row[2] << "\n";
                            cout << "Duracion(s): " << row[3] << "\n"<<endl;
                            break;
                        }
                    }
                    if (lim == 0)
                        cout << "Cancion no encontrada\n"<<endl;
                    lee.close();
                }
                break;
            case 3:
                {
                    cout<<"Ha salido de la biblioteca"<<endl;
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

        lee.close();
    }
    else
        cout << "Unable to open file";

    return 0;
}
