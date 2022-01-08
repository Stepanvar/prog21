int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = nb;
	while (power > 1)
	{
		if (0 == power)
		{
			return (1);
		}
		nb *= i;
		power--;
	}
	return (nb);
}
