#include <unistd.h>

int main(int ac, char **argv)
{
    int i;
    i = 0;

    if(ac==2)
    {
        while(argv[1][i])
        {
            //one for betwwen a and m
            if((argv[1][i] >= 'a' && argv[1][i] <= 'm') || (argv[1][i] >= 'A' && argv[1][i] <= 'M'))
            {
                argv[1][i] += 13;
            }

            //one for betwwen n and z
            else if((argv[1][i] >= 'n' && argv[1][i] <= 'z') || (argv[1][i] >= 'N' && argv[1][i] <= 'Z')) //IMPORTANT NOTE: IF checks the modified character. thats why we using else if here. so that if the first condition is not met, check this, if its met, skip this.
            {
                argv[1][i] -= 13;
            }
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}