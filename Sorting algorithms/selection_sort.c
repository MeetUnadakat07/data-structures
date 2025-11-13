#include <stdio.h>
#include <limits.h>

void selectionSort(int arr[], int n) {
    // Select the minimum element and swap it with the i-th element
    int min, temp = 0;
    int minIdx;
    for (int i = 0; i < n - 1; i++) {
        min = INT_MAX;
        minIdx = -1;
        for (int j = i; j <= n - 1; j++) {
            if (arr[j] < min) {
                min = arr[j]; 
                minIdx = j;  
            }
        }
        temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[7] = {7, 4, 5, 9, 8, 2, 1};
    int n = 7;
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    selectionSort(arr, n);
    return 0;
}