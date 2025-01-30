/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:14:57 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/30 14:40:54 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;
	t_map	map;
	t_img	img;

	if (argc == 2)
	{
		if (data_init(&cub3d, &img, &map))
			return (1);
		checkformat(&cub3d, argv[1]); // mettre les erreurs dans la fonction car il pourrait y avoir des erreur differente dans une seul fonction
		map_reader(&cub3d, argv[1]);
		print_data(&cub3d, 1);
		checkmap(&cub3d);
		print_data(&cub3d, 0);
		printf("Map valid \n");
		printf("\xF0\x9F\x92\xA9\n");
		free_strs(cub3d.maps);
		cub3d.maps = NULL;
		msg_error("OK", &cub3d);
	}
	return (0);
}
