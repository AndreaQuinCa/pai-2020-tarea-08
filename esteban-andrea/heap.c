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
  return -1;
} 

void bottomUpHeapify(int *arr, int k){ 
  return;
} 

void topDownHeapify(int * arr, int k, int n){ 
  while (3*k <= n){
    int j = 3*k;
    if (j < n && arr[j] < arr[j+1]) j++;
    if (arr[k]>= arr[j]) break;
    swap(arr, k, j);
    k = j;
  }
  return;
} 

THeap * THeap_new(void){
  // Alocacion de memoria
  THeap *heap = (THeap *) calloc (1,sizeof(THeap));
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
