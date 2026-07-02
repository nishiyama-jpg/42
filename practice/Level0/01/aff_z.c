#include <unistd.h>

int main(int ac, char **argv)
{
    int i;
    int found;
    i = 0;
    found = 0;
    if(ac == 2)
    {
        while(argv[1][i])
        {
            if(argv[1][i] == 'z')
            {
                write(1, "z\n", 2);
                found = 1;
                break;
            }
            i++;
        }
        if(found == 0)
        {
                    write(1, "z\n", 2);
        }
    }
    else 
    {
        write(1, "z\n", 2);
    }
}