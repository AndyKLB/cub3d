/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:58:33 by ankammer          #+#    #+#             */
/*   Updated: 2025/02/17 16:11:09 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	remove_comma(char *element)
{
	int	i;

	i = 0;
	if (!element)
		return ;
	while (element[i])
	{
		if (element[i] == ',')
			element[i] = ' ';
		i++;
	}
}

int	ftfuldgt(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_isdigit(str[i]))
		return (1);
	return (0);
}

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
		free_superstrs(&cub3d->maps);
		return ;
	}
	free(buff);
	separate_map_texture(&j, &i, cub3d->maps);
	set_map(i, &cub3d->maps, cub3d);
	set_textures_info(j, i, &tmp_texture);
	get_texture(cub3d, tmp_texture);
	free_superstrs(&tmp_texture);
}

char	*line_reader(char **buff, int fd, t_cub3d *cub3d, int flag)
{
	while (1)
	{
		cub3d->utils->line = get_next_line(fd);
		if (!cub3d->utils->line)
			break ;
		if (ftfuldgt(cub3d->utils->line) && flag == 0)
			flag = 1;
		else if (flag == 2 && (cub3d->utils->line[0] != '\n'
				|| lineisspace(cub3d->utils->line)))
		{
			if (!ftfuldgt(cub3d->utils->line))
				flag = 3;
			if (ftfuldgt(cub3d->utils->line) || lineisspace(cub3d->utils->line))
				flag = 4;
		}
		else if (flag == 1 && cub3d->utils->line[0] == '\n')
			flag = 2;
		*buff = ft_strjoinfree(*buff, cub3d->utils->line);
		free(cub3d->utils->line);
	}
	if (flag == 3)
		(free(*buff), msg_error(ERRORDR, cub3d));
	if (flag == 4)
		(free(*buff), msg_error(ERR_MAP, cub3d));
	return (*buff);
}

void	map_reader(t_cub3d *cub3d, char *path)
{
	int		fd;
	char	*buff;
	int		flag;

	flag = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ;
	buff = ft_strdup("");
	if (!buff)
	{
		close(fd);
		return ;
	}
	line_reader(&buff, fd, cub3d, flag);
	if (!*buff)
		return (free(buff), close(fd), (void)0);
	close(fd);
	init_map_textures(cub3d, buff);
}
