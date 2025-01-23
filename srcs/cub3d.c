/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:14:57 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/23 12:56:56 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	print_map(t_cub3d *cub3d, bool restr_aff)
{
	int	i;

	i = 0;
	while (cub3d->maps[i])
	{
		ft_printf_fd(1, cub3d->maps[i]);
		ft_printf_fd(1, "\n");
		i++;
	}
	ft_printf_fd(1, "\n");
	if (restr_aff)
	{
		printf("celling = %s\nfloor = %s\n", cub3d->celling, cub3d->floor);
		printf("east = %s\nnorth = %s\nsouth = %s\nwest = %s\n",
			cub3d->east_element, cub3d->north_element, cub3d->south_element,
			cub3d->west_element);
		printf("direction = %c\nplayer  x = %d\nplayer y = %d\n",
			cub3d->player_direction, cub3d->player_x, cub3d->player_y);
	}
}

int	main(int argc, char **argv)
{
	t_cub3d cub3d;
	if (argc == 2)
	{
		if (data_init(argv[1], &cub3d))
			return (1);
		checkformat(argv[1]);
		// mettre les erreurs dans la fonction car il pourrait y avoir des erreur differente dans une seul fonction
		map_reader(&cub3d, argv[1]);
		print_map(&cub3d, 0);
		checkmap(&cub3d);
		print_map(&cub3d, 1);

		printf("Map valid \n");
		printf("\xF0\x9F\x92\xA9\n");
	}
	return (0);
}