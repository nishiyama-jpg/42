/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   03.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/28 12:51:53 by username         #+#    #+#              */
/*   Updated: 2026/06/28 12:55:23 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

// V	Exercise 01 : ft_strncmp 8
// VI	Exercise 02 : ft_strcat 9
// VII	Exercise 03 : ft_strncat 10
// VIII	Exercise 04 : ft_strstr 11
// IX	Exercise 05 : ft_strlcat 12

int	ft_strcmp(char *s1, char *s2)
{
	int	i = 0;

	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i = 0;

	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && i < (n - 1))
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i = 0;
	int	j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i = 0;
	unsigned int	j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < nb)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i = 0;
	int	j;

	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return (&str[i]);
		// Found it, return pointer to the match start
		i++;
	}
	return (0);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len = 0;
	unsigned int	s_len = 0;
	unsigned int	i = 0;

	while (dest[d_len] && d_len < size)
		d_len++;
	while (src[s_len])
		s_len++;
	if (d_len >= size)
		return (size + s_len);
	while (src[i] && (d_len + i) < (size - 1))
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (d_len + s_len);
}
