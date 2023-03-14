#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

struct pair{
    char *key;
    char *value;
    struct pair *next;
};

struct pair *hashtable[SIZE]; 

int createHashCode(char *key){
    int len = strlen(key);
    int i;
    int hash = 0;
    for(i = 0; i < len;i++){
        hash += key[i];
    }
    return hash % 100;
}

void createPair(char *key, char* value){
    int hash = createHashCode(key);
    struct pair *newPair = (struct pair*)malloc(sizeof(struct pair));
    newPair->key = (char*)malloc(strlen(key) + 1);
    newPair->value = (char*)malloc(strlen(value) + 1);
    strcpy(newPair->key, key);
    strcpy(newPair->value, value);
    newPair->next = hashtable[hash];
    hashtable[hash] = newPair;
}

char* getValue(char *key){
    int hash = createHashCode(key);
    struct pair *current = hashtable[hash];
    while(current != NULL){
        if(strcmp(current->key, key) == 0){
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

int main(){

    createPair("Nome", "asddadad");
    char* returned = getValue("Nome");
        
    printf("%s", returned);


    return 0;
}