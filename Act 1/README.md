# Actividad integradora 1
El programa consiste en una biblioteca de música extraída de una archivo de texto separado por comas que en un principio se te presenta con cada fila con el nombre de la canción, su álbum, artista y duración en segundos, todo esto en forma desordenada. El usuario tiene 3 opciones, buscar una canción para saber sus detalles individuales, organizar en forma descendente la duración de las canciones (unicamente esta característica) en un nuevo archivo de texto o salir del programa.

# Análisis de complejidad
Para el ordenamiento de la duración se utilizó el algoritmo Merge, siendo la entrada un vector de enteros con n números. Se tiene que recorrer los n elementos del arreglo, toma una forma de log n al ordenar las particiones, cada dos divisiones hay un ordenamiento, su complejidad sería O(n log n) para el peor de los casos.

En cuanto a la búsqueda de la canción sería O(n^2) ya que tiene dos ciclos, uno para cada línea y otro para cada elemento de la línea, de manera que pueda encontrar la columna indicada para comparar.

# Consideraciones
Debido a las funciones utilizadas es necesario utilizar C++ 11 en el compilador para el correcto funcionamiento del programa.
