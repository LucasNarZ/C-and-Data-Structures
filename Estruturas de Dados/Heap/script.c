#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 100

int heap[HEAP_SIZE];
int n = 0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int i){
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if(left < n && heap[left] < heap[smallest]){
        smallest = left;
    }
    if(right < n && heap[right] < heap[smallest]){
        smallest = right;
    }
    if(smallest != i){
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

void insert(int element){
    if(n == HEAP_SIZE){
        printf("Heap cheio");
        return;
    }

    n++;
    heap[n - 1] = element;

    int i = n - 1;
    while(i > 0 && heap[(i - 1) / 2] > heap[i]){
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

void removeMin(){
    if(n == 0){
        printf("Heap vazio");
    }
    
    heap[0] = heap[n - 1];
    n--;
    heapify(0);
}

int main() {
    insert(3);
    insert(2);
    insert(1);
    insert(15);
    insert(5);
    insert(4);
    insert(45);

    printf("Elementos no heap: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");

    removeMin();

    printf("Elementos no heap depois de remover o mínimo: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");

    return 0;
}