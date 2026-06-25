/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:16:30 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/02/08 17:20:48 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char *ft_strcapitalize(char *str)
{
	int	i;
	
	i = 0;
	while(str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z' )
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}

int	main(void)
{
	char	str[] = "all is lowercase 42!";

	printf("Before: %s\n", str);
	printf("After:  %s\n", ft_strcapitalize(str));
	return (0);
}
