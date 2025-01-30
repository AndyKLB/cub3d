/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:34:31 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/30 15:39:39 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_and_free(char ****map, char ***tmp, int *k, int i)
{
	int	j;

	j = i;
	while ((**map)[j])
	{
		(*tmp)[*k] = (**map)[j];
		j++;
		(*k)++;
	}
	i--;
	while (i >= 0)
	{
		free((**map)[i]);
		(**map)[i] = NULL;
		i--;
	}
	(*tmp)[*k] = NULL;
	free(**map);
	**map = *tmp;
	*tmp = NULL;
}

void	set_map(int i, char ***map)
{
	int		k;
	char	**tmp;
	int		size;
	int		j;

	size = 0;
	j = i;
	while ((*map)[size])
		size++;
	tmp = malloc(sizeof(char *) * (size - i + 1));
	if (!tmp)
		return ;
	k = 0;
	init_and_free(&map, &tmp, &k, i);
}

void	set_textures_info(int j, int i, char ***textures_info)
{
	int		k;
	char	**tmp;

	tmp = malloc(sizeof(char *) * (i + 1));
	if (!tmp)
		return ;
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
