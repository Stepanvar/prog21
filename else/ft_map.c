#include <stdlib.h>
int *ft_map(int *tab, int length, int(*f)(int))
{
	int *arr;
	int count;

	count = 0;
	arr = (int *)malloc(sizeof(int) * length);
	if (arr == NULL)
		return (0);
	while (count < length)
	{
		arr[count] = f(tab[count]);
		count++;
	}
	return (arr);
}
