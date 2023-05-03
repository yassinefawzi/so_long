/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfawzi <yfawzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:32:05 by yfawzi            #+#    #+#             */
/*   Updated: 2023/05/03 22:11:05 by yfawzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	flline(char	*str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr_fd("Invalide map.\n", 2);
		exit(-1);
	}
	while (str[i])
	{
		if (str[i] == '1')
			i++;
		else
			ft_error();
	}
}

void	betweenmap(char **str, int len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i][0] == '1') && (str[i][len] == '1'))
			i++;
		else
			ft_error();
	}
}

void	checksymbol(char **map, t_symbol sym, int i, int j)
{
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				sym.col++;
			else if (map[i][j] == 'E' )
				sym.ext++;
			else if (map[i][j] == 'P')
				sym.plr++;
			else if (map[i][j] != '0' && map[i][j] != '1')
				ft_error();
			j++;
		}
		j = 0;
		i++;
	}
	if ((sym.col < 1) || (sym.ext > 0) || (sym.plr > 0))
		ft_error();
	if ((sym.ext < 0) || (sym.plr < 0))
		ft_error();
}

void	symbol(char **map)
{
	t_symbol	sym;

	sym.col = 0;
	sym.ext = -1;
	sym.plr = -1;
	checksymbol(map, sym, 0, 0);
}

void	checkmap(char **map, int linec)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlenn(map[i]);
	i = 0;
	while (map && map[i])
	{
		if (len == (ft_strlenn(map[i])))
			i++;
		else
			ft_error();
	}
	symbol(map);
	flline(map[0]);
	flline(map[linec - 1]);
	betweenmap(map, len - 1);
}
