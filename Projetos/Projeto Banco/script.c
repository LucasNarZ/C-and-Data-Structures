#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_STRING_SIZE 20

struct Fila{
    char stack[MAX_SIZE][MAX_STRING_SIZE];
    int front, rear;
};

bool isEmpty(struct Fila *fila){
    return fila->rear == -1;
}

bool isFull(struct Fila *fila, int max_size){
    return fila->rear >= max_size - 1;
}

void add(char* value, struct Fila* fila, int max_size){
    if(isFull(fila, max_size)){
        printf("A lista está cheia.\n");
    }else{
        strcpy(fila->stack[++fila->rear], value);
        printf("Item Adicionado!\n");
    }
}

void MoverParaAtendendo(struct Fila *FilaEspera, struct Fila *FilaAtendendo, int max_size){
    if(isEmpty(FilaEspera)){
        printf("Fila de Espera Vazia.\n");
    }if(isFull(FilaAtendendo, max_size)){
        printf("Fila de atendimento cheia.\n");
    }else{ 
        strcpy(FilaAtendendo->stack[++FilaAtendendo->rear], FilaEspera->stack[FilaEspera->front]);
        FilaEspera->front++;
        printf("Elemento Movido!\n");
    }
}

void display(struct Fila *fila){
    int i;
    for(i = fila->front;i <= fila->rear;i++){
        printf("%s\n", fila->stack[i]);
    }
    printf("\n");
}

void MoverParaEncerrado(int *top, char atendidos[][MAX_STRING_SIZE], struct Fila *FilaAtendendo, int max_size){
    if(*top >= max_size - 1){
        printf("Pilha Cheia.\n");
    }else{
        (*top)++;
        strcpy(atendidos[*top], FilaAtendendo->stack[++FilaAtendendo->front]);
        printf("Atendimento Encerrado!\n");
    }
}

void removeEncerrado(int *top){
    if(*top == -1){
        printf("Pilha Vazia.\n");
    }else{
        (*top)--;
        printf("Cliente Removido.\n");
    }
}

void mostrarPilha(char atendidos[][MAX_STRING_SIZE], int *top){
    int i;
    for(i = *top;i >= 0;i--){
        printf("%s\n", atendidos[i]);
    }
}

int main(){
    char atendidos[MAX_SIZE][MAX_STRING_SIZE];
    int top = -1;
    struct Fila FilaEspera;
    struct Fila FilaAtendendo;
    FilaEspera.rear  = -1;
    FilaAtendendo.rear = -1;
    FilaEspera.front = 0;
    FilaAtendendo.front = 0;

    add("Lucas", &FilaEspera, MAX_SIZE);
    add("Matheus", &FilaEspera, MAX_SIZE);
    add("Nicolas", &FilaEspera, MAX_SIZE);
    add("João", &FilaEspera, MAX_SIZE);
    add("Duda", &FilaEspera, MAX_SIZE);
    MoverParaAtendendo(&FilaEspera, &FilaAtendendo, MAX_SIZE);
    MoverParaAtendendo(&FilaEspera, &FilaAtendendo, MAX_SIZE);
    MoverParaAtendendo(&FilaEspera, &FilaAtendendo, MAX_SIZE);
    MoverParaEncerrado(&top, atendidos, &FilaAtendendo, MAX_SIZE);
    MoverParaEncerrado(&top, atendidos, &FilaAtendendo, MAX_SIZE);
    removeEncerrado(&top);
    display(&FilaEspera);
    display(&FilaAtendendo);
    mostrarPilha(atendidos, &top);
    return 0;
}