/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfawzi <yfawzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 07:57:02 by yfawzi            #+#    #+#             */
/*   Updated: 2023/05/03 22:02:28 by yfawzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	scheck(char **map1, char s, int i, int j)
{
	while (map1[i])
	{
		while (map1[i][j])
		{
			if (map1[i][j] == s)
			{
				ft_error();
			}
			j++;
		}
		j = 0;
		i++;
	}
}

char	**lookforpathe(int i, int j, char **map)
{
	if (map[i][j] && (map[i][j] != '1' && map[i][j] != 'X'))
		map[i][j] = 'X';
	else
		return (0);
	lookforpathe(i, j + 1, map);
	lookforpathe(i, j - 1, map);
	lookforpathe(i + 1, j, map);
	lookforpathe(i - 1, j, map);
	return (map);
}

int	map_name(char *str)
{
	int	i;

	if (!str)
		ft_putstr_fd("Error\n", 2);
	i = ft_strlenn(str) - 4;
	if (ft_strncmp(&str[i], ".ber", 4))
	{
		ft_putstr_fd("Invalide map name.\n", 2);
		exit(-1);
	}
	return (0);
}
