#include <stdio.h>

#define SIZE 50

void shift_element(int*, int);
void insertion_sort(int*, int);


int main()
{
    int arr[SIZE] = {0}, i = 0, *ptr = &arr[0];

    for(i = 0; i < SIZE; i++)
    {
        scanf("%d", (arr + i));
    }

    insertion_sort(arr, SIZE);

    for(i = 0; i < SIZE; i++)
    {
        if(i == (SIZE - 1))
        {
            printf("%d", *ptr);
        }
        else
        {
            printf("%d,", *ptr);
        }
        
        ptr += 1;
    }

    printf("\n");
    
    return 0;
}

void shift_element(int *arr, int i)
{   
    return;
}

void insertion_sort(int *arr, int len)
{
    return;
}
