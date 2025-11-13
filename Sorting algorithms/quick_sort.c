#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int st, int end) {
    // Partition the array along the pivot element
    int idx = st - 1;
    int pivot = arr[end];

    for (int i = st; i < end; i++) {
        if (arr[i] < pivot) {
            idx++;
            swap(&arr[i], &arr[idx]);
        }
    }

    idx++;
    swap(&arr[end], &arr[idx]);
    return idx;
}

void quickSort(int arr[], int st, int end) {
    // Sorting similar to merge sort but not from middle but from a pivot element and elements smaller than pivot at the left and greater at the right
    if (st < end) {
        int pivotIdx = partition(arr, st, end);

        quickSort(arr, st, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, end);
    }
}

int main() {
    int arr[] = {5, 2, 6, 4, 1, 3};
    int n = sizeof(arr) / sizeof(int);

    quickSort(arr, 0, n);
    for(int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
}