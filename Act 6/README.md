# Actividad integradora 6: Estructura Nueva
# Radix Sort
La entrega se hace únicamente para la estructura extra. EL programa consiste en una demostración del uso del Radix Sort. Cuenta con 4 opciones, la prueba manual de la estructura, la lectura de un archivo para ordenarlo, visualizar casos de prueba y salir del programa.

# ¿Para qué sirve?
Se utiliza para ordenar un conjunto de valores de enteros, es eficiente de usar cuando el número de dígitos de los valores no es demasiado grande.

# ¿Cómo se usa?
El rdenamiento se basa en los valores de los dígitos en las representaciones de posiciones de los numeros que se ordenan, es decir, divide cada valor en decenas, centenas, millares, etc para procesarlos de forma individual. Se empieza a ordenar a partir del dígito menos significativo al más significativo. El radix es la base del sistema numérico, en el sistema decimal la base es 10, entonces para su funcionamiento se utiliza un arreglo auxiliar de 10 elementos para guardar los dígitos.

# Ejemplos
Se pude utilizar para básicamente cualquier problemática que involucre ordenamiento de números, siempre y cuando no sean demasiado grandes, por lo que en la vida real puede entrar perfectamente para ordenamiento de fechas de nacimiento, temperaturas, medidas y ordenamiento de datos binarios.

# Análisis de complejidad
El algoritmo divide por dígitos cada valor desde el menos hasta el más significativo, por cada dígito va guardando el valor en un arreglo auxiliar, una vez que termine el ciclo de ese dígito pasa al siguiente y mueve los los elementos del arreglo auxiliar al originial, limpia el auxiliar y repite el proceso.
Contamos con dos ciclos for, uno que se recorre m veces por cada dígito y otro que se recorre k veces, que son la cantidad de elementos. Por lo tanto su complejidad sería O(nk).

# Consideraciones
-No utlizar el valor de 999 en la entrada manual

# Fuentes
http://ict.udlap.mx/people/ingrid/Clases/IS211/Radix.html

https://es.wikipedia.org/wiki/Ordenamiento_Radix

https://www.tutorialspoint.com/cplusplus-program-to-implement-radix-sort
