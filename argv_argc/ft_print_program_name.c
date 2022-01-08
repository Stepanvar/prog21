#include <unistd.h>
int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = argc - 1;
	j = 0;
	while (argv[0][j] != '\0')
	{
		write(1, &argv[0][j], 1);
		j++;
	}
	write(1, "\n", 1);
}
