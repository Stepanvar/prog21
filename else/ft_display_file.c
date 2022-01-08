#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#define SIZE 4096
int	ft_checkargc(int argc)
{
	if (1 == argc)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	return (0);
}

void	ft_show(int fd)
{
	char	b[SIZE + 1];
	int		i;

	i = 1;
	while (i != 0)
	{
		i = read(fd, &b, SIZE);
		b[i] = '\0';
		write(1, &b, i);
	}
	if (i < 0)
	{
		write(1, "Cannot read file.\n", 18);
	}
}

int	main(int argc, char *argv[])
{
	int		fd;

	if (ft_checkargc(argc))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (-1 == fd)
	{
		write(1, "Cannot read file.\n", 18);
		return (1);
	}
	ft_show(fd);
	close(fd);
	return (0);
}
