#include "ft_printf.h"
int	main(int argc, char *argv[])
{
	//ft_p_field();
	if (!*(argv[1]))
		return (-1);
	ft_field(argv[1]);
	return (0);
}
