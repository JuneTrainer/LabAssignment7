#include <stdio.h>
#define SIZE 4095
void bubbleSort(int arr[], int n, int SP[]) {
    int i, j, count, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                SP[arr[j]]++;
                SP[arr[j + 1]]++;
                count++;
            }
        }
    }
    printf("It took %d swaps to sort \n", count);
    count = 0;
}
void selectionSort(int Array[], int n, int Swaps[]) {
    int i, j, Min;
    int count = 0;
    for (i = 0; i < n-1; i++) {
        Min = i;
        for (j = i+1; j < n; j++) {
            if (Array[j] < Array[Min])
                Min = j;
                
        }
        
        if (Min != i) { 
            int temp = Array[Min];
            Array[Min] = Array[i];
            Array[i] = temp;
            Swaps[Array[Min]]++;
            Swaps[Array[i]]++;

            count++;
        }
    }
    printf("It took %d swap(s) to sort \n", count);
    count = 0;
}


int main() {
    int arr[] = {97, 16, 45, 63, 13, 22, 7, 58, 72}; 
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int Swaps[SIZE]; 
    for (int i = 0; i < SIZE; i++) {
        Swaps[i] = 0;
    }

    bubbleSort(arr, n, Swaps);
    printf("Number of swaps for each element in the bubble sort: \n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: %d swap(s)\n", arr[i], Swaps[arr[i]]);
    }
    
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int Swaps2[SIZE]; 
    for (int i = 0; i < SIZE; i++) {
        Swaps2[i] = 0;
    }
    
    printf("\n");
    bubbleSort(arr2, n2, Swaps2);
    printf("Number of swaps for each element in the bubble sort: \n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: %d swap(s)\n", arr2[i], Swaps2[arr2[i]]);
    }

    int selarr[] = {97, 16, 45, 63, 13, 22, 7, 58, 72}; 
    int selarr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    
    int n3 = sizeof(arr)/sizeof(arr[0]);
    int Swaps3[SIZE]; 
    int i;
    printf("\n");
    selectionSort(selarr, n3, Swaps3);
    printf("Number of swaps for each element in the selection sort: \n");
    for (i = 0; i < SIZE; i++) {
        if (Swaps3[i] > 0)
            printf("Element %d: %d swap(s) \n", i, Swaps3[i]) ;
    }
    
    int n4 = sizeof(arr)/sizeof(arr[0]);
    int Swaps4[SIZE]; 
    printf("\n");
    selectionSort(selarr2, n4, Swaps4);
    printf("Number of swaps for each element in the selection sort: \n");
    for (i = 0; i < SIZE; i++) {
        if (Swaps4[i] > 0)
            printf("Element %d: %d swap(s) \n", i, Swaps4[i]) ;
    }
    return 0;
}

