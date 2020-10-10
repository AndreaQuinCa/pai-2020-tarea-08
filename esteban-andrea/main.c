#include<stdio.h>
#include<stdlib.h>
#include "./heap.c"
#include "./median.c"

// Función principal, recibe de STDIN un stream de datos e imprime a STDOUT
// la mediana.

//prueba
int main(int num_args, char ** args){
  THeap *heap_esteban;
  heap_esteban = THeap_new(10);
  printf("Capacity: %i\nSize: %i\n", heap_esteban->capacity, heap_esteban->size);
  return 0;
}
