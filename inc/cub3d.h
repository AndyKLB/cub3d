/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:28:43 by wzeraig           #+#    #+#             */
/*   Updated: 2025/01/22 12:52:42 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../lib/libft/libft.h"
#include "../lib/mlx/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define ERRDIR "it's a directory"
#define ERRFD "it's empty"
#define ERREXT "it's not the good format"


typedef struct s_cub3d
{
	char *line;
	char *path;
	char *buff;
	char **map;

} t_cub3d;

typedef struct map
{
	int count;
	char *line;
	int countline;
	int index;

} t_map;

typedef struct s_img
{
	char *south_element;
	char *north_element;
	char *west_element;
	char *east_element;
	char *floor;
	char *celling;
	void *mlx_img; // ca je sais pas pk
	int width;	   // epaisseur de limage 32
	int height;	   // taille de limage 32
	void *wall;
	void *exit;
	void *ground;
	void *player;
	int line_length; // en gros la largeur de limage
	void *coin;

} t_img;

typedef struct s_data
{
	void *mlx;
	void *win;
	int win_height;
	int win_width;
	int player_x;
	int player_y;
	char player_direction;

	t_map *map;
	t_img *img;
} t_data;

int check_elements_order(t_cub3d *cub3d);
int data_init(char *path, t_cub3d *cub3d);
int get_texture(t_cub3d *cub3d, t_img *img, t_data *data);
void checkmap(t_cub3d *cub3d);
int ft_isspace(char c);
int msg_error(char *error, t_cub3d *cub3d);
int checkformat(t_cub3d *cub3d, char *path);


#endif