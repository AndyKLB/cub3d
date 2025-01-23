/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:28:43 by wzeraig           #+#    #+#             */
/*   Updated: 2025/01/23 15:30:45 by ankammer         ###   ########.fr       */
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
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERRDIR "it's a directory"
# define ERRFD "it's empty"
# define ERREXT "it's not the good format"
# define ERRORDR "it's not the good order"
# define ERRTEXT "err init textures"

typedef struct s_map
{
	char	*line;
	int		count;
	int		countline;
	int		index;

}			t_map;

typedef struct s_img
{
	void *mlx_img;   // ca je sais pas pk
	int width;       // epaisseur de limage 32
	int height;      // taille de limage 32
	int line_length; // en gros la largeur de limage
	void	*wall_no;
	void	*wall_ea;
	void	*wall_we;
	void	*wall_so;
	void	*floor;
	void	*celling;
	void	*player;

}			t_img;

typedef struct s_cub3d
{
	char	**maps;
	char	*south_element;
	char	*north_element;
	char	*west_element;
	char	*east_element;
	char	*floor;
	char	*celling;
	char	player_direction;
	int		player_x;
	int		player_y;
	int		win_height;
	int		win_width;
	void	*mlx;
	void	*win;

	t_map	*map;
	t_img	*img;
}			t_cub3d;

int			check_elements_order(t_cub3d *cub3d);
int			data_init(t_cub3d *cub3d, t_img *img, t_map *map);
int			get_texture(t_cub3d *cub3d, char **tmp_texture);
void		checkmap(t_cub3d *cub3d);
int			ft_isspace(char c);
int			msg_error(char *error, t_cub3d *cub3d);
int			check_cardinal_caracters(char *line_map);
int			check_textures_caracters(char *line_map);
int			line_is_fullspace(char *line_map);
void		print_map(t_cub3d *cub3d, bool restr_aff);
void		fill_space_one(char **map);
int			checkformat(t_cub3d *cub3d, char *path);
void		free_strs(char **strs);
void		map_reader(t_cub3d *cub3d, char *path);
int			is_news(char c);
int			is_character(char c);

#endif