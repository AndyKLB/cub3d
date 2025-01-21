/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:28:43 by wzeraig           #+#    #+#             */
/*   Updated: 2025/01/21 13:08:04 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_cub3d
{
	char	*line;
	char	*str;
	char	**map;

}			t_cub3d;

typedef struct map
{
	int		count;
	char	*line;
	int		countline;
	int		index;

}			t_map;

typedef struct s_img
{
	void *mlx_img; // ca je sais pas pk
	int width;     // epaisseur de limage 32
	int height;    // taille de limage 32
	void	*wall;
	void	*exit;
	void	*ground;
	void	*player;
	int line_length; // en gros la largeur de limage
	void	*coin;

}			t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		win_height;
	int		win_width;
	int		player_i;
	int		player_j;

	t_map	*map;
	t_img	*img;
}			t_data;

int			check_order_elements(char **map);

#endif