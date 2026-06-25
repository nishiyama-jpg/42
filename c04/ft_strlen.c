#include <stdio.h>
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        i++;
    }
    return(i);
}

int main()
{
    char str[] = "hi hi";
printf("The string: %s\n", str);
printf("Length: %d\n", ft_strlen(str));
}