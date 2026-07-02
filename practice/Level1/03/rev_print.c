#include <unistd.h>

int main(int ac, char **argv)
{
    int i;
    
    if (ac == 2)
    {
        i = 0;
        while(argv[1][i] != '\0')
        {
            i++;
        } //loop through the entire string and get the length.
        i--; //whatever the length we got above, -1. To move one step back to skip (\0) the null terminator at the end of the string.
        while(i >= 0)
        {
            write(1, &argv[1][i], 1);
            i--;
        }
    }
    write(1, "\n", 1);
    return (1);
}