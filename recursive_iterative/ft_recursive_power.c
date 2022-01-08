int	ft_recursive_power(int nb, int power)
{
	if (0 == power % 2)
	{
		if (power < 1)
			return (1);
		return (ft_recursive_power(nb * nb, power / 2));
	}
	else
	{
		if (power < 1)
		{
			return (1);
		}
		return (ft_recursive_power(nb, power - 1) * nb);
	}
}
