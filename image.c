/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfawzi <yfawzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:11:00 by yfawzi            #+#    #+#             */
/*   Updated: 2023/05/03 23:03:44 by yfawzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	putimg(t_mlx mlx, char *str, int i, int j)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(mlx.mlxc, str, &width, &height);
	if (img == NULL)
	{
		ft_putstr_fd("Error, Invalid image", 2);
		exit(-3);
	}
	mlx_put_image_to_window(mlx.mlxc, mlx.mlx_win, img, j * 50, i * 50);
	mlx_destroy_image(mlx.mlxc, img);
}

void	find_player(char **map, int *i, int *j)
{
	while (map[*i])
	{
		while (map[*i][*j])
		{
			if (map[*i][*j] == 'P')
				return ;
			*j += 1;
		}
		*j = 0;
		*i += 1;
	}
}

int	countc(char **map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		j = 0;
		i++;
	}
	return (c);
}

void	ft_move(int key, t_mlx *mlx, t_pre pre)
{
	if (key == 124 && (mlx->map[pre.i][pre.j + 1] != '1'))
	{
		right(pre.i, pre.j, mlx);
		mlx->moves++;
		ft_write(mlx->moves);
	}
	else if (key == 123 && (mlx->map[pre.i][pre.j - 1] != '1'))
	{
		left(pre.i, pre.j, mlx);
		mlx->moves++;
		ft_write(mlx->moves);
	}
	else if (key == 126 && (mlx->map[pre.i - 1][pre.j] != '1'))
	{
		up(pre.i, pre.j, mlx);
		mlx->moves++;
		ft_write(mlx->moves);
	}
	else if (key == 125 && (mlx->map[pre.i + 1][pre.j] != '1'))
	{
		down(pre.i, pre.j, mlx);
		mlx->moves++;
		ft_write(mlx->moves);
	}
}

int	ft_press(int key, t_mlx *mlx)
{
	t_pre	pre;

	pre.i = 0;
	pre.j = 0;
	find_player(mlx->map, &pre.i, &pre.j);
	if (key == 53)
		(mlx_destroy_window(mlx->mlxc, mlx->mlx_win), exit(0));
	ft_move(key, mlx, pre);
	return (0);
}
