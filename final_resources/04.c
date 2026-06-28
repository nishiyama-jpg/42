/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   04.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/28 12:56:42 by username         #+#    #+#              */
/*   Updated: 2026/06/28 14:14:19 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i = 0;

	while (str[i])
		write(1, &str[i++], 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

int	ft_atoi(char *str)
{
	int	i = 0, sign = 1, res = 0;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
//---

int	check_base(char *base)
{
	int	i = 0, j;

	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i < 2 ? 0 : i);
	// Returns the length of the base if valid, else 0
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb = nbr;
	int		b_len = check_base(base);

	if (b_len == 0)
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= b_len)
		ft_putnbr_base(nb / b_len, base);
	write(1, &base[nb % b_len], 1);
}
//---

int	get_base_index(char c, char *base)
{
	int	i = 0;

	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i = 0, sign = 1, res = 0, idx;
	int	b_len = check_base(base);

	// Uses the same validation logic from Ex 04
	if (b_len == 0)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		idx = get_base_index(str[i], base);
		if (idx == -1) // Stop instantly if character is not part of the base rules
			break ;
		res = res * b_len + idx;
		i++;
	}
	return (res * sign);
}
