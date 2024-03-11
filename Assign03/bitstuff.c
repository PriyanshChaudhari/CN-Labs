#include <stdio.h>
#include <string.h>

void bitStuffing(int N, int arr[], int brr[])
{
    int i = 0, j = 0, k;
    while (i < N)
    {
        if (arr[i] == 1)
        {
            int count = 1;
            brr[j] = arr[i];
            for (k = i + 1; arr[k] == 1 && k < N && count < 5; k++)
            {
                j++;
                brr[j] = arr[k];
                count++;
                if (count == 5)
                {
                    j++;
                    brr[j] = 0;
                }
                i = k;
            }
        }
        else
            brr[j] = arr[i];
        i++;
        j++;
    }

    printf("Stuffed Array: ");
    for (i = 0; i < j; i++)
        printf("%d", brr[i]);
    printf("\n");
}

void bitDestuffing(int N, int arr[])
{
    int brr[30];
    int i = 0, j = 0, k;
    int count = 1;
    while (i < N)
    {
        if (arr[i] == 1)
        {
            brr[j] = arr[i];
            for (k = i + 1; arr[k] == 1 && k < N && count < 5; k++)
            {
                j++;
                brr[j] = arr[k];
                count++;
                if (count == 5)
                {
                    k++;
                }
                i = k;
            }
        }
        else
            brr[j] = arr[i];
        i++;
        j++;
    }

    printf("Destuffed Array: ");
    for (i = 0; i < j; i++)
        printf("%d", brr[i]);
    printf("\n");
}

int main()
{
    int N = 7;
    int arr[] = {1, 1, 1, 1, 1, 1, 1};
    int brr[N];
    bitStuffing(N, arr, brr);
    bitDestuffing(N + 1, brr);
    return 0;
}
