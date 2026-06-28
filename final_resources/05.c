/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   05.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/28 14:19:42 by username         #+#    #+#              */
/*   Updated: 2026/06/28 14:22:49 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res = 1;

	if (nb < 0) return (0);
		while (nb > 0)
		res *= nb--;
	return (res);
}

int	ft_recursive_factorial(int nb)
{
	if (nb < 0) return (0);
		if (nb == 0) return (1);
		return (nb * ft_recursive_factorial(nb - 1));
}

int	ft_iterative_power(int nb, int power)
{
	int	res = 1;

	if (power < 0) return (0);
		while (power-- > 0)
		res *= nb;
	return (res);
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0) return (0);
		if (power == 0) return (1);
		return (nb * ft_recursive_power(nb, power - 1));
}

int	ft_fibonacci(int index)
{
	if (index < 0) return (-1);
		if (index == 0) return (0);
		if (index == 1) return (1);
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

int	ft_sqrt(int nb)
{
	int	i = 1;

	if (nb <= 0) return (0);
		while (i <= 46340 && i * i < nb) // 46340 avoids int overflow when squared
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}

int	ft_is_prime(int nb)
{
	int	i = 2;

	if (nb <= 1)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2) return (2);
		while (!ft_is_prime(nb)) // Recycle the logic directly from Ex 06
		nb++;
	return (nb);
}
