#include <stdio.h>

#define SIZE 50

void shift_element(int*, int);
void insertion_sort(int*, int);


int main()
{
    int arr[SIZE] = {0}, i = 0, *ptr = &arr; //declearing variables 

    for(i = 0; i < SIZE; i++) // get all the numbers
    {
        scanf("%d", (arr + i));
    }

    insertion_sort(arr, SIZE); // sort the array

    for(i = 0; i < SIZE; i++) //print the array
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

/**
 * move i element in the array from arr pointer right
*/
void shift_element(int *arr, int i)
{   
    int temp = *(arr + 1); //for the first element
    int *parr = arr + 1;
    *parr = *arr;

    for (size_t j = 1; j < i  ; j++) //for the rest
    {
        int temp2 = *(arr+j+1);
        parr = arr + j + 1;
        *parr = temp;
        temp = temp2;
    }
}

/**
 * insertion sort with shift_element
*/
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
