#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
//to print a character

void	ft_puthex(unsigned char c)
{
	char	*hex; //the pointer to a string

	hex = "0123456789abcdef"; //creates a lookup table
	ft_putchar('\\');
	ft_putchar(hex[c / 16]);//to print the first hexadecimal digit
	ft_putchar(hex[c % 16]);//to print the second hexadecimal digit
}

//converts a character's ASCII value into 2 hexadecimal digits and prints them.

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]); //if printable, print normally.
		else
			ft_puthex((unsigned char)str[i]); //non-printable, print its hexadecimal code. 
		i++;
	}
}

int	main(void)
{
	char *str = "Ola\nesta bem?";
	ft_putstr_non_printable(str);
}
