#include <stdio.h>
    unsigned ft_strlen(char *str){
        int i;
        i = 0;
        while(str[i])
        {
            i++;
        }
        return(i);
    }

    unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
    {
        unsigned int dest_len;
        unsigned int src_len;
        int j;
        dest_len = ft_strlen(dest);
        src_len = ft_strlen(src);

        
        if (size <= dest_len)
        {
            return (size + src_len);
        }   
            j = 0;
            while(src[j] && dest_len + j < size - 1)
            {
                dest[dest_len + j] = src[j];
            j++;
            }
            dest[dest_len + j] = '\0';

            return (dest_len + src_len);
            
    }

int main()
{
    char dest[20] = "Hello";
    char src[] = "World";

    printf("Before: %s\n", dest);

    printf("Return: %u\n",
        ft_strlcat(dest, src, 10));

    printf("After: %s\n", dest);

    return (0);
    }

//strlcat returns the length of the string it tried to create after trying to concatenate src with dest