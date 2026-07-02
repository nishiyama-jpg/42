#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
    int size;
    int *array;
    int i;
   
    // first we calculate how many numbers are within the range (including the bounds).
    if(start < end){
        size = (end - start) + 1; //the +1 is to include the upper and lower bound
    }
    else
    {
       size = (start - end) + 1;
    }

    array = malloc(size * sizeof(int)); //allocate a memory on the heap of size 16bytes (if size = 4)(and because int = 4)

        if (array == NULL) // if (!arr)
    {
        return (NULL);
    }

    i = 0;
    while (i < size)
    {
        if (start <= end)
        {
            array[i] = start + i;
        }
    else
    {
        array[i] = start - i;
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
