#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char titulo[100];
    char descricao[100];
    char categoria[100];
    int prioridade;
    int vencimento;
    struct node *left;
    struct node *right;
};

struct node* createNode(char titulo[], int prioridade, char descricao[], char categoria[], int vencimento){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if(descricao[0] == '\0'){
        strcpy(newNode->descricao, "");
    }if(categoria[0] == '\0'){
        strcpy(newNode->categoria, "");
    }if(vencimento == 0){
        newNode->vencimento = 9999999;
    }
    if(newNode == NULL){
        printf("Erro na alocação da memória");
        exit(1);
    }
    strcpy(newNode->titulo, titulo);
    strcpy(newNode->descricao, descricao);
    strcpy(newNode->categoria, categoria);
    newNode->prioridade = prioridade;
    newNode->vencimento = vencimento;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node *root, char titulo[], int prioridade, char descricao[], char categoria[], int vencimento){
    if(root == NULL){
        return createNode(titulo, prioridade, descricao, categoria, vencimento);
    }if(prioridade < root->prioridade || prioridade == root->prioridade){
        root->left = insert(root->left, titulo, prioridade, descricao, categoria, vencimento);
    }else if(prioridade > root->prioridade){
        root->right = insert(root->right, titulo, prioridade, descricao, categoria, vencimento);
    }
    return root;
}

void inOrder(struct node *root){
    if(root != NULL){
        inOrder(root->left);
        printf("%s \n", root->titulo);
        inOrder(root->right);
    }
}

int main() {
    struct node *root = NULL;
    root = insert(root, "levar o lixo", 1, "", "", 0);
    insert(root, "Lavar louça", 1, "", "", 0);
    insert(root, "Lavar roupa", 3, "", "", 0);
    insert(root, "estudar", 2, "", "", 0);
    insert(root, "mercado", 3, "", "", 0);
    insert(root, "passeio", 3, "", "", 0);

    inOrder(root);

    return 0;
}