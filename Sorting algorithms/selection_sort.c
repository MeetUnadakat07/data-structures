#include <stdio.h>
#include <limits.h>
int main()
{
    int arr[7] = {7, 4, 5, 9, 8, 2, 1};
    int n = 7;
    int min, temp = 0;
    int minIdx;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < n - 1; i++) // Gives the number of passes for the algorithm
    {
        min = INT_MAX;
        minIdx = -1;
        for (int j = i; j <= n - 1; j++) // Gives the elements which have to be traversed
        {
            if (arr[j] < min)
            {
                min = arr[j]; // Getting the minimum element
                minIdx = j;   // Getting the index on which minimum number is present
            }
        }
        // Swapping of the minimum number and arr[i]
        temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

// Time complexity = O(n^2)
// Total number of swaps = O(n)