#include <stdio.h>
#include <stdlib.h>

void insertionSorting(int arr[], int n){
    int i;
    int big = 0;
    for(i = 0;i < n;i++){
        int t;
        big = arr[i];
        for(t = 0;t < n;t++){
            if(arr[t] > big){
                big = arr[t];
            }
        }
        arr[i] = big;
    }
}