/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   06.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/28 14:24:32 by username         #+#    #+#              */
/*   Updated: 2026/06/28 14:31:20 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//print program name

int	main(int argc, char **argv)
{
	int	i = 0;

	(void) argc;
	// Silence unused variable warning if compiling with flags
	while (argv[0][i])
		write(1, &argv[0][i++], 1);
	write(1, "\n", 1);
	return (0);
}
#include <unistd.h>
//Prints all parameters given to the	program, starting from argv[1]

int	main(int argc, char **argv)
{
	int	i = 1;

	// Start at 1 to skip program name
	int	j;

	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			write(1, &argv[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
//Prints all parameters in reverse order
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = argc - 1;

	// Start at the final argument index
	int	j;

	while (i >= 1) // Loop backwards down to 1
	{
		j = 0;
		while (argv[i][j])
			write(1, &argv[i][j++], 1);
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
//Sorts the arguments in ASCII order using a basic Bubble	Sort, then prints them
#include <unistd.h>

// Tiny helper to compare strings based on ASCII value

int	ft_strcmp(char *s1, char *s2)
{
	int	i = 0;

	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	main(int argc, char **argv)
{
	int		i = 1;
	int		j;
	char	*tmp;

	// 1. Bubble Sort the pointers inside argv (skip index 0)
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				tmp = argv[i];
				argv[i] = argv[j];
				argv[j] = tmp;
			}
			j++;
		}
		i++;
	}
	// 2. Print the newly sorted arguments
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			write(1, &argv[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
