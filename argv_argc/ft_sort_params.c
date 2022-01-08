#include <unistd.h>
int	ft_write(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argc > j)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			write(1, &argv[j][i], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
	return (0);
}

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 != '\0' || *str2 != '\0')
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else if (*str1 != *str2)
		{
			return (*(unsigned char *)str1 - *(unsigned char *)str2);
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	 int	j;
	char	*tmp;

	j = 1;
	while (argc > j + 1)
	{
		if (ft_strcmp(argv[j], argv[j + 1]) > 0)
		{
			tmp = argv[j];
			argv[j] = argv[j + 1];
			argv[j + 1] = tmp;
		}
		j++;
	}
	ft_write(argc, argv);
}
