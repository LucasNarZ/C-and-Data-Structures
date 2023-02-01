#include <stdio.h>
#include <stdlib.h>

    char* calculate(int num1, int num2, char operator){
    //uma variavel estatica se mantem seu valor ao longo de todo o programa
    static char result[20];
    switch(operator){
        case '+':
            //a função sprintf é semelhante ao printf mas tb adiciona a "string" mostrada a variavel do primeiro parametro(result)
            sprintf(result, "Answer %d", num1 + num2);
            break;
        case '-':
            sprintf(result, "Answer %d", num1 - num2);
            break;
        case '*':
            sprintf(result, "Answer %d", num1 * num2);
            break;
        case '/':
            sprintf(result, "Answer %d", num1 / num2);
            break;
        default:
            sprintf(result, "Invalid Operator");
    
    }
    return result;
}

int main(){
    //string %s
    //float, double %f
    //char %c
    //int %d
    
    char name[] = "Jon";
    char letter = 'a';
    const int AGE = 35 * 2;
    printf("My name is %s and I'm %d and my favorite letter it's %c \n", name, AGE, letter);
    
    //pow() potência
    //seil() aredonda para cima
    //floor() aredonda para baixo 
    
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("You are %d years old", age);
    
    int num1;
    int num2;
    char operator;
    printf("First number:");
    scanf("%d", &num1);
    printf("Second number:");
    scanf("%d", &num2);
    printf("Operator:");
    //o espaço é para consumir o \n invisivel do ultimo scanf
    scanf(" %c", &operator);
    char* retorno = calculate(num1, num2, operator);
    printf("%s", retorno);
    return 0;
}