#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void merge(int arr[], int st, int mid, int end) {
    // Merging the arrays in sorted manner
    int temp[MAX];
    int i = st, j = mid + 1;
    int idx = 0;
    
    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp[idx++] = arr[i++];
        } else {
            temp[idx++] = arr[j++];
        }
    }
    while(i <= mid) {
        temp[idx++] = arr[i++];
    } 
    while(j <= end) {
        temp[idx++] = arr[j++];
    }
    
    for(int k = 0; k < idx; k++) {
        arr[st + k] = temp[k];
    }
}

void mergeSort(int arr[], int st, int end) {
    // Splitting the array into two halves and sorting it wrt the elements and then merging it
    if(st < end) {
        int mid = st + (end - st) / 2;
        
        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, end);
        
        merge(arr, st, mid, end);
    }
}

int main() {
    int arr[] = {12, 31, 35, 8, 32, 17};
    int n = sizeof(arr) / sizeof(int);
    mergeSort(arr, 0, n - 1);
    
    printf("Sorted array: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}