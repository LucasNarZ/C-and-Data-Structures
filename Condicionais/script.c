#include <stdio.h>
#include <string.h>

//and: &&; or:||; not: !;
int main(){
    int i = 3;
    if(i < 12){
        printf("i é menor do que 12");
    }else if(i > 12){
        printf("i é maior do 12");
    }else{
        printf("i é igual a 12");
    }


    switch (i){
        case 2:
            printf("i é igual a 2");
            break;
        case 3:
            printf("i é igual 3");
            break;
        default:
            printf("i é diferente de 2 e 3");
            break;
    }
    return 0;
}

