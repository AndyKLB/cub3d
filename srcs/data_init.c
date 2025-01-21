/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:33:42 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/21 15:54:24 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	copy_element(char *element)
{
}

int	get_cardinal(char *line_map, t_cub3d *cub3d)
{
	if ((line_map[0] == 'N' || line_map[0] == 'S') && line_map[1] == 'O')
	{
		if (line_map[0] == 'N')
			copy_element();
		else
			copy_element();
	}
	else if (line_map[0] == 'W' && line_map[1] == 'E')
		copy_element();
	else if (line_map[0] == 'E' && line_map[1] == 'A')
		copy_element();
	return (0);
}

int	get_texture(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->map[i])
	{
	}
}

int	data_init(char *path, t_cub3d *cub3d)
{
	if (!path || !*path)
		return (1);
	cub3d->path = path;
	cub3d->buff = NULL;
	cub3d->line = NULL;
	cub3d->map = NULL;
	return (0);
}