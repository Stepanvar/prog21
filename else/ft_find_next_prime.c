int ft_sqrt(int nb)
{
	int sqr;
	int i;

	i = 1;
	sqr = 1;
	while (nb > sqr)
	{
		sqr = i * i;
		i++;
	}
	if (nb == sqr)
		return (--i);
	if (nb < sqr)
		return (0);
	return(0);
}

int ft_find_next_prime(int nb)
{
	int b;
	b = 2;
	if (nb <= 1)
		return (0);
	while (b <= ft_sqrt(nb))
		if (nb % b == 0)
			return (0);
		b++;
	return (1);
}
