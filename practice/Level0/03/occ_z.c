#include <unistd.h>

void putnbr(int n)
{
    char c;

    if (n >= 10)
    {
        putnbr(n / 10);
    }
    c = (n % 10) + '0';
    write(1, &c, 1);
}

int main(int ac, char **argv)
{
    int i; //is your position in the string. doesnt store the number of Zs found.
    int count; //the count variable stores the number of Zs found.
    
    i = 0;
    if (ac == 2)
    {
        count = 0; //
        while (argv[1][i]) //loops through the entire string. through every character in the argument string.
        {
            if (argv[1][i] == 'Z')// if a character is equal to Z, increase the count.
            {
                count++;
            }
            i++;// then go to the next index/position/character in the string.
        }
    }
    putnbr(count); //we used putnbr here to convert the count to string so that it prints. 
    return (0); //0 is the exit code
}