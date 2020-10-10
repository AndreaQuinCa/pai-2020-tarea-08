#ifndef HEAP_T08
#define HEAP_T08
#include <stdio.h>
#include <stdlib.h>
// Prototipos =================================================================

typedef struct _THeap{
  int capacity;
  int size;
  int *data;
}THeap;

THeap * THeap_new(int capacity);
void    swap(int *arr, int i, int j);
void    free_THeap(THeap ** hptr);

void    insert(THeap *h, int data);
int     removeMax(THeap *h);
int     getMax(THeap *h);

void    bottomUpHeapify(int *arr, int k);
void    topDownHeapify(int * arr, int k, int n);

// Definiciones ===============================================================

void insert(THeap *h, int data){ 
  return;
} 

int removeMax(THeap *h){ 
  if (h->size == 0) {
    printf("Heap vacío.");
    return -1;
  }
  int tmp = h->data[0];
  h->data[0] = h->data[h->size--];
  topDownHeapify(h->data, 0, h->size);
  return tmp;
} 

int getMax(THeap *h){ 
  if (h->size == 0){
    printf("Heap vacío.\n");
    return 0;
  }
  int max = h->data[1];
  return max;
} 

void bottomUpHeapify(int *arr, int k){ 
  return;
} 

void topDownHeapify(int * arr, int k, int n){ 
  while (3*k < n){
    int j = 3*k+1;                            // Busco primer hijo
    if (j < n && arr[j] < arr[j+1]) {         // Si arr[j] < arr[j+1] ...
      j++;
      if (j < n && arr[j] < arr[j+1]) j++;    // Si arr[j] < arr[j+1] < arr[j+2]
    }
    else{                                     // arr[j] > arr[j+1]
      if (j+1 < n && arr[j] < arr[j+2]) j += 2;// arr[j] > arr[j+1] y arr[j] < arr[j+2]
    }                               
    // Si no se cumple lo anterior, hijo maximo esta en primer hijo
    if (arr[k]>= arr[j]) break;
    swap(arr, k, j);
    k = j;
  }
} 

THeap * THeap_new(int capacity){
  // Alocacion de memoria
  THeap *heap = (THeap *) calloc (1,sizeof(THeap));
  if (heap == NULL) {
    printf("No se alocó memoria para heap.\n");
    exit(-1);
  }

  heap->capacity = capacity;
  heap->size = 0;
  heap->data = (int *) calloc (capacity, sizeof(int));
  if (heap->data == NULL) {
    printf("No se alocó memoria para heap.\n");
    exit(-1);
    }

  return heap;
}

void swap(int *arr, int i, int j){
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

void showHead(THeap *h){
  for (int i = 0; i < h->size; i++){
    printf("%i\n",h->data[i]);
  }
}

void free_THeap(THeap ** hptr){
  free((*hptr)->data);
  free(*hptr);
  hptr = NULL;
}

#endif
