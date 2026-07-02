#include <unistd.h>

void	ft_print_numbers(void)
{
    int count;

    count = '0';
    while(count <= '9')
    {
        write(1, &count, 1);
        count++;
    }

}
int main(void)
{
    ft_print_numbers();
}