#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char nome[];
    char descriçao[];
    int dataVenci;
    int prioridade;
    struct Node *next;
};

struct Node *head = NULL;

void insert_at_position(char nome[], char descriçao[], int dataVenci, int prioridade, int pos, struct Node **head){
    int counter = 0;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->nome, nome);
    strcpy(newNode->descriçao, descriçao);
    newNode->dataVenci = dataVenci;
    newNode->prioridade = prioridade;
    if(pos == 0){
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while(temp != NULL && counter < pos - 1){
        temp = temp->next;
        counter++;
    }

    if(temp == NULL){
        printf("Posição não encontrada.\n")
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void remove_at_position(int pos, struct Node **head){
    int counter = 1;
    struct Node *temp = *head, *prev = NULL;
    if(pos < 1){
        printf("Posição invalida.\n");
        return;
    }
    if(pos == 1){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && counter < pos - 1){
        temp = temp->next;
        counter++;
    }

    if(temp == NULL){
        printf("Posição não encontrada.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}