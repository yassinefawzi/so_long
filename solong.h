/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfawzi <yfawzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:33:08 by yfawzi            #+#    #+#             */
/*   Updated: 2023/05/03 22:02:32 by yfawzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include "mlx.h"
# include "getnext_line/get_next_line.h"

typedef struct s_arg {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_arg;

typedef struct s_symbol {
	int	i;
	int	j;
	int	col;
	int	ext;
	int	plr;
}	t_symbol;

typedef struct s_mlx
{
	void	*mlxc;
	void	*mlx_win;
	char	**map;
	int		i;
	int		j;
	int		pi;
	int		pj;
	int		moves;
}	t_mlx;

typedef struct s_pre
{
	int	i;
	int	j;
	int	moves;
}	t_pre;

char	**retmap(char *arv);
void	flline(char *str);
void	betweenmap(char **str, int len);
void	checkmap(char **map, int linec);
void	ft_error(void);
void	find_path(char **map, int i, int j);
char	**lookforpath(int i, int j, char **map);
int		count(char	**map);
void	putimg(t_mlx mlx, char	*str, int i, int j);
int		ft_quit(void);
int		ft_press(int key, t_mlx *mlx);
int		map_name(char *str);
void	ft_free(char **map);
void	right(int i, int j, t_mlx *mlx);
void	left(int i, int j, t_mlx *mlx);
void	up(int i, int j, t_mlx *mlx);
void	down(int i, int j, t_mlx *mlx);
int		countc(char **map);
int		lookfori(char **map);
int		lookforj(char **map);
int		ft_quit(void);
void	ft_write(int moves);
char	**lookforpathe(int i, int j, char **map);
void	scheck(char **map1, char s, int i, int j);
#endif