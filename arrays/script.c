#include <stdio.h>
#include <stdlib.h>

int main(){
    //vc pode especifiar quantos elementos irão na array ou não
    int array[] = {3 ,5 , 6};
    int i;
    //aqui usamos o loop for com umma variavel de contador i, alémm da função sizeof e retorna o tamanho em bytes do argumento, se queremos iterar sobre uma array podemos usar sizeof(array) / sizeof(array[0] assim estamos pegando os bytes de todos os elementos somados ex: array de 10 se cada um for bytes serão 50 dividido pelo valor de um elemento que seria 5, então 50 / 5 = 10 
    for(i = 0; i < sizeof(array) / sizeof(array[0]); i++){
        printf("%d \n", array[i]);
    }
    return 0;
}