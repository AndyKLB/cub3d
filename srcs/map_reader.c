/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:58:33 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/30 15:37:19 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_map_textures(t_cub3d *cub3d, char *buff)
{
	int		i;
	int		j;
	char	**tmp_texture;

	i = 0;
	j = 0;
	tmp_texture = NULL;
	cub3d->maps = splits_elements(buff);
	if (!cub3d->maps)
		return ;
	if (check_elements_order(cub3d))
		free_elements(&tmp_texture, &buff, cub3d);
	tmp_texture = splits_elements(buff);
	if (!tmp_texture)
	{
		free(buff);
		free_strs(cub3d->maps);
		return ;
	}
	free(buff);
	separate_map_texture(&j, &i, cub3d->maps);
	set_map(i, &cub3d->maps);
	set_textures_info(j, i, &tmp_texture);
	get_texture(cub3d, tmp_texture);
	free_strs(tmp_texture);
}

void	map_reader(t_cub3d *cub3d, char *path)
{
	int		fd;
	char	*buff;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ;
	buff = ft_strdup("");
	if (!buff)
	{
		close(fd);
		return ;
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		buff = ft_strjoinfree(buff, line);
		free(line);
	}
	if (!*buff)
		return (free(buff), (void)0);
	init_map_textures(cub3d, buff);
	close(fd);
}
