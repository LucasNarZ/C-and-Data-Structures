#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *returnnewString(char *string, int number){
    int length = strlen(string);
    char *newString = malloc(length + 1 + 11);
    sprintf(newString, "%s %d", newString, number); 
    return newString;
}

int main(){
    char *returned = returnnewString("batata", 10);
    printf("%s", returned);
    free(newString);
    return 0;
}