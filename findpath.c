/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfawzi <yfawzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:00:13 by yfawzi            #+#    #+#             */
/*   Updated: 2023/05/03 23:58:17 by yfawzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	**retmap(char *arv)
{
	int		fd;
	char	*str;
	char	**mapv1;
	char	*tmp;

	fd = open(arv, O_RDONLY);
	if (!fd)
	{
		ft_putstr_fd("Error in map opening.\n", 2);
		exit(0);
	}
	str = get_next_line(fd);
	tmp = get_next_line(fd);
	while (tmp)
	{
		str = ft_strjoin(str, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	mapv1 = ft_split(str, '\n');
	free (str);
	return (mapv1);
}

int	count(char	**map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	**lookforpath(int i, int j, char **map)
{
	if (map[i][j] && (map[i][j] != '1' && map[i][j] != 'X')
	&& (map[i][j] != 'E'))
	{
		map[i][j] = 'X';
	}
	else
		return (0);
	lookforpath(i, j + 1, map);
	lookforpath(i, j - 1, map);
	lookforpath(i + 1, j, map);
	lookforpath(i - 1, j, map);
	return (map);
}

char	**ft_copy(char **map)
{
	char	**map1;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = count(map);
	map1 = malloc((len + 1) * sizeof(char *));
	while (map[i])
	{
		map1[i] = malloc(ft_strlen(map[i] + 1));
		while (map[i][j])
		{
			map1[i][j] = map[i][j];
			j++;
		}
		map1[i][j] = '\0';
		j = 0;
		i++;
	}
	map1[i] = NULL;
	return (map1);
}

void	find_path(char **map, int i, int j)
{
	char	**map1;
	char	**map2;

	map1 = ft_copy(map);
	map2 = ft_copy(map);
	i = lookfori(map1);
	j = lookforj(map1);
	map1 = lookforpath(i, j, map1);
	scheck(map1, 'C', 0, 0);
	ft_free(map1);
	map2 = lookforpathe(i, j, map2);
	scheck(map2, 'E', 0, 0);
	ft_free(map2);
}
