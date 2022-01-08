int	ft_sqrt(int nb)
{
	int	sqr;
	int	i;

	i = 10;
	sqr = 1;
	while (nb >= sqr || i < 46340)
	{
		if (nb == sqr)
		{
			return (--i);
		}
		sqr = i * i;
		i++;
	}
	if (nb != sqr * --i)
	{
		return (0);
	}
	return (i);
}
