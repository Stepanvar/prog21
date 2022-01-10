#include "stdio.h"
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (((unsigned char *)s)[++i])
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (&((char *)s)[i]);
	}	
	if (((unsigned char *)s)[i] == (unsigned char)c)
		return (&((char *)s)[i]);
	return (NULL);
}

int main(void)
{
	char *str;

	str = "check \nit";
	str = ft_strchr(str, '\n');
	printf("%s", str);
	return (0);
}
