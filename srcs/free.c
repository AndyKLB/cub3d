/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:47:03 by ankammer          #+#    #+#             */
/*   Updated: 2025/02/06 14:49:43 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_superstrs(char ***strs)
{
	int	i;

	i = 0;
	if (!*strs || !**strs)
		return ;
	while ((*strs)[i])
	{
		free((*strs)[i]);
		(*strs)[i] = NULL;
		i++;
	}
	free(*strs);
	*strs = NULL;
	return ;
}

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	if (!strs || !*strs)
		return ;
	while (strs[i])
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	free(strs);
	strs = NULL;
	return ;
}

void	free_cub3d(t_cub3d *cub3d)
{
	// free mlx
	// free win
	if (cub3d->celling)
		free(cub3d->celling);
	if (cub3d->floor)
		free(cub3d->floor);
	if (cub3d->east_element)
		free(cub3d->east_element);
	if (cub3d->west_element)
		free(cub3d->west_element);
	if (cub3d->north_element)
		free(cub3d->north_element);
	if (cub3d->south_element)
		free(cub3d->south_element);
	if (cub3d->maps && *cub3d->maps)
		free_superstrs(&cub3d->maps);
}

int	msg_error(char *msg, t_cub3d *cub3d)
{
	free_cub3d(cub3d);
	if (msg)
		ft_printf_fd(2, "%s\n", msg);
	exit(1);
}

void	free_elements(char ***tmp_texture, char **buff, t_cub3d *cub3d)
{
	free_strs(*tmp_texture);
	free(*buff);
	msg_error(NULL, cub3d);
}
