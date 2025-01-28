/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:58:33 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/28 12:31:23 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	set_map(int i, char ***map)
{
	int		k;
	char	**tmp;

	tmp = &(*map)[i];
	k = i - 1;
	while (k >= 0)
	{
		free((*map)[k]);
		(*map)[k] = NULL;
		k--;
	}
	*map = tmp;
}
void	set_textures_info(int j, int i, char ***textures_info)
{
	while (j >= i)
	{
		free((*textures_info)[j]);
		(*textures_info)[j] = NULL;
		j--;
	}
}

void	separate_map_texture(int *j, int *i, char **map)
{
	while (map[*j])
		(*j)++;
	while (check_cardinal_caracters(map[*i])
		|| check_textures_caracters(map[*i]) || line_is_fullspace(map[*i]))
		(*i)++;
}
char	**splits_elements(char *buff)
{
	char	**new;

	new = ft_split(buff, '\n');
	if (!new)
		return (NULL);
	return (new);
}

void	init_map_textures(t_cub3d *cub3d, char *buff)
{
	int		i;
	int		j;
	char	**tmp_texture;

	tmp_texture = NULL;
	i = 0;
	j = 0;
	tmp_texture = splits_elements(buff);
	if (!tmp_texture)
		return ;
	cub3d->maps = splits_elements(buff);
	if (!cub3d->maps)
	{
		free_strs(tmp_texture);
		return ;
	}
	if (check_elements_order(cub3d) == 1)
	{
		free_strs(tmp_texture);
		msg_error(ERRORDR, cub3d);
	}
	else if (check_elements_order(cub3d) == 2)
	{
		free_strs(tmp_texture);
		msg_error(ERRNOMAP, cub3d);
	}
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
	{
		free(buff);
		return ;
	}
	init_map_textures(cub3d, buff);
	free(buff);
	close(fd);
}
