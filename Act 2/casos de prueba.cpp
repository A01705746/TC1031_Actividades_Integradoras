/*
*   Casos de prueba en main
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
#include "sorts.h"
#include "list.h"
using namespace std;

int main(){
    // Objetos para clases
    Sorts<int> sorts;
    List<string> can;
    List<string> alb;
    List<string> art;
    List<int> dur;

    // Declaración de variables
    int roll2, contar = 0,i=0, op, temp, lim=0, j=0;
    string line, word, song, song2; // variable vacía de texto
    string d0,d1,d2;
    vector <string> row;
    vector <string> cancion;
    vector <string> album;
    vector <string> artista;
    vector <int> duracion;
    vector<int> v;

    cout<<"----------Biblioteca de musica----------"<<endl;
    cout<<endl;
    cout<<"Cancion     |     Album     |     Artista     |     Duracion(s)"<<endl;
    ifstream lee ("Musica.csv");    // Lectura de archivo separado por comas
    if (lee.is_open()){
            // Se lee cada línea individualmente y se imprime en pantalla,
            // cada elemento de la línea es separado y almacenado en
            // el vector temporal row para posteriormente almacenar todos
            // en su vector correspondiente e igualmente a una lista ligada simple
        while(getline(lee,line)){
            row.clear();
            cout<<line<<"\n";
            stringstream s(line);
            while(getline(s,word,',')){
                row.push_back(word);
            }
            // Añade elementos a los vectores correspondientes
            cancion.push_back(row[0]);
            album.push_back(row[1]);
            artista.push_back(row[2]);
            roll2 = std::stoi(row[3]);
            duracion.push_back(roll2);

            d0=row[0];
            d1=row[1];
            d2=row[2];

            // Adición de elementos a lista ligada
            can.add(d0);
            alb.add(d1);
            art.add(d2);
            dur.add(roll2);
            i++;
        }
        cout<<endl;
            temp=i;
            contar=i;
            cout<<"Seleccionar una opcion:\n";
            cout<<"1) Ordenar por duracion\n";
            cout<<"2) Buscar una cancion\n";
            cout<<"3) Buscar por rango de duracion\n";
            cout<<"4) Agregar Cancion\n";
            cout<<"5) Salir\n";
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
            // Busqueda por rangos de la duración mediante busqueda bianria
            int ini, fin;
            ini=176;
            fin=228;
            cout<<"Rango de inicio: "<<ini<<endl;
            ini=sorts.busqBinaria(v,ini);
            cout<<"Rango de fin: "<<fin<<endl;
            fin=sorts.busqBinaria(v,fin);

            for(j=ini; j<=fin; j++){
                cout<<v[j]<<"\n";
            }
            cout<<endl;

            cout<<"------------------------4---------------------------\n";
            // añade una canción con sus características a su lista correspondiente
            // y es desplegada
            string canc, albu, arti;
            int dura;

            cout<<"Cancion"<<endl;
            canc="EJEMPLO";
            can.add(canc); // Añade característica especificada a la lista relacionada
            cout<<"Album:"<<endl;
            albu="EJEMPLO";
            alb.add(albu);
            cout<<"Artista:"<<endl;
            arti="EJEMPLO";
            art.add(arti);
            cout<<"Duracion:"<<endl;
            dura=00000;
            dur.add(dura);

            cout<<can.toString(); // Convierte la lista en un string imprimible
            cout<<endl;
            cout<<endl;
            cout<<alb.toString();
            cout<<endl;
            cout<<endl;
            cout<<art.toString();
            cout<<endl;
            cout<<endl;
            cout<<dur.toString();
            cout<<endl;
            cout<<endl;

            cout<<"------------------------5---------------------------\n";
            // Salida del programa
            cout<<"Ha salido de la biblioteca"<<endl;

        lee.close();
    }
    else
        cout << "Unable to open file";

    return 0;
}
