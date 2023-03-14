#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char nome[100];
    int codigoBarra;
    float preço;
    int quantidade;
    struct node *left;
    struct node *right;
};

struct node* createItem(char nome[], int codigoBarra, float preço, int quantidade){
    struct node *newItem = (struct node*)malloc(sizeof(struct node));
    strcpy(newItem->nome, nome);
    newItem->codigoBarra = codigoBarra;
    newItem->preço = preço;
    newItem->quantidade = quantidade;
    newItem->left = NULL;
    newItem->right = NULL;
    return newItem;
} 

struct node* insert(struct node *root, char nome[], int codigoBarra, float preço, int quantidade){
    int response = strcmp(nome, root->nome);
    if(root == NULL){
        return createItem(nome, codigoBarra, preço, quantidade);
    }if(response < 0){
        root->left = insert(root->left, nome, codigoBarra, preço, quantidade);
    }else if(response > 0){
        root->right = insert(root->right, nome, codigoBarra, preço, quantidade);
    }
    return root;
}

struct node* OrganizarOrdemAlfabética(struct node *root){
    if(root == NULL){
        printf("Árvore Vazia.");
    }if(strcmp(root->nome, root->left->nome) < 0 && root->left != NULL){
        struct node *temp = root;
        root = root->left;
        root->left = temp;
        root->left->left = OrganizarOrdemAlfabética(root->left->left);
        root = OrganizarOrdemAlfabética(root);

    }if(strcmp(root->nome, root->right->nome) > 0 && root->right != NULL){
        struct node *temp = root;
        root = root->right;
        root->right = temp;
        root->right->right = OrganizarOrdemAlfabética(root->right->right);
        root = OrganizarOrdemAlfabética(root);

    }
    return root;
}