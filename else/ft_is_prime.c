int	ft_is_prime(int nb)
{
	int	b;

	if (nb <= 1)
		return (0);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	b = 5;
	while (b * b <= nb)
	{
		if (nb % b == 0 || nb % (b + 2) == 0)
			return (0);
		b++;
	}
	return (1);
}
