int	ft_recursive_factorial(int nb)
{
	if (0 == nb)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}
