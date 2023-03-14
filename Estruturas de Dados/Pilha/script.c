//A pilha é uma das estrutudras de dados mais básicas e mais usadas, ela é do tipo Last in First out, ou seja ultimo que entra primeiro que sai, é como uma pilha de pratos vc vai cococando em cima e se quiser tirar vai ter que tirar de cima tb.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int, int *, int [], int);
void pop(int *);
void verPilha(int [], int *);

int main(){

    push(2, &top, stack, MAX_SIZE);
    push(5, &top, stack, MAX_SIZE);
    pop(&top);
    verPilha(stack, &top);
    return 0;
}

void push(int value, int *top, int stack[], int max_size){
    if(*top >= max_size - 1){
        printf("A pilha está cheia\n");
    }else{
        (*top)++;
        stack[*top] = value;
        printf("Item adicionado com sucesso!\n");
    }
}


void pop(int *top){
    if(*top < 0){
        printf("A pilha está vazia\n");
    }else{
        printf("Item removido\n");
        (*top)--;
    }
}


void verPilha(int pilha[], int *top){
    int i;
    if(*top < 0){
        printf("Pilha está vazia");
    }else{
        for(i = *top; i >= 0; i--){
            printf("%d", pilha[i]);
        }
    }

}