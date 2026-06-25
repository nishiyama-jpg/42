#include <unistd.h>

void maff_alpha(void)
{
    char c;
    int i;
    i = 0;
    c = 'a';
    while(c <= 'z')
    {
        if(i % 2 == 1) //even = 0 and odd = 1
        {
            c -=32; //convert from lowercase to uppercase
            write(1, &c, 1); //print
            c +=32;//convert back to lowercase
        }
        else 
        {
            write(1, &c, 1);
        }
        i++;
        c++;
    }
}

int main(void)
{
    maff_alpha();
}

//or just write(1, "aBcDeFgHiJkLmNoPqRsTuVwXyZ\n", 27);