#include <unistd.h>

int main(int ac, char **argv)
{
    int i;

    i = 0;
    if (ac >= 2)
    {
        while (argv[1][i])
        {
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}