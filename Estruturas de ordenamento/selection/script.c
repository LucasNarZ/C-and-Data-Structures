#include <stdio.h>

void selection_sorting(int arr[], int n){
    int i, j;
    for(i = 0;i < n - 1;i++){
        int current_value = i;
        for(j = i + 1;j < n;j++){
            if(arr[current_value] > arr[j]){
                current_value = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[current_value];
        arr[current_value] = temp;
    }
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    selection_sorting(arr, n);
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}