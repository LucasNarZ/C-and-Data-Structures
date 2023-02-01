#include <stdio.h>
#include <string.h>

int main(){
    int i;
    for(i = 0; i < 5; i++){
        printf("Isso foi printado 5 vezes \n");
    }


    int array[] = {3, 5 , 6};
    for(i = 0; i < sizeof(array) / sizeof(array[0]); i++){
        printf("%d \n", array[i]);
    }
    i = 0;


    while (i < 10)
    {
        printf("Isso foi printado 10 vezes usando while \n");
        i++;
    }
    
    
    return 0;
}