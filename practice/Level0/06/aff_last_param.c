#include <unistd.h>

int main(int ac, char **argv)
{
    int i;
    int j;

    i = ac - 1; //to get the last argument
    if (ac >= 2)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            write(1, &argv[i][j], 1);
            j++; //only j should move to iterate through the characters cz khalas we already set i to be the last paramter
        }
    }
    write(1, "\n", 1);
    return(0);
}