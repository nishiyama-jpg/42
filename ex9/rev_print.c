#include <unistd.h>

char	*ft_rev_print(char *str)
{
	int	i;
	int	last;

	i = 0;
	while (str[i])
		i++;

	last = i - 1;
	while (last >= 0)
	{
		write(1, &str[last], 1);
		last--;
	}
	write(1, "\n", 1);
	return (str);
}

int	main(void)
{
	ft_rev_print("hello");
	return (0);
}
