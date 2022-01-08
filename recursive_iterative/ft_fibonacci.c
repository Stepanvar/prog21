int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (0 == index) || (1 == index) || (2 == index)
		return (0);
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}
