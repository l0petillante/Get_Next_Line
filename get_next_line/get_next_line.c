#include "get_next_line.h"

int	ft_non(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char	*strfinal;
	char	*buffer;
	int	len;

	str = NULL;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	len = 0;
	//printf("%d\n", fd);
	while (ft_non(str) == 1)
	{
		// printf("read %ld\n", read(fd, buffer, BUFFER_SIZE));
		read(fd, buffer, BUFFER_SIZE);
		str = ft_strjoin(str, buffer);
		printf("ma str --> %s\n", str);
		free(buffer);
		len += BUFFER_SIZE;
	}
	// gérer la fin du fichier 
	strfinal = ft_strfinal(str);
	str = ft_strcop(str, len);
	return (strfinal);	
}
