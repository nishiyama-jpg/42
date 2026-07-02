#include <stdio.h>

int	ft_strlen(char *str)
{
    int i;
    i = 0;
    while(str[i])
    {
        i++;
    }
    return (i);
}

int main(void)
{
    printf("this is the length of the string: %d", ft_strlen("hello"));
}