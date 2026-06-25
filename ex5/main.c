#include <stdio.h>

void    ft_div_mod(int a, int b, int *div, int *mod);

int main(void)
{
	int a = 45;
	int b = 5;

	int v1 = 0;
	int v2 = 0;

	int *div = &v1;
	int *mod = &v2;

	printf("Before ft_div_mod: \n");
	
	printf("Pointer div points to address %p and has the value %d stored\n", div, *div);	
	printf("Pointer mod points to the address %p and has the value %d stored", mod, *mod);

	ft_div_mod(a, b, div, mod);
	printf("\n");
	printf("After ft_div_mod: \n");

	printf("Pointer div points to address %p and has the value %d stored\n", div, *div);
	printf("Pointer mod points to the address %p and has the value %d stored", mod, *mod);
}
