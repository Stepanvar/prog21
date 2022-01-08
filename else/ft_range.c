#include <stdlib.h>
#include <stdio.h>
int *ft_range(int min, int max)
{
	int*	arr;
	long long	i;
	unsigned long	count;
	
	i = min;
	count = 0;
	if (min >= max)
		return (NULL);
	while(i < max)
	{
		i++;
		count++;
	}
	i = 0;
	arr = (int *)malloc(sizeof(int) * count);
	if (arr == NULL)
		return (NULL);
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}
