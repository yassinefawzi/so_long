/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfawzi <yfawzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 02:29:29 by yfawzi            #+#    #+#             */
/*   Updated: 2023/05/03 23:06:36 by yfawzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	right(int i, int j, t_mlx *mlx)
{
	int	ccount;

	ccount = countc(mlx->map);
	if (ccount == 0 && mlx->map[i][j + 1] == 'E')
	{
		ft_write(mlx->moves + 1);
		exit(0);
	}
	if (mlx->map[i][j + 1] != 'E' && mlx->map[i][j + 1])
	{
		mlx->map[i][j + 1] = 'P';
		mlx->map[i][j] = '0';
		putimg(*mlx, "./images/mapback.xpm", i, j);
		putimg(*mlx, "./images/playerimg.xpm", i, j + 1);
	}
}

void	left(int i, int j, t_mlx *mlx)
{
	int	ccount;

	ccount = countc(mlx->map);
	if (ccount == 0 && mlx->map[i][j - 1] == 'E')
	{
		ft_write(mlx->moves + 1);
		exit(0);
	}
	if (mlx->map[i][j - 1] != 'E' && mlx->map[i][j - 1])
	{
		mlx->map[i][j - 1] = 'P';
		mlx->map[i][j] = '0';
		putimg(*mlx, "./images/mapback.xpm", i, j);
		putimg(*mlx, "./images/playerimg.xpm", i, j - 1);
	}
}

void	up(int i, int j, t_mlx *mlx)
{
	int	ccount;

	ccount = countc(mlx->map);
	if (ccount == 0 && mlx->map[i - 1][j] == 'E')
	{
		ft_write(mlx->moves + 1);
		exit(0);
	}
	if (mlx->map[i - 1][j] != 'E' && mlx->map[i - 1][j])
	{
		mlx->map[i - 1][j] = 'P';
		mlx->map[i][j] = '0';
		putimg(*mlx, "./images/mapback.xpm", i, j);
		putimg(*mlx, "./images/playerimg.xpm", i - 1, j);
	}
}

void	down(int i, int j, t_mlx *mlx)
{
	int	ccount;

	ccount = countc(mlx->map);
	if (ccount == 0 && mlx->map[i + 1][j] == 'E')
	{
		ft_write(mlx->moves + 1);
		exit(0);
	}
	if (mlx->map[i + 1][j] != 'E' && mlx->map[i + 1][j])
	{
		mlx->map[i + 1][j] = 'P';
		mlx->map[i][j] = '0';
		putimg(*mlx, "./images/mapback.xpm", i, j);
		putimg(*mlx, "./images/playerimg.xpm", i + 1, j);
	}
}

void	ft_write(int moves)
{
	char	*f;

	f = ft_itoa(moves);
	ft_putstr_fd(f, 1);
	write(1, "\n", 1);
}
