#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

class Graph {
	private:
	vector<vector<int>> adj_list;
	int nu_vertices;
	int nu_edges;
	string ruta[6]={"Queretaro", "Zacatecas", "Aguascalientes", "San Luis Potosi", "CDMX", "Hidalgo"};

	public:
	Graph(){}
    string print_vector(vector<int> vec);

	void loadGraphList(string filename, int vertices, int edges); // Cargar elementos a la lista de adyacencia

	string printAdjList(); // Impresión de la lista

	string DFS(int init_vertex, int target_vertex); // Algoritmos de búsqueda
	string BFS(int init_vertex, int target_vertex);
};

string Graph:: print_vector(vector<int> vec){
	string result = "";
	for (int i=0; i<vec.size(); i++){
		result = result + ruta[(vec[i])] + ", ";
	}
	return result;
}

void Graph::loadGraphList(string filename, int vertices, int edges){
	nu_vertices = vertices;
	nu_edges = edges;

	for (int i=0; i<vertices; i++){     // Creación de la lista de adyacencia
		vector<int> row;
		adj_list.push_back(row);
	}

	ifstream file;                      // Lectura de archivo
	file.open(filename);
	while(file.good()){
		string init_vertex;
		string end_vertex;
		getline(file, init_vertex, ',');
		getline(file, end_vertex, '\n');
		init_vertex = init_vertex.substr(1, init_vertex.length()-1);
		end_vertex = end_vertex.substr(1, end_vertex.length()-2);
		int init_node = stoi(init_vertex);
		int end_node = stoi(end_vertex);

		adj_list[init_node].push_back(end_node); // Llenado del grafo
		adj_list[end_node].push_back(init_node);
	}
}

string Graph::printAdjList(){
	string result = "";
	for(int i=0; i<adj_list.size(); i++){
		result += ruta[i] + " llega a: ";
		sort(adj_list[i].begin(), adj_list[i].end());
		for(int j=0; j<adj_list[i].size(); j++){
			result += ruta[(adj_list[i][j])] + ", ";
		}
		result += "\n";
	}
	return result;
}


string Graph::DFS(int init_vertex, int target_vertex){

	vector<vector<int>> adj_list_copy;          // Copia de la lista de adyacencia
	for (int i=0; i<adj_list.size(); i++){
		adj_list_copy.push_back(adj_list[i]);
	}

	vector<int> stack;
	vector<int> visited;
	bool found = false;
	int current = init_vertex;

	while (!found && !(visited.size() >= nu_vertices)){

		bool already_visited = false;           // Revisar que el nodo actual haya sido visitado
		for (int i=0; i<visited.size(); i++){
			if(current == visited[i]) {
				already_visited = true;
				break;
			}
		}

		// Añadir a los visitados
		if (!already_visited) visited.push_back(current);

		// En caso de que el nodo actual sea el objetivo
		if (current == target_vertex){
			found = true;
			break;
		}

		// Borrar los nodos visitados
		for (int i=0; i<adj_list_copy[current].size(); i++){
			for (int j=0; j<visited.size(); j++){
				if(adj_list_copy[current][i] == visited[j])
					adj_list_copy[current].erase(adj_list_copy[current].begin()+i);
			}
		}
		if (adj_list_copy[current].size() > 0){
			stack.push_back(current);
			// Hijo del nodo actual
			int temp_index = current;
			current = adj_list_copy[current].back();
			adj_list_copy[temp_index].pop_back();
		}
		else {
			// En caso de topar con pared
			current = stack[stack.size()-1];
			stack.pop_back();
		}
	}
	// Añade el nodo actual para terminar el camino
	stack.push_back(current);

	// Convertir la lista en string
	string visited_str = print_vector(visited);
	string path_str = print_vector(stack);
	string result = "visited: " + visited_str + "\n" + "path: " + path_str;
	result = result.substr(0, result.size()-1);
	return result;
}


string Graph::BFS(int init_vertex, int target_vertex){
	vector<vector<int>> queue;
	vector<vector<int>> visited;
	int current = init_vertex;
	int parent = -1;
	bool found = false;

	while (true){
		// Añadir a visitados
		visited.push_back(vector<int>({parent, current}));

		// Revisar si es el nodo objetivo
		if (current == target_vertex){
			found = true;
			break;
		}

		// En caso de que no estén visitados enviarlos a la cola
		for (int i=0; i<adj_list[current].size(); i++){
			int val = adj_list[current][i];
			bool already_visited = false;
			for (int j=0; j<visited.size(); j++){
				if (visited[j][1] == val){
					already_visited = true;
					break;
				}
			}
			if (!already_visited) queue.push_back(vector<int>({current, val}));
		}
		// Tomar nodos de la cola
		parent = queue[0][0];
		current = queue[0][1];
		queue.erase(queue.begin());
	}
	// Encontrar el camino
	vector<int> path;
	int find = target_vertex;
	do {
		for (int i=0; i<visited.size(); i++){
			if (visited[i][1] == find){
				path.insert(path.begin(), find);
				find = visited[i][0];
			}
		}
	} while (find != -1);
	// Juntar nodos en un mismo arreglo
	vector<int> converted_visited;
	for (int i=0; i<visited.size(); i++){
		converted_visited.push_back(visited[i][1]);
	}

	// Convertir lista a string
	string visited_str = print_vector(converted_visited);
	string path_str = print_vector(path);
	string result = "visited: " + visited_str + "\n" + "path: " + path_str;
	result = result.substr(0, result.size()-1);
	return result;
}
