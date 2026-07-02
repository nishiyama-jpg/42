#include <unistd.h>

int main(int ac, char **argv)
{
    int i;
    int printed;

    i = 0;
    printed = 0; // to find out whether this is the first printed charater
    if (ac == 2)
    {
        while (argv[1][i]) //have i reached the end of the string?
        {
            if (argv[1][i] != ' ') // check if the theres a space. is the current character not a space?
            {//ignore spaces
                if (printed == 1) // if the first character is printed
                {
                    write(1, "   ", 3); // add space
                }
                write(1, &argv[1][i], 1); //
                printed = 1;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
// ac = 2
// given that ./program "abc"
// argv
//  |
//  +--> argv[0] = "./program"
//  |
//  +--> argv[1] = "abc"
//  |
//  +--> argv[2] = NULL

// argv[1][0] = 'a'
// argv[1][1] = 'b'
// argv[1][2] = 'c'
// argv[1][3] = '\0'


// WAY2:
// #include <unistd.h>

// int main(int ac, char **argv)
// {
//     int i;
//     int printed;

//     i = 0;
//     printed = 0;

//     if (ac == 2)
//     {
//         while (argv[1][i])
//         {
//             if (argv[1][i] != ' ' && argv[1][i] != '\t')
//             {
//                 if (printed == 1)
//                 {
//                     write(1, "   ", 3);
//                 }
//                 write(1, &argv[1][i], 1);
//                 printed = 1;
//             }
//             i++;
//         }
//     }
//     write(1, "\n", 1);
//     return (0);
// }
