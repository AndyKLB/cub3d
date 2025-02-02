/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:28:43 by wzeraig           #+#    #+#             */
/*   Updated: 2025/02/01 12:25:48 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

# define ERRDIR "it's a directory"
# define ERRFD "it's empty"
# define ERREXT "it's not the good format"
# define ERRORDR "it's not the good order"
# define ERRNOMAP "missing map or textures"
# define ERRTEXT "err init textures"
# define ERR_MALLOC "malloc failed"

# define WIN_W 1280
# define WIN_H 720

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


typedef struct s_ray
{
	double	pos[2];
	double	dir[2];
	double	plane[2];
	double	camera[2];
	double	raydir[2];
	double	sidedist[2];
	double	deltadist[2];
	int		map[2];
	int		step[2];
	int		tex[2];
	int		move[2];
	int		rotate;
	int		moved;
	int		lineh;
	int		drawstart;
	int		drawend;
	bool	hit;
	int		side;
	double	perpwalldist;
	int		texnum;
	double	wallx;
	double	texstep;
	double	texpos;
	int		color;
	int		y;
}	t_ray;

# define PLAYEROTATE_SPEED 0.03
# define ROTATE_SPEED 0.04
# define WALL 1
# define FLOOR 0
# define PLAYER_N 'N'
# define PLAYER_S 'S'
# define PLAYER_E 'E'
# define PLAYER_W 'W'
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define X 0
# define Y 1
# define IMG_SIZE 64

int			check_elements_order(t_cub3d *cub3d);
int			data_init(t_cub3d *cub3d, t_img *img, t_map *map);
int			get_texture(t_cub3d *cub3d, char **tmp_texture);
void		checkmap(t_cub3d *cub3d);
int			ft_isspace(char c);
int			msg_error(char *error, t_cub3d *cub3d);
int			check_cardinal_caracters(char *line_map);
int			check_textures_caracters(char *line_map);
int			line_is_fullspace(char *line_map);
void		fill_space_one(char **map);
int			checkformat(t_cub3d *cub3d, char *path);
void		free_superstrs(char ***strs);
void		free_strs(char **strs);
void		map_reader(t_cub3d *cub3d, char *path);
int			is_news(char c);
int			is_character(char c);
int			valid_character(char c);
void		print_data(t_cub3d *cub3d, bool restr_aff);
void		get_chararacter_pos(char **map, t_cub3d *cub3d);
void		remove_comma(char *element);
int			check_value(char *floor_or_ceilling);
int			check_nbr_value(char *floor_or_celling);
int			check_dir_textures(char **dir_path);
void		check_wall(t_cub3d *cub3d);
int			countplayer(char **map);
int			find(char **map);
void		free_elements(char ***tmp_texture, char **buff, t_cub3d *cub3d);
char		**splits_elements(char *buff);
void		separate_map_texture(int *j, int *i, char **map);
void		set_textures_info(int j, int i, char ***textures_info);
void		set_map(int i, char ***map);

#endif