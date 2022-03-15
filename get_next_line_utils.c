/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:22:18 by vess              #+#    #+#             */
/*   Updated: 2022/03/14 16:41:35 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while(str[i])
		i++;
	return (i);
}

char *ft_strchr (char *str, int c)
{
	int i;

	i = 0;

	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char *ft_strjoin(char *s1, char *s2)
{
	int i;
	size_t len;

	char *str;

	str = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);

	len = 0;
	while (s1 && s1[len])
	{
		str[len] = s1[len];
		len++;
	}
	i = -1;
	while (s2 && s2[++i])
		str[len++] = s2[i];
	str[len] = '\0';
	free(s1);
	return (str);	
}