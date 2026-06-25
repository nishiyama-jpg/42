#include <unistd.h>

char *ft_rev_print (char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    i--; // to remove '\0' at the end
    while(i>=0) // since we're starting backwards. ex: 2->1->0
    {
        write(1, &str[i], 1); //print the character
        i--; //go down
    }
    write(1, "\n", 1);
    return (str);

}

int main(void)
{
    ft_rev_print("hello");
}