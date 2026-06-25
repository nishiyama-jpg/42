#include <unistd.h>
int main(int ac, char **argv)
{
    int i;
    int found;
    i = 0;
    found = 0;
    if(ac == 2)
    {
        while(argv[1][i] != '\0')
        { //loop through the second argument 0 - 1
            if(argv[1][i] == 'a')
            {
                write(1, "a\n", 2);
                found = 1;
                break;
            }
            i++;
        }
        if(found == 0){
            write(1, "\n", 1);
        }
    }
    else
    {
        write(1, "a\n", 2);
    }
}