#include <stdio.h>
void	ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
   int a = 1;
   int b = 2;
   printf("Before swapping:\n");
    printf("%d\n",a);
    printf("%d\n",b);
    printf("After swapping:\n");
    ft_swap(&a,&b);
    printf("%d\n",a);
    printf("%d\n",b);

}