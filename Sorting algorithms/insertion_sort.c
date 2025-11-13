#include <stdio.h>
#include <limits.h>

void insertionSort(int arr[], int n) {
    // Smallest number ko ek ek karke start me laao
    int temp = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        int j = i;
        while (j >= 1 && arr[j] < arr[j - 1])
        {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[7] = {7, 4, 5, 9, 8, 2, 1};
    int n = 7;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    insertionSort(arr, n);
    return 0;
}