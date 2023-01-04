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


    // int arr[] = {0,1,2,3,4,5};
    // shift_element(arr + 1 , 3);
    // // 0 x 1 2 3 5

    //1 4 3 5 2  array
    //1 4 2 5 7  sort 1 
    //1 4 2 5 7  sort 4

    //1 3 4 5 2  sort 2  (shift l(1 , 1))

    // for (size_t i = 0; i < sizeof(arr)/sizeof(int); i++)
    // {
    //     printf("%d " , arr[i]);
    // }
    // printf("\n");

    // //1 4 3 5 2  array
    // int arr[] = {};
    // for (size_t i = 0; i < sizeof(arr)/sizeof(int); i++)
    // {
    //     printf("%d " , arr[i]);
    // }
    // printf("\n");
    // insertion_sort(arr , 0);
    // for (size_t i = 0; i < sizeof(arr)/sizeof(int); i++)
    // {
    //     printf("%d " , arr[i]);
    // }
    // printf("\n");
     
    
    return 0;
}

void shift_element(int *arr, int i)
{   
    int temp = *(arr + 1);
    int *parr = arr + 1;
    *parr = *arr;

    for (size_t j = 1; j < i  ; j++)
    {
        int temp2 = *(arr+j+1);
        parr = arr + j + 1;
        *parr = temp;
        temp = temp2;
    }
}

//1 4 3 5 2  array
//i = 1
//count = 0
//cur = 4
//parr -> arr[0] (=1)
void insertion_sort(int *arr, int len)
{
    int *parr = NULL;
    for (size_t i = 1; i < len; i++)
    {
        int count = 0;
        int cur = *(arr + i);
        parr = (arr + i - 1);
        int enter = 0;
        while(parr >= arr && cur < *parr)
        {
            enter = 1;
            count++;
            parr = parr - 1;
        }
        if(enter == 1){
            shift_element(parr + 1 , count);
            *(parr+1) = cur; 
        }
    }
}
