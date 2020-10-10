#ifndef HEAP_T08
#define HEAP_T08

// Prototipos =================================================================

typedef struct _THeap{
  int capacity;
  int size;
  int *data;
}THeap;

THeap * THeap_new(void);
void    swap(int *arr, int i, int j){
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
  if (h->size < 1) return -1;
  int tmp = h->data[1];
  h->data[1] = h->data[h->size--];
  topDownHeapify(h->data, 1, h->size);
} 

int getMax(THeap *h){ 
  if (h->size == 0){
    printf("Heap vacío.\n");
    return 0;
  }
  int max = 0;
    max = h->data[1];
  }
  return max;
} 

void bottomUpHeapify(int *arr, int k){ 
  return;
} 

void topDownHeapify(int * arr, int k, int n){ 
  while (3*k <= n){
    int j = 3*k;                              // Busco primer hijo
    if (j < n && arr[j] < arr[j+1]) {         // Si arr[j] < arr[j+1] ...
      j++;
      if (j < n && arr[j] < arr[j+1]) j++;    // Si arr[j] < arr[j+1] < arr[j+2]
    }
    else{                                     // arr[j] > arr[j+1]
      if (j+1 < n && arr[j] < arr[j+2] j += 2;// arr[j] > arr[j+1] y arr[j] < arr[j+2]
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
  heap->capacity = capacity;
  heap->data = (int *) calloc (capacity, sizeof(int ));
  return heap;
}

void swap(int *arr, int i, int j){
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

void free_THeap(THeap ** hptr){
  free((*hptr)->data);
  free(*hptr);
}

#endif
