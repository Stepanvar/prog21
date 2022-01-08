char	*ft_strcat(char *dest, char *src, unsigned int nb)
{
	char	*notend;

	notend = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while ((*src != '\0') && (nb))
	{
		*dest = *src;
		dest++;
		src++;
		nb--;
	}
	*dest = '\0';
	return (notend);
}
