int	ft_strncmp(char *str1, char *str2, unsigned int n)
{
	while ((*str1 != '\0' || *str2 != '\0') && (n))
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
			n--;
		}
		else if (*str1 != *str2)
		{
			return (*(unsigned char *)str1 - *(unsigned char *)str2);
		}
	}
	return (0);
}
