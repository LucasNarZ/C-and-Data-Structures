#include <stdio.h>
#include <string.h>



int main(){
    char a[] = returnNewstring("Batata", 4);
    printf("%s", a);
    return 0;
}

char* returnNewstring(char *string, int number){
    static char *result;
    sprinf(result, "%s %d", string, number);
    return result;
}