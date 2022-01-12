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
	int		i = 0;
	char	*str = "\0";

	//printf("%d", (int)(*str));
	str = "check \nit";
	while (str[i])
		printf("%c\n", str[i++]);
	//str = ft_strchr(str, '\n');
	//printf("%s", str);
	return (0);
}
