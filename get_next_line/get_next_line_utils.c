#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*rep;
	const unsigned char	*str;

	i = 0;
	rep = (unsigned char *)dest;
	str = (const unsigned char *)src;
	if (!dest)
		return (NULL);
	while (i < n)
	{
		rep[i] = str[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(char *s)
{
	size_t	size;
	char	*res;

	size = ft_strlen (s) + 1;
	res = malloc(sizeof(char) * size);
	if (!res)
		return (NULL);
	else
		res = ft_memcpy(res, s, size);
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
	if (!s1)
		return (s1 = ft_strdup(""));
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	j = 0;
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

// fonction qui copie une str dans un str final jusqu'au premier \n

char	*ft_strfinal(char *str)
{
	char	*strfinal;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
		len ++;
	strfinal = malloc(sizeof(char) * len + 1);
	if (!strfinal)
	{
		free(strfinal);
		return (NULL);
	}
	while (str[i] != '\n')
	{
		strfinal[i] = str[i];
		i++;
	}
	return (strfinal);
}

// fomction qui copie str à partir du premier \n

char	*ft_strcop(char *str, int len)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	res = malloc(sizeof(char) * (len - i + 1));
	while (i < len)
	{
		res[j] = str[i];
		j++;
		i++;
	}
	return (res);
}
