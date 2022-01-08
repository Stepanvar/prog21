#include <stdlib.h>
#include <stdio.h>
int *ft_ultimate_range(int **range, int min, int max)
{
	int*	arr;
	long long	i;
	unsigned long	count;
	
	i = min;
	count = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	while(i < max)
	{
		i++;
		count++;
	}
	i = 0;
	*range = (int *)malloc(sizeof(int) * count);
	if (!(*range))
		return (-1);
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (i);
}
