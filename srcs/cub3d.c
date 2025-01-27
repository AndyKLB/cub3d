/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:14:57 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/27 14:01:59 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	print_img_struct(t_img *img)
{
	printf("###IMG STRUCT##\n");
	printf("img = %p\nimg height = %d\nimg width = %d\nlinelength = %d\n\n",img, img->height,
		img->width, img->line_length);
}
void	print_map_struct(t_map *map)
{
	printf("###MAP STRUCT##\n");
	printf("map = %p\ncount = %d\ncountline = %d\nindex = %d\nline = %s\n\n",map, map->count,
		map->countline, map->index, map->line);
}
void	print_cub3d_struct(t_cub3d *cub3d)
{
	printf("###CUB3D STRUCT##\n");
	printf("map = %p\nimg = %p\n", cub3d->map, cub3d->img);
	printf("celling = %s\nfloor = %s\n", cub3d->celling, cub3d->floor);
	printf("east = %s\nnorth = %s\nsouth = %s\nwest = %s\n",
		cub3d->east_element, cub3d->north_element, cub3d->south_element,
		cub3d->west_element);
	printf("direction = %c\nplayer  x = %d\nplayer y = %d\n\n\n",
		cub3d->player_direction, cub3d->player_x, cub3d->player_y);
}
void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf_fd(1, map[i]);
		ft_printf_fd(1, "\n");
		i++;
	}
	ft_printf_fd(1, "\n");
}

void	print_data(t_cub3d *cub3d, bool restr_aff)
{
	if (restr_aff)
	{
		print_cub3d_struct(cub3d);
		print_img_struct(cub3d->img);
		print_map_struct(cub3d->map);
		if (cub3d->maps)
		{
			ft_printf_fd(1, "##BEFORE FILL_ONE##\n\n");
			print_map(cub3d->maps);
		}
	}
	else if (cub3d->maps)
	{
		ft_printf_fd(1, "##AFTER FILL_ONE##\n\n");
		print_map(cub3d->maps);
	}
}

int	main(int argc, char **argv)
{
	t_cub3d cub3d;
	t_map map;
	t_img img;
	if (argc == 2)
	{
		if (data_init(&cub3d, &img, &map))
			return (1);
		checkformat(&cub3d, argv[1]);
		// mettre les erreurs dans la fonction car il pourrait y avoir des erreur differente dans une seul fonction
		map_reader(&cub3d, argv[1]);
		print_data(&cub3d, 1);
		checkmap(&cub3d);
		print_data(&cub3d, 0);

		printf("Map valid \n");
		printf("\xF0\x9F\x92\xA9\n");
	}
	return (0);
}