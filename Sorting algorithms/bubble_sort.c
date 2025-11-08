#include <stdio.h>
#include<stdbool.h>
int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    int n = 5;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = true;                           //Assuming the array to be sorted
        for (int j = 0; j < n - i - 1; j++)
        {   
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = false;
            }
        }
        if(flag == true) break;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

// Time Complexity = O(n^2)
// Space Complexity = O(1)                                 //No extra array is used