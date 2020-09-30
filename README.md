# Programación y Algoritmos
## Tarea 08 -- Montículos ternarios

**Nota 1:** Esta tarea es *colaborativa* (en pares y con un repositorio git). Un medio punto
se atribuirá en función del buen uso de git entre ambos participantes (contribuciones equilibradas y revisiones
de uno para el otro). 

**Nota 2:** Se atribuirá otro medio punto en la elaboración de tests (por ejemplo con las funciones *assert*); 
la idea es que cada uno en el euqipo pruebe (con tests) la robustez del código del otro.

En la clase, vimos la estructura de montículo binario. Nos permite, entre otras aplicaciones, 
implementar de forma eficiente colas de prioridad o ordenar datos. 
En esta tarea, nos vamos a enfocar en una estructura
muy similar, el montículo ternario. Como su nombre lo indica, se trata de una estructura basada en un
árbol ternario, en lugar de binario. Significa que cada nodo de este árbol (excepto para los nodos hojas)
tiene exactamente tres hijos.
Un montículo ternario cumple con las propriedades de los montículos: 
* el árbol ternario correspondiente está casi completo
* las raíces de cualquier sub-árbol contienen una llave superior a todas las de los otros
nodos del sub-´arbol. 

En la figura siguiente, damos un ejemplo de montículo ternario.

Es interesante observar que, de manera similar a lo que vimos en la clase con montículos binarios, se
puede implementar esta estructura con un arreglo, guardando los datos nivel por nivel. Con el primer
dato en el índice 0, se puede mostrar que los tres hijos del nodo ubicado en el índex k se encuentran en
los índices 3k + 1, 3k + 2, 3k + 3; similarmente, el padre del nodo de índex k se encuentra en el índex
(k − 1)/3.

### Implementación del montículo ternario 

Para la implementación del montículo ternario, se tomará como modelo la implementación del montículo 
binario y se realizará la implementación de la estructura `Theap` de las siguientes funciones: 


```c
void insert(THeap *h, int data);
int removeMax(THeap *h);
int getMax(THeap *h);

void bottomUpHeapify(int *arr, int k);
void topDownHeapify(int * arr, int k, int n);
```

#### Pregunta 01 (3 pts)
  Implementar el montículo ternario como se sugirió arriba.
#### Pregunta 02 (1 pts)
  Hacer un análsis de complejidad de los métodos desarrollados (puede venir este análsisi como 
  comentario en el código). Comparar en particular el desempeño contra el montículo binario. 

### Aplicación al cálculo de la mediana en streaming

En esta aplicación de los montículos, usaremos la estructura desarrollada en la pregunta anterior para
determinar el valor mediano de datos llegando como flujo (pensar en datos llegando a través de un medio de 
comunicación). Cuando el número de datos es impar, tomaremos el único dato que separa el conjunto en dos 
partes iguales, y cuando es par, tomaremos el promedio delos dos elementos centrales. 

Imaginar por ejemplo el flujo siguiente: 

```
1       #=> 1
1 4     #=> 2.5
1 4 6   #=> 4
1 4 6 3 #=> 3
```

Queremos un algoritmo que permita actualizar de manera eficiente el valor mediano, mientras llegan datos
nuevos, sin "re-empezar el trabajo" desde cero cada vez, aprovechando que los datos van llegando uno 
a uno. 

Para eso creamos **dos** montículos: Un montículo-max y un montículo-min. El primero guardará la mitad inferior
de los datos vistos hasta ahora (los elementos más chicos), mientras el segundo guardará la mitad 
superior (los elementos más grandes). Asegurar que la diferencia de tamaño entre los dos montículos es a lo más
uno. Guardar tambien el valor actual de la mediana inicializada a 0. 

La actialización de la mediana se hará como sigue:

* Si el montículo-max tiene más elementos que el montículo-min: si el nuevo dato leído es inferior al mediano 
actual, quitar el elemento máximo del montículo-max, pasarle al montículo-min e insertar el nuevo dato en el 
montículo-max; si el nuevo dato es superior al mediano actual, insertarlo en el montículo-min. La mediana es 
el promedio entre el max y el min. 

* Si el montículo-max tiene menos elementos que el montículo-min: si el nuevo dato leído es superior al mediano
actual, quitar el elemento mínimo del montículo-min, pasarle al montículo-max e insertar el nuevo dato en el 
montículo-min; si el nuevo dato es inferior al mediano actual, insertarlo en el montículo-max. El mediano es 
el promedio entre el max y el min. 

* Si los dos montículos tienen el mismo tamaño: si el nuevo dato es inferior al mediano actual, ponerlo en 
el montículo-max y el nuevo mediano será el max; si el nuevo dato es superior al mediano actual, ponerlo en el
montículo mín y el nuevo mediano será el min. 


#### Pregunta 03 (3pts)
Implementar el algoritmo de cálculo del valor mediano

#### Pregunta 04 (1pts)
Demostrar que el algoritmo propuesto calcula bien el valor mediano

#### Pregunta 05 (1pts)
Hacer un análisi de complejidad del algoritmo (puede venir este análisis como comentario en el código). 

