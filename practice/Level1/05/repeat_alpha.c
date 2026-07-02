#include <unistd.h>

int main(int ac, char **argv)
{
    int i;
    int j;
    int repeat; //counter

    i = 0;
    if (ac == 2)
    {
        while (argv[1][i])
        {
            if(argv[1][i] >= 'a' && argv[1][i] <= 'z') //for lowercase letters
            {
                repeat = argv[1][i] - 'a' + 1; //how far is the current letter from a, add 1 to it, and this is the amount of time we want to repeat the letter.
            }
            else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
            {
                repeat = argv[1][i] - 'A' + 1; // same thing but for upper case letters.
            }
            else //if not an alphabet, just print it once.
            {
                repeat = 1;
            }
            j = 0;
            while(j < repeat)
            {
                write(1, &argv[1][i], 1);
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}