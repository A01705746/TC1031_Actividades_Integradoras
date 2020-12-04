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
            temp=i;
            contar=i;
            cout<<"Seleccionar una opcion:\n";
            cout<<"1) Ordenar por duracion\n";
            cout<<"2) Buscar una cancion\n";
            cout<<"3) Salir\n";
            cout<<endl;

            cout<<"------------------------1---------------------------\n";
            // Ordenamiento de los datos de duración por método merge
            ofstream escribe ("lista ordenada.txt");
            v=sorts.mergeSort(duracion);

            // Escritura del vector ordenado en un nuevo archivo
            for(temp=temp-1;temp>=0;temp--){
                escribe<<v[temp]<<"\n";
            }

            // Despliegue de datos en consola
            for(contar=contar-1;contar>=0;contar--){
                cout<<v[contar]<<"\n";
            }
            cout<<endl<<"Se ha guardado el archivo con el nombre lista ordenada.txt"<<endl<<endl;

            cout<<"------------------------2---------------------------\n";
            // Busqueda de cancion individual, despliega su información general
            ifstream lee2 ("Musica.csv");
            cout<< "Introducir nombre de cancion "<<endl;
            song="Warriors";
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

            cout<<"------------------------3---------------------------\n";
            // Salida del programa
            cout<<"Ha salido de la biblioteca"<<endl;

        lee.close();
    }
    else
        cout << "Unable to open file";

    return 0;
}
