#include <stdio.h>
#include <stdlib.h>

//este é a estrutura de um nó na lista
struct Node{
    int data;
    struct Node *next;
};

//esta é a lista em si
struct Node *head = NULL;

//função de adicionar a lista em uma posição especifica
void insert_at_position(int data, int pos, struct Node **head){

    int counter = 0;
    //alocando a memoria necessaria para o novo nó
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    //alocando o valor passado como parametro para data de Node
    new_node->data = data;

    if(pos == 0){
        //colocando que o proximo do novo nó será o atual primeiro elemento
        new_node->next = *head;
        //adicionando o nó ao inicio da lista
        *head = new_node;
        return;
    }

    struct Node *temp = *head;
    int i;
    //iterando sobre a lista até que ela chegue na posição desejada
    while(temp != NULL && counter < pos-1){
        temp = temp->next;
        counter++;
    }
    //se a posição estiver alem do range da lista
    if(temp == NULL){
        printf("Position not found");
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;

}
void print(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
int main(){
    insert_at_position(1, 0, &head);
    insert_at_position(5, 0, &head);
    insert_at_position(7, 1, &head);
    insert_at_position(9, 2, &head);
    insert_at_position(2, 3, &head);

    print(head);
    return 0;
}