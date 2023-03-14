void bubblesort(int arr[], int i){
    int i, j;
    for(i = 0;i < n - 1;i++){
        for(j = 1; j < n-i-1. j|++){
            if(arr[j] > arr[j + 1]){
                int temp arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

        }
    }
}

void selectionSort(int arr[], int n){
    int i, j, min;
    for(i = 0;i < n - 1;i++){
        min = i;
        for(j = i + 1; j < n;j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}