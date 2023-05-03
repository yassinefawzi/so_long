/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfawzi <yfawzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:30:10 by yfawzi            #+#    #+#             */
/*   Updated: 2023/05/03 23:07:11 by yfawzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	checkfwall(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '1')
			i++;
		else
		{
			write(1, "map error", 9);
			exit(1);
		}
	}
}

int	linecount(char *arv)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open(arv, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
	{
		ft_putstr_fd("invalide map\n", 2);
		exit(-1);
	}
	while (str && str[0] != '\n')
	{
		i++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	putmap(t_mlx mlx)
{
	while (mlx.map[mlx.i])
	{
		mlx.j = 0;
		while (mlx.map[mlx.i][mlx.j])
		{
			if (mlx.map[mlx.i][mlx.j] == '1')
				putimg(mlx, "./images/tower.xpm", mlx.i, mlx.j);
			else if (mlx.map[mlx.i][mlx.j] == 'C')
				putimg(mlx, "./images/col.xpm", mlx.i, mlx.j);
			else if (mlx.map[mlx.i][mlx.j] == 'P')
				putimg(mlx, "./images/playerimg.xpm", mlx.i, mlx.j);
			else if (mlx.map[mlx.i][mlx.j] == 'E')
				putimg(mlx, "./images/exit.xpm", mlx.i, mlx.j);
			mlx.j++;
		}
		mlx.i++;
	}
}

void	put_back(t_mlx mlx)
{
	while (mlx.map[mlx.i])
	{
		mlx.j = 0;
		while (mlx.map[mlx.i][mlx.j])
		{
			if (mlx.map[mlx.i][mlx.j])
				putimg(mlx, "./images/mapback.xpm", mlx.i, mlx.j);
			mlx.j++;
		}
		mlx.i++;
	}
}

int	main(int arc, char **arv)
{
	t_mlx	mlx;
	int		linec;

	if (arc == 2 && !map_name(arv[1]))
	{
		mlx.i = 0;
		linec = linecount(arv[1]);
		mlx.map = retmap(arv[1]);
		checkmap(mlx.map, linec);
		find_path(mlx.map, 0, 0);
		mlx.mlxc = mlx_init();
		mlx.mlx_win = mlx_new_window(mlx.mlxc, ft_strlenn(mlx.map[mlx.i]) * 50,
				count(mlx.map) * 50, "so_long");
		put_back(mlx);
		mlx.i = 0;
		mlx.j = 0;
		mlx.moves = 0;
		putmap(mlx);
		mlx_hook(mlx.mlx_win, 17, 0, ft_quit, &mlx);
		mlx_hook(mlx.mlx_win, 02, 0, ft_press, &mlx);
		mlx_loop(mlx.mlxc);
	}
	else
		ft_putstr_fd("Invalide number of arguments.\n", 2);
	return (0);
}
