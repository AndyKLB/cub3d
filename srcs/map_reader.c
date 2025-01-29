/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:58:33 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/29 15:26:06 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void set_map(int i, char ***map)
{
	int k;
	char **tmp;
	int size;
	int j;

	size = 0;
	j = i;
	while ((*map)[size]) // Calculer la taille totale
		size++;
	printf("i = %d size = %d\n", i, size);
	tmp = malloc(sizeof(char *) * (size - i + 1));
	if (!tmp)
		return;
	k = 0;
	while ((*map)[j])
	{
		tmp[k] = (*map)[j]; // Copier les pointeurs, pas de nouvelle allocation de chaînes
		j++;
		k++;
	}
	i--;
	while (i >= 0)
	{
		free((*map)[i]);
		(*map)[i] = NULL;
		i--;
	}
	tmp[k] = NULL;
	free(*map); // Libérer l'ancien tableau (sans libérer les chaînes)
	*map = tmp;
	tmp = NULL;
}
void set_textures_info(int j, int i, char ***textures_info)
{
	int k;
	char **tmp;

	tmp = malloc(sizeof(char *) * (i + 1));
	if (!tmp)
		return;
	k = 0;
	while (k < i)
	{
		tmp[k] = (*textures_info)[k];
		k++;
	}
	tmp[k] = NULL;
	while (i <= j)
	{
		free((*textures_info)[i]);
		(*textures_info)[i] = NULL;
		i++;
	}
	free(*textures_info);
	*textures_info = tmp;
}

void separate_map_texture(int *j, int *i, char **map)
{
	while (map[*j])
		(*j)++;
	while (check_cardinal_caracters(map[*i]) || check_textures_caracters(map[*i]) || line_is_fullspace(map[*i]))
		(*i)++;
}
char **splits_elements(char *buff)
{
	char **new;
	if (!buff || !*buff)
		return (NULL);
	new = ft_split(buff, '\n');
	if (new && !*new)
	{
		free(new);
		return (NULL);
	}
	return (new);
}

void init_map_textures(t_cub3d *cub3d, char *buff)
{
	int i;
	int j;
	char **tmp_texture;

	tmp_texture = NULL;
	i = 0;
	j = 0;
	cub3d->maps = splits_elements(buff);
	if (!cub3d->maps)
		return;
	if (check_elements_order(cub3d) == 1)
	{
		free_strs(tmp_texture);
		free(buff);
		msg_error(ERRORDR, cub3d);
	}
	else if (check_elements_order(cub3d) == 2)
	{
		free_strs(tmp_texture);
		free(buff);
		msg_error(ERRNOMAP, cub3d);
	}
	tmp_texture = splits_elements(buff);
	if (!tmp_texture)
	{
		free_strs(cub3d->maps);
		return;
	}
	free(buff);
	separate_map_texture(&j, &i, cub3d->maps);
	set_map(i, &cub3d->maps);
	set_textures_info(j, i, &tmp_texture);
	get_texture(cub3d, tmp_texture);
	free_strs(tmp_texture);
}

void map_reader(t_cub3d *cub3d, char *path)
{
	int fd;
	char *buff;
	char *line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return;
	buff = ft_strdup("");
	if (!buff)
	{
		close(fd);
		return;
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		buff = ft_strjoinfree(buff, line);
		free(line);
	}
	if (!*buff)
		return (free(buff), (void)0);
	init_map_textures(cub3d, buff);
	close(fd);
}
