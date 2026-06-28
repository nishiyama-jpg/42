/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   02.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/28 12:46:34 by username         #+#    #+#              */
/*   Updated: 2026/06/28 12:49:37 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i = 0;

	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n) // Fill remaining space with null bytes
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
// Exercise 06: Only printable characters (ASCII 32 to 126)

int	ft_str_is_printable(char *str)
{
	int	i = 0;

	while (str[i])
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i = 0;
	int	new_word = 1;

	while (str[i])
	{
		// Check if current char is alphanumeric
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))
		{
			if (new_word && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] -= 32;
			// Capitalize
			else if (!new_word && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] += 32;
			// Lowercase existing capitals inside the word
			new_word = 0;
		}
		else
			new_word = 1;
		// Next alphanumeric char will be the start of a word
		i++;
	}
	return (str);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i = 0;
	unsigned int	src_len = 0;

	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i = 0;
	char	*hex = "0123456789abcdef";

	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			// Cast to unsigned char to handle negative char values correctly
			unsigned char	c = (unsigned char) str[i];

			write(1, &hex[c / 16], 1);
			write(1, &hex[c % 16], 1);
		}
		i++;
	}
}
