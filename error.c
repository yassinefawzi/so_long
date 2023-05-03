/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfawzi <yfawzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:48:46 by yfawzi            #+#    #+#             */
/*   Updated: 2023/04/19 04:19:19 by yfawzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_error(void)
{
	write(1, "invalide map", 12);
	exit(1);
}

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	lookfori(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j] && map[i][j] != 'P')
			j++;
		if (map[i][j] == 'P')
			break ;
		j = 0;
		i++;
	}
	return (i);
}

int	lookforj(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j] && map[i][j] != 'P')
		{
			j++;
		}
		if (map[i][j] == 'P')
			break ;
		j = 0;
		i++;
	}
	return (j);
}

int	ft_quit(void)
{
	exit(0);
}
