/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfawzi <yfawzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:45:34 by yfawzi            #+#    #+#             */
/*   Updated: 2023/04/10 01:42:11 by yfawzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*salamcv(int fd, char *cih)
{
	char	*str;
	int		i;

	if (!cih)
		cih = ft_calloc(1, 1);
	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	i = 1;
	while (i != 0 && !ft_strchr(cih, '\n'))
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			free(cih);
			return (NULL);
		}
		str[i] = 0;
		cih = ft_strjoinn(cih, str);
	}
	free(str);
	return (cih);
}

char	*tetouan(char *cih)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cih[i] && cih[i] != '\n')
		i++;
	if (!cih[i])
	{
		free(cih);
		return (NULL);
	}
	str = malloc((ft_strlenn(cih) - i) + 1);
	if (!str)
	{
		free(cih);
		return (NULL);
	}
	i++;
	while (cih[i])
		str[j++] = cih[i++];
	str[j] = 0;
	free(cih);
	return (str);
}

char	*adoul(char *cih)
{
	char	*line;
	int		i;

	i = 0;
	if (!cih[i])
		return (NULL);
	while (cih[i] && cih[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (cih[i] && cih[i] != '\n')
	{
		line[i] = cih[i];
		i++;
	}
	if (cih[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*cih;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cih = salamcv(fd, cih);
	if (!cih)
		return (NULL);
	ret = adoul(cih);
	cih = tetouan(cih);
	return (ret);
}
