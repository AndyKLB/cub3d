/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:14:57 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/22 12:53:26 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void map_reader(t_cub3d *cub3d)
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
	cub3d->map = ft_split(cub3d->buff, '\n');
	free(cub3d->buff);
	close(fd);
}

void print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_printf_fd(1, map[i]);
		ft_printf_fd(1, "\n");
		i++;
	}
	ft_printf_fd(1, "\n");
}

int main(int argc, char **argv)
{
	t_cub3d cub3d;
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