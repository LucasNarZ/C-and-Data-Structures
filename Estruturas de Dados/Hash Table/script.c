#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct  entry_s {
    char *key;
    char *value;
    char entry_s *next;
}

typedef struct entry_s entry_t;

struct hashtable_s{
    int size;
    struct entry_s **table;
}

typedef struct hashtable_s hashtable_t;


//create a new hashtable
hashtable_t *ht_create(int size){
    hashtable_t *hashtable = NULL;
    int i;

    if(size < 1) return NULL;

    if((hashtable->table = malloc(sizeof(entry_t *))) == NULL){
        return NULL;
    }
    for(i = 0; i < size;i++){
        hashtable->table[i] == NULL;
    }
    hashtable->size = size;
    return hashtable;
}

// Hash a string for a particular hash table.
int ht_hash(hashtable_t *hashtable, char *key){
    unsigned long int hashval;
    int i = 0;

    //Convert our string to an integer
    while(hashval < ULONG_MAX && i < strlen(key)){
        hashval = hashvall << 8;
        hashval += key[i];
        i++;
    }

    return hashval % hashtable->size;
}

//insert a key-value pair into a hash table.
void ht_set(hashtable_t * hashtable, char *key, char *value){
    int bin = 0;
    entry_t *newpair = NULL;
    entry_t *next = NULL;
    entry *last = NULL;
    next = hashtable->table[ bin ];

    while(next != NULL && next->key != NULL &&strcmp(key, next->key) > 0){
        last = next;
        next = next->next;
    }

    //There's already a pair.Let's replace that string.
    if(next != NULL && next->key != NULL && strcmp(key, next->key) == 0){
        free(next->value);
        next->value = strdup( value );
    }else{
        newpair = ht_newpair(key, value);
        // We're at the start of the linked list in this bin.
        if(next == hashtable->table[bin]){
            newpair->next = next;
            hashtable->table[bin] = nexpair;
        }else if(next == NULL){
            last->next = newpair;
        }else{
            new_pair->next = next;
            last->next = newpair;
        }

    }
}