#include <unistd.h>

#include <unistd.h>

int main(void)
{
    int i;
    char c;

    i = 0;
    c = 'z';
    while (c >= 'a')
    {
        if(i % 2 == 1)
        {
            c = c - 32;
            write(1, &c, 1);
            c = c + 32;
        }
        else
        {
            write(1, &c, 1);
        }
        i++;
        c--;
    } 
    write(1, "\n", 1);
    return (0);
}

// int main(void)
// {
//     write(1, "zYxWvUtSrQpOnMlKjIhGfEdCbA\n", 29);
// }