#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
    int size;
    int *array;
    int i;

    if(start < end){
        size = (end - start) + 1; //the +1 is to include the upper and lower bound
    }
    else
    {
       size = (start - end) + 1;
    }

    array = malloc(size * sizeof(int));

    i = 0;
    while(i < size)
    {
        array[i] = start;
        if(start<end){
            start++;
        }
        else{
            start--;
        }
        i++;
    }
    return(array);
    
}

int main(void)
{
    int *array;
    int i;

    array = ft_range(1, 3);

    i = 0;
    while (i < 3)
    {
        printf("%d ", array[i]);
        i++;
    }

    free(array);
    return (0);
}