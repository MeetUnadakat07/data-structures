#include <stdio.h>
#include <limits.h>
int main()
{
    int arr[7] = {7, 4, 5, 9, 8, 2, 1};
    int n = 7;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
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
    return 0;
}