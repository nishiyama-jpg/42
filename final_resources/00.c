/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   00.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/28 11:46:34 by username         #+#    #+#              */
/*   Updated: 2026/06/28 11:54:11 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_print_reverse_alphabet(void)
{
	char	c = 'z';

	while (c >= 'a')
	{
		ft_putchar(c);
		c--;
	}
}

void	ft_is_negative(int n)
{
	if (n < 0)
		ft_putchar('N');
	else
		ft_putchar('P');
}

void	ft_print_comb(void)
{
	char	a = '0';
	char	b;
	char	c;

	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				ft_putchar(a);
				ft_putchar(b);
				ft_putchar(c);
				if (!(a == '7' && b == '8' && c == '9'))
					write(1, ", ", 2);
				c++;
			}
			b++;
		}
		a++;
	}
}

void	ft_print_comb2(void)
{
	int	a = 0;
	int	b;

	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_putchar((a / 10) + '0');
			ft_putchar((a % 10) + '0');
			ft_putchar(' ');
			ft_putchar((b / 10) + '0');
			ft_putchar((b % 10) + '0');
			if (!(a == 98 && b == 99))
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}

void	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar((n % 10) + '0');
}

void	ft_print_combn_recursive(int n, int current_digit, int index, char *buffer)
{
	if (index == n)
	{
		write(1, buffer, n);
		// If the first digit is at its maximum possible value, it's the last combination
		if (buffer[0] != (10 - n) + '0')
			write(1, ", ", 2);
		return ;
	}
	while (current_digit <= 9)
	{
		buffer[index] = current_digit + '0';
		ft_print_combn_recursive(n, current_digit + 1, index + 1, buffer);
		current_digit++;
	}
}

void	ft_print_combn(int n)
{
	char	buffer[10];

	if (n > 0 && n < 10)
		ft_print_combn_recursive(n, 0, 0, buffer);
}
