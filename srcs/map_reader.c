/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:58:33 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/23 12:12:32 by ankammer         ###   ########.fr       */
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
void	splits_elements(t_cub3d *cub3d, char *buff, char ***tmp_texture)
{
	*tmp_texture = ft_split(buff, '\n');
	if (!*tmp_texture)
		return ;
	cub3d->maps = ft_split((buff), '\n');
	if (!cub3d->maps)
	{
		free_strs(*tmp_texture);
		return ;
	}
}

void	init_map_textures(t_cub3d *cub3d, char *buff, char ***tmp_texture)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	splits_elements(cub3d, buff, tmp_texture);
	if (check_elements_order(cub3d))
		msg_error(ERRORDR); // free les splits
	separate_map_texture(&j, &i, cub3d->maps);
	set_map(i, &cub3d->maps);
	set_textures_info(j, i, tmp_texture);
    get_texture(cub3d, *tmp_texture);
}

void	map_reader(t_cub3d *cub3d, char *path)
{
	int fd;
	char *buff;
	char *line;
    char **tmp_texture_info;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ;
	buff = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		buff = ft_strjoin(buff, line);
		free(line);
	}
	init_map_textures(cub3d, buff, &tmp_texture_info);
	free(buff);
	close(fd);
}