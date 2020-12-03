#ifndef RSORT_H_INCLUDED
#define RSORT_H_INCLUDED

#include<iostream>
#include<list>
#include<cmath>

using namespace std;

class Rsort {
    private:
    int i, j, m, p = 1, index, temp, count = 0;
    list<int> pocket[10]; //arreglo auxiliar, respresenta del 0 a 9 las unidades

    public:
    Rsort(){}
    void display(int *array, int size);
    void radixSort(int *arr, int n, int max);
};

// Imprime el arreglo
void Rsort::display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}

// Realiza el ordenamiento
void Rsort::radixSort(int *arr, int n, int max) {
   for(i = 0; i< max; i++) {
      m = pow(10, i+1); // Se utiliza para sacar el módulo
      p = pow(10, i);   // Se utiliza para el índice
      for(j = 0; j<n; j++) {
         temp = arr[j]%m;
         index = temp/p;      //Encuentra el ínidice para el arreglo auxiliar pocket donde se ordenan los valores
         pocket[index].push_back(arr[j]);
      }
      count = 0;
      for(j = 0; j<10; j++) {
         // Reorganiza el arreglo y limpia el auxiliar
         while(!pocket[j].empty()) {
            arr[count] = *(pocket[j].begin());
            pocket[j].erase(pocket[j].begin());
            count++;
         }
      }
   }
}

#endif // RSORT_H_INCLUDED
