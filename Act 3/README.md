# Actividad integradora 3
El programa consiste en una biblioteca de música extraída de una archivo de texto separado por comas que en un principio se te presenta con cada fila con el nombre de la canción, su álbum, artista y duración en segundos, todo esto en forma desordenada. El usuario tiene 6 opciones: buscar una canción para saber sus detalles individuales, organizar en forma descendente y ascendente la duración de las canciones (unicamente esta característica) en un nuevo archivo de texto, buscar por rangos de duración (unicamente esta característica), agregar una nueva canción a la biblioteca mediante una lista ligada o salir del programa.

# Correcciones
Se tomó en cuenta la retroalimentación de la primera entrega y fue comentado buena parte del código para clarificar el método de trabajo, igualmente se añadió un archivo main que muestra cómo debe funcionar el programa idealmente llamado "casos de prueba.cpp", el main para el uso del usuario sigue siendo "lector.cpp".

# Análisis de complejidad
Para el ordenamiento de la duración se utilizó el algoritmo Merge, siendo la entrada un vector de enteros con n números. Se tiene que recorrer los n elementos del arreglo, toma una forma de log n al ordenar las particiones, cada dos divisiones hay un ordenamiento, su complejidad sería O(n log n) para el peor de los casos.

En cuanto a la búsqueda de la canción sería O(n^2) ya que tiene dos ciclos, uno para cada línea y otro para cada elemento de la línea, de manera que pueda encontrar la columna indicada para comparar.

Al momento de agregar una nueva canción se trabaja con listas ligadas mediante la función add, que inserta un elemento al final de la lista, ya que necseita recorrer toda la lista hasta llegar a la posición deseada y añadir el elemento cuenta con una complejidad O(n).

Para el ordenamiento ascendente se utilizó un Splay tree. Para añadir cada duración se empleó la función add, la función compara los valores por ramas para revisar donde entra el nuevo valor, una vez llega a la posición deseada se inserta el dato y realiza las operacione de balance splay, no recorre todo el árbol por lo que su complejidad sería O(log n). Una vez hecho eso se da la opción de visualizar el árbol para corroborar su funcionamiento mediante preorder y print_tree, los cuales serían complejidad O(n) pues recorren el árbol entero.

# Consideraciones
- Debido a las funciones utilizadas es necesario utilizar C++ 11 en el compilador para el correcto funcionamiento del programa
- Para que el programa funcione de manera correcta es necesario que se descargue de igual manera el archivo de expeciones de la misma carpeta
- El programa generará un archivo de texto no presente en el repositorio
- Para el caso de añadir y buscar una canción se pide que el apartado de duración sea estrictamente usado un número entero para que no se loopee el programa
