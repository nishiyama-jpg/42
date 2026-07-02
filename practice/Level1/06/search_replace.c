#include <unistd.h>

int main(int ac, char **argv)
{
    int j;

    
    if (ac == 4 && argv[2][1] == '\0' && argv[3][1] == '\0') //for exactly one character, index 1 must be the null terminator
    {
        j = 0;
        while(argv[1][j])
        {
            if(argv[1][j] == argv[2][0])
            {
                write(1, &argv[3][0], 1);
            }
            else
            {
                write(1, &argv[1][j], 1);
            }
            j++;   
        }
    }
    write(1, "\n", 1);
    return(0);
}