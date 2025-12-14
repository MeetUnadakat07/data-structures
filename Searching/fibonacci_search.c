#include<stdio.h>
#include<stdlib.h>

void generateFibonacci(int n, int *fib, int *fib1, int *fib2) {
    *fib2 = 0;
    *fib1 = 1;
    *fib = *fib1 + *fib2;
    while(*fib < n) {
        *fib2 = *fib1;
        *fib1 = *fib;
        *fib = *fib1 + *fib2;
    }
}

int fibonacciSearch(int arr[], int n, int x) {
    int fib, fib1, fib2;
    generateFibonacci(n, &fib, &fib1, &fib2);
    int offset = -1;
    while(fib > 1) {
        int i = (offset + fib2 < n) ? offset + fib2 : n - 1;
        if(arr[i] < x) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else if(arr[i] > x) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else {
            return i;
        }
        if(fib1 && offset + 1 < n && arr[offset + 1] == x) {
            return offset + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10, 22, 35, 40, 45, 50, 70, 80, 82, 85, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 85;

    int result = fibonacciSearch(arr, n, x);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}