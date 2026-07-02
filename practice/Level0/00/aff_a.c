#include <unistd.h>
int main(int ac, char **argv)
{
    int i;
    int found; //optional
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

//Way 2 of solving the question:
// #include <unistd.h>

// int main(int ac, char **argv)
// {
//     int i;

//     i = 0;
//     if (ac == 2)
//     {
//         while (argv[1][i])
//         {
//             if(argv[1][i] == 'a')
//             {
//                 write(1, &argv[1][i], 1);
//                 break;
//             }
//             i++;
//         }
//         write(1, "\n", 1);
//     }
//     else{
//         write(1, "a\n", 2);
//     }
//     return (1);
// }


//Way 3 of solving the question:
// while (argv[1][i] && argv[1][i] != 'a')
//     i++;

// if (argv[1][i] == 'a')
//     write(1, &argv[1][i], 1);

// write(1, "\n", 1);