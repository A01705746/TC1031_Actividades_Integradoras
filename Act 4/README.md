# Actividad integradora 4
Esta entrega es para demostrar únicamente la parte de grafos. Consiste en una central de autobuses que te permite ir a distintos estados de la república, 5 de ellos en particular. Se le presenta al usuario 4 opciones, mostrar las rutas de todos los camiones y guardarlas en un archivo, mostrar el camino de un punto a otro, mostrar el camino más corto de un punto a otro y salir de la aplicación.
Cuenta con un archivo de texto para la lectura de los grafos, el main para el usuario y un main de casos de prueba que muestra el funcionamiento ideal del programa.

# Consideraciones
- Para que el programa funcione es necesario tener los archivos del repositorio
- La entradas de datos de usuario son únicamente numéricas

# Análisis de complejidad
# loadGraphList
En nuestro caso los autobuses pueden ir de ida y de regreso, por lo que su representación sería un grafo no dirigido, entonces tomaría n vertices más 2a arcos, por lo mismo que no es dirigido, dicho eso podemos concluir que su complejidad es O(n+2a) para el peor de los casos.

# printAdjList
Puesto que tenemos que recorrer la lista, la cual es un conjunto de vectores anidados serán necesarios dos ciclos de recorrido, por lo que su complejidad sería O(n^2).

# DFS
Ya que tenemos que almacenar los nodos visitados y el camino recorrido, navegando los puntos hasta topar con pared y repetir para llegar a nuestra meta, su complejidad sería O(n+a), teniendo en cuenta los nodos y arcos que necesita recorrer.

# BFS
Si bien el comportamiento es distinto al DFS, y en este ahora es navegar por amplitud en vez de profundidad, el camino que deben recorrer es el mismo, tomando en cuenta nuevamente los nodos y arcos disponibles, por lo que su complejidad de igual manera es O(n+a).
