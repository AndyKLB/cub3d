/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:19:34 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/30 14:38:38 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	go_to_end(int *i, char *dir_path, char c)
{
	while (dir_path[*i])
		(*i)++;
	while (dir_path[*i] != c && *i > 0)
		(*i)--;
}

int	check_dir_textures(char **dir_path)
{
	DIR		*dir;
	int		i;
	char	*dir_strim;

	if (!*dir_path)
		return (1);
	i = 0;
	*dir_path = ft_strtrim_free(*dir_path, " ");
	go_to_end(&i, *dir_path, '/');
	dir_strim = ft_rsubstr(*dir_path, i, (ft_strlen(*dir_path)));
	if (!dir_strim)
		return (1);
	dir = opendir(dir_strim);
	if (!dir)
		return (free(dir_strim), 1);
	closedir(dir);
	free(dir_strim);
	i = 0;
	go_to_end(&i, *dir_path, '.');
	if (ft_strictcmp((*dir_path + i), ".xpm"))
		return (1);
	return (0);
}
