#include <unistd.h>
void	ft_putstr(char *str)
{
	char	c;

	c = '0';
	while (*str != '\0')
	{
		c = *str;
		write(1, &c, 1);
		str++;
	}
}
