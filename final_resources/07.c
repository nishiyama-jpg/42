/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   07.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/28 14:32:33 by username         #+#    #+#              */
/*   Updated: 2026/06/28 14:43:18 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i = 0;
	char	*dest;

	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i = 0;

	if (min >= max)
		return (NULL);
	range = malloc(sizeof(int) * (max - min));
	if (!range)
		return (NULL);
	while (min < max)
		range[i++] = min++;
	return (range);
}
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i = 0;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * (max - min));
	if (!*range)
		return (-1);
	while (min < max)
		(*range)[i++] = min++;
	return (i);
}
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i]) i++;
		return (i);
}

int	get_total_len(int size, char **strs, char *sep)
{
	int	len = 0, i = 0;

	if (size <= 0) return (1);
		while (i < size)
		len += ft_strlen(strs[i++]);
	return (len + (ft_strlen(sep) * (size - 1)) + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i = 0, j, k = 0;

	res = malloc(sizeof(char) * get_total_len(size, strs, sep));
	if (!res) return (NULL);
		if (size <= 0)
		{
			res[0] = '\0';
			return (res);
		}
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			res[k++] = strs[i][j++];
		if (i < size - 1)
		{
			j = 0;
			while (sep[j])
				res[k++] = sep[j++];
		}
		i++;
	}
	res[k] = '\0';
	return (res);
}

#include <stdlib.h>

// Assumes standard validation check_base/get_base_index from C04 are loaded
int	ft_atoi_base(char *str, char *base);
int	check_base(char *base);

int	get_nbr_len(long nbr, int b_len)
{
	int	len = 0;

	if (nbr <= 0)
	{
		len++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		len++;
		nbr /= b_len;
	}
	return (len);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nb;
	int		b_to_len = check_base(base_to), len, sign = 0;
	char	*res;

	if (!check_base(base_from) || !b_to_len) return (NULL);
		nb = ft_atoi_base(nbr, base_from);
	len = get_nbr_len(nb, b_to_len);
	res = malloc(sizeof(char) * (len + 1));
	if (!res) return (NULL);
		res[len] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
		sign = 1;
	}
	if (nb == 0) res[0] = base_to[0];
		while (nb > 0)
		{
			res[--len] = base_to[nb % b_to_len];
			nb /= b_to_len;
		}
	return (res);
}

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	while (*charset)
		if (c == *charset++) return (1);
		return (0);
}

int	count_words(char *str, char *charset)
{
	int	words = 0, i = 0;

	while (str[i])
	{
		if (!is_sep(str[i], charset) && (i == 0 || is_sep(str[i - 1], charset)))
			words++;
		i++;
	}
	return (words);
}

char	*word_dup(char *str, char *charset)
{
	int		len = 0, i = 0;
	char	*word;

	while (str[len] && !is_sep(str[len], charset))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word) return (NULL);
		while (i < len)
		word[i++] = *str++;
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i = 0, words = count_words(str, charset);

	res = malloc(sizeof(char *) * (words + 1));
	if (!res) return (NULL);
		while (*str)
		{
			while (*str && is_sep(*str, charset))
				str++;
			if (*str && !is_sep(*str, charset))
			{
				res[i++] = word_dup(str, charset);
				while (*str && !is_sep(*str, charset))
					str++;
			}
		}
	res[i] = NULL;
	return (res);
}
