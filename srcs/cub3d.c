/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:14:57 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/23 10:53:19 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf_fd(1, map[i]);
		ft_printf_fd(1, "\n");
		i++;
	}
	ft_printf_fd(1, "\n");
}

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
void	splits_elements(t_cub3d *cub3d)
{
	cub3d->textures_info = ft_split(cub3d->buff, '\n');
	cub3d->map = ft_split((cub3d->buff), '\n');
}

void	init_map_textures(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	splits_elements(cub3d);
	if (check_elements_order(cub3d))
		msg_error(ERRORDR, cub3d); // free les splits
	separate_map_texture(&j, &i, cub3d->map);
	set_map(i, &cub3d->map);
	set_textures_info(j, i, &cub3d->textures_info);
}

void	map_reader(t_cub3d *cub3d)
{
	int fd;

	fd = open(cub3d->path, O_RDONLY);
	if (fd == -1)
		return;
	cub3d->buff = ft_strdup("");
	while (1)
	{
		cub3d->line = get_next_line(fd);
		if (!cub3d->line)
			break;
		cub3d->buff = ft_strjoin(cub3d->buff, cub3d->line);
		free(cub3d->line);
	}
	init_map_textures(cub3d);
	free(cub3d->buff);
	close(fd);
}


int main(int argc, char **argv)
{
	t_cub3d cub3d;
	//t_data data;
	if (argc == 2)
	{
		if (data_init(argv[1], &cub3d))
			return (1);
		checkformat(&cub3d, cub3d.path); // mettre les erreurs dans la fonction car il pourrait y avoir des erreur differente dans une seul fonction
		map_reader(&cub3d);
		checkmap(&cub3d);

		printf("Map valid \n");
		printf("\xF0\x9F\x92\xA9\n");
		// if (get_texture(&cub3d))
		//     return (1);
	}
	return (0);
}