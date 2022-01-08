void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	count;

	count = 0;
	while (count < length)
	{
		 f(tab[count]);
		 count++;
	}
}
