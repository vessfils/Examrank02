/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:22:54 by vess              #+#    #+#             */
/*   Updated: 2022/01/06 10:24:54 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t	ft_strlen (const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;
	
	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int	i;
	size_t	len;

	str = 0;
	i = -1;
	str = malloc((ft_strlen (s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	len = 0;
	while (s1 && s1[len])
	{
		str[len] = s1[len];
		len++;
	}
	while (s2 && s2[++i])
	{
		str[len++] = s2[i];
	}
	str[len] = 0;
	return (str);
}

/*
 *On recupere une ligne
 */
char	*ft_get_line(char *left_str)
{
	int	i;
	char	*str;

	i = 0;
	if	(!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = malloc (sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

/*
 * on garde uniquement le reste de la ligne attention a free a la fin left_str et si il existe ap
 */

char	*ft_new_left_str(char *left_str)
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = malloc (sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = 0;
	free(left_str);
	return (str);
}

/*
 *On malloc le buffer avec BUFFER_SIZE puis on lit tant que on trouve pas \n ou bien que on arrive a la fin du fichier
 */

char    *ft_read_to_left_str(int fd, char *left_str)
{
	char *buf;
	int rd_bytes;
	char *tmp;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buf, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rd_bytes] = 0;
		tmp = left_str;
		left_str = ft_strjoin(tmp, buf);
		free(tmp);
	}
	free(buf);
	return (left_str);
}

/*
 *On gere les erreurs, on lit la ligne, on recupere la ligne puis on stock le reste dans la variable static
 */

char	*get_next_line(int fd)
{
	static char	*left_str;
	char	*line;

	if (fd < 0 && BUFFER_SIZE < 1)
		return (NULL);
	left_str = ft_read_to_left_str (fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}


int main ()
{
	char	*line = NULL;
	int fd = open("texte.txt", O_RDONLY);

	//printf("%ld\n", ft_strlen(str));
	//printf("%s\n", ft_strchr(str, 'l'));
	//printf("%s\n", ft_strjoin(str, str1));
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}

