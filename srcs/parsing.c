/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:10:43 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/30 14:59:38 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	checkformat(t_cub3d *cub3d, char *path)
{
	int	len;
	int	fd;

	len = ft_strlen(path);
	if (open(path, __O_DIRECTORY) >= 0)
	{
		fd = open(path, __O_DIRECTORY);
		close(fd);
		msg_error(ERRDIR, cub3d);
	}
	else
	{
		if (ft_strncmp(path + len - 4, ".cub", 4) != 0)
			msg_error(ERREXT, cub3d);
		fd = open(path, O_RDONLY);
		if (fd < 0)
			msg_error("Unknown error -1: Permission denied\n", cub3d);
		if (read(fd, 0, 0) < 0)
			msg_error("Unknown error -1: Bad file descriptor\n", cub3d);
		close(fd);
	}
	return (Success);
}

void	checkmap(t_cub3d *cub3d)
{
	if (!cub3d->maps)
		msg_error(ERRNOMAP, cub3d);
	if (find(cub3d->maps))
		msg_error("find", cub3d);
	if (countplayer(cub3d->maps) != 1)
		msg_error("countplayer", cub3d);
	check_wall(cub3d);
	fill_space_one(cub3d->maps);
}
