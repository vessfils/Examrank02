/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:22:22 by vess              #+#    #+#             */
/*   Updated: 2022/03/14 16:54:17 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *ft_save(char *save)
{
	int i;
	int j;
	char *str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!str)
		return (NULL);
	j = 0;
	i++;
	while (save[i])
		str[j++] = save[i++];
	str[j] = '\0';
	free(save);
	return (str);
}


char *ft_get_line(char *save)
{
	int i;
	char *str;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
char *ft_read_save(int fd, char *save)
{
	int rd_bytes;
	char *buf;
	
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(save, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buf, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rd_bytes] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	return (save);
}

char *get_next_line(int fd)
{
	char *line;
	static char *save;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	save = ft_read_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}

/*
int main()
{
	char *line = NULL;
	int fd;

	fd = open("texte.txt", O_RDONLY);

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}
*/