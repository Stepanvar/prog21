#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <libgen.h>
void	ft_enter(void)
{
	char	c;

	while (read(0, &c, 1) != 0)
		write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	char	c;

	while (*str != '\0')
	{
		c = *str;
		write(2, &c, 1);
		str++;
	}
}

void	ft_err(char *argvc)
{
	ft_putstr("ft_cat: ");
	ft_putstr(argvc);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
}
