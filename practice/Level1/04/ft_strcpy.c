//#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2) //we're copying from s2 to s1.
{
    int i;

    i = 0;
    while (s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';// put the last i which exits the while loop as \0. this is necessary because we are copying strings. a string without the null terminator at the end is not a string per say.
    return(s1);
}

// int main(void)
// {
//     char src[] = "hellojehkwjfbrhjewbkwj";
//     char dest[50];
//     printf("%s ", ft_strcpy(dest, src));
// }