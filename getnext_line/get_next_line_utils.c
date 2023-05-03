/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfawzi <yfawzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:18:31 by yfawzi            #+#    #+#             */
/*   Updated: 2023/05/03 21:57:27 by yfawzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoinn(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	if (s2 == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
		i++;
	s = (char *)malloc((i + (ft_strlenn(s2) + 1)));
	j = 0;
	while (i > 0 && s1[j])
	{
		s[j] = s1[j];
		j++;
	}
	free(s1);
	i = 0;
	while (s2[i])
	{
		s[j + i] = s2[i];
		i++;
	}
	s[j + i] = '\0';
	return (s);
}

int	ft_strlenn(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cha;

	i = 0;
	cha = (char )c;
	while (s[i])
	{
		if (s[i] == cha)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cha)
		return ((char *)&s[i]);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size * count > SIZE_MAX)
		return (0);
	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	ft_memset(p, '\0', count * size);
	return (p);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	char			*s;

	s = (char *)(b);
	ch = c;
	while (len)
	{
		*s = ch;
		s++;
		len--;
	}
	return (b);
}
