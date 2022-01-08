#include "time.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include <fcntl.h>

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

int	main(void)
{
	int		fd;
	char	*str;
	char	out[201];
	char	name[6] = "0.txt";
	int		index;
	int		i;
	int		j;

	index = 0;
	i = 0;
	fd = 0;
	j = 0;
	srand(time(0));
	//if (ft_checkargc(argc))
	//	return (1);
	str = "\n\n\n\n\n\n\n!\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	//fd = open(argv[1], O_RDWR);
	while (j < 10)
	{
		fd = open(name, O_RDWR | O_CREAT, 0666);
		(name[0])++;
		while (i < 200)
		{
			index = rand() % 100;
			out[i] = str[index];
			i++;
		}
		write(fd, out, 200);
		j++;
		close(fd);
	}
	//close(fd);
	return (1);
}
