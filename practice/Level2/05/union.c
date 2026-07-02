#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 3)
	{
		i = 0;
		while (av[1][i])
		{
			j = 0;
			while (j < i)
			{
				if (av[1][j] == av[1][i])
					break;
				j++;
			}
			if (j == i)
				write(1, &av[1][i], 1);
			i++;
		}
		i = 0;
		while (av[2][i])
		{
			j = 0;
			while (av[1][j])
			{
				if (av[2][i] == av[1][j])
					break;
				j++;
			}
			if (!av[1][j])
			{
				j = 0;
				while (j < i)
				{
					if (av[2][j] == av[2][i])
						break;
					j++;
				}
				if (j == i)
					write(1, &av[2][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}