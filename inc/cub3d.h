/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:28:43 by wzeraig           #+#    #+#             */
/*   Updated: 2025/02/12 15:14:13 by wzeraig          ###   ########.fr       */
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

# define PLAYEROTATE_SPEED 0.03
# define ROTATE_SPEED 0.04
# define WALL 1
# define FLOOR 0
# define PLAYER_N 'N'
# define PLAYER_S 'S'
# define PLAYER_E 'E'
# define PLAYER_W 'W'
# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define X 0
# define Y 1
# define IMG_SIZE 64
# define ERRDIR "ERROR\nit's a directory"
# define ERRFD "ERROR\nit's empty"
# define ERREXT "ERROR\nit's not the good format"
# define ERRORDR "ERROR\nit's not the good order"
# define ERRNOMAP "ERROR\nmissing map or textures"
# define ERRCOLTEX "ERROR\nmissing color or texture"
# define ERRINVTEX "ERROR\ninvalid texture"
# define ERRDUPTEX "ERROR\nduplicate texture"
# define ERRFORB "ERROR\ninvalid access"
# define ERR_MALLOC "ERROR\nmalloc failed"
# define ERRONLY "ERROR\nonly 1 or space in the first and last line\n"
# define FIRSTONE "ERROR\nNot beginning by 1\n"
# define ERRWALL "ERROR\n0 not surrounded by wall\n"
# define FINALONE "ERROR\nNot finishing by 1\n"
# define ERRORUNKNOWN "ERROR\nunknown character detected"
# define ERRPLAYER "ERROR\nnumber of player != 1"
# define ERRSMALL "ERROR\nMap are too biggysmall"
# define WIN_W 1280
# define RGB_SIZE 3
# define WIN_H 720

typedef struct s_map
{
	int		fcolor_i;
	int		ccolor_i;
	int		f_tab[RGB_SIZE];
	int		c_tab[RGB_SIZE];
	int		width;
	int		height;
}			t_map;

typedef struct s_img
{
	void	*mlx_img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		img_width;
	int		img_height;

}			t_img;

typedef struct s_ray
{
	double	pos[2];
	double	dir[2];
	double	plane[2];
	double	camera_offset[2];
	double	ray_dir[2];
	double	side_dist[2];
	double	delta_dist[2];
	int		map_pos[2];
	int		step[2];
	int		texture[2];
	int		move[2];
	int		rotate;
	int		moved;
	int		line_height;
	int		draw_start;
	int		draw_end;
	bool	hit_side;
	int		wall_hit;
	double	perp_wall_dist;
	int		texture_index;
	double	wall_hit_x;
	double	texture_step;
	double	texture_position;
	int		color;
	int		y;
}			t_ray;

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
	int		coltex;
	void	*mlx;
	int		**textures;
	void	*win;

	t_map	*map;
	t_img	*img;
	t_ray	*ray;

}			t_cub3d;

int			check_elements_order(t_cub3d *cub3d);
int			data_init(t_cub3d *cub3d, t_img *img, t_map *map, t_ray *ray);
int			get_texture(t_cub3d *cub3d, char **tmp_texture);
void		checkmap(t_cub3d *cub3d);
int			ft_isspace(char c);
void		msg_error(char *msg, t_cub3d *cub3d);
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
int			check_value(char *floor_or_ceilling, int floor, t_cub3d *cub3d);
int			check_nbr_value(char *floor_or_celling);
int			check_dir_textures(char **dir_path, t_cub3d *cub3d);
void		check_wall(t_cub3d *cub3d);
int			countplayer(char **map);
int			find(char **map);
void		free_elements(char ***tmp_texture, char **buff, t_cub3d *cub3d);
char		**splits_elements(char *buff);
void		separate_map_texture(int *j, int *i, char **map);
void		set_textures_info(int j, int i, char ***textures_info);
void		set_map(int i, char ***map, t_cub3d *cub3d);
void		initialize_ray_direction(t_ray *ray, int x);
void		calculate_initial_side_distances(t_ray *ray);
void		perform_dda(t_cub3d *cub3d, t_ray *ray);
void		render_wall_pixels(t_cub3d *cub3d, t_ray *ray, int x, int **buffer);
void		initialize_wall_draw(t_ray *ray);
void		init_vectors(t_cub3d *cub3d);
void		init_textures(t_cub3d *cub3d);
void		raycasting(t_cub3d *cub3d);
void		initialize_wall_draw(t_ray *ray);

void		render_wall_pixels(t_cub3d *cub3d, t_ray *ray, int x, int **buffer);
void		perform_dda(t_cub3d *cub3d, t_ray *ray);
void		calculate_initial_side_distances(t_ray *ray);
void		initialize_ray_direction(t_ray *ray, int x);
int			game_init(t_cub3d *cub3d);
int			handle_key_press(int keycode, t_cub3d *cub3d);
int			handle_key_release(int keycode, t_cub3d *cub3d);
int			movedisplay(t_cub3d *cub3d);
int			moving(t_cub3d *cub3d, t_ray *ray);
int			free_cub3d(t_cub3d *cub3d);
void		mapformat(t_cub3d *cub3d);
void		init_img_struct(t_img **img);
void	init_cub3d_struct(t_cub3d **cub3d);
void	init_map_struct(t_map **map);
void	init_ray_struct(t_ray **ray);



#endif