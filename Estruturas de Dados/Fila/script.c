#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Fila{
    int stack[MAX_SIZE];
    int front,rear;
};

bool isFull(struct Fila *fila, int max_size){
    return fila->rear == max_size - 1;
}
bool isEmpty(struct Fila *fila){
    return fila->rear == -1;
}

void add(int value, struct Fila *fila, int max_size){
    if(isFull(fila, max_size)){
        printf("A fila está cheia\n");
    }else{
        fila->stack[++fila->rear] = value;
        printf("Item adicionado!\n");
    }
}

void Remove(struct Fila *fila){
    if(isEmpty(fila)){
        printf("A fila está vazia\n");
    }else{
        fila->front++;
        printf("Elemento removido\n");
    }
}

void display(struct Fila *fila){
    int i;
    for(i = fila->front;i <= fila->rear; i++){
        printf("%d\n", fila->stack[i]);
    }
}

int main(){
    struct Fila fila;
    fila.rear = -1;
    fila.front = 0;
    add(3, &fila, MAX_SIZE);
    add(5, &fila, MAX_SIZE);
    Remove(&fila);
    display(&fila);

    return 0;
}
