int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	count;
	int	el;

	count = 0;
	el = length;
	if(f(tab[count], tab[count + 1]) <= 0)
	{
		while (f(tab[count], tab[count + 1]) <= 0 || count + 1 < length )	
		{
			count++;
		}
		if (count + 1 == length)
			return (1);	
	}
	else
	{
		while (f(tab[el], tab[el - 1]) <= 0)
		{
			el--;
			if(el - 1 == 0)
				return (1);	
	
		}
	}
	return (0);
}
