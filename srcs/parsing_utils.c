/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:35:19 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/30 14:39:50 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	surrounded_or_not(char **maps, int j, int i, int flag)
{
	if (flag)
	{
		while (maps[j][i])
		{
			if ((maps[j][i] == '0' && i > (int)ft_strlen(maps[j - 1]) - 1)
				|| (maps[j][i] == '0' && i > (int)ft_strlen(maps[j + 1]) - 1))
				return (1);
			i++;
		}
	}
	else
	{
		while (maps[j][i])
		{
			if (maps[j][i] != ' ' && maps[j][i] != '1')
				return (1);
			i++;
		}
	}
	return (0);
}

void	check_wall(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	if (!cub3d->maps)
		return ;
	while (cub3d->maps[++j])
	{
		while (ft_isspace(cub3d->maps[j][i]))
			i++;
		if (cub3d->maps[j][i] != '1')
			msg_error("first 1\n", cub3d);
		if (j == 0 || !cub3d->maps[j + 1])
		{
			if (surrounded_or_not(cub3d->maps, j, i, 0))
				msg_error("in first or last only 1 or space\n", cub3d);
		}
		else if (surrounded_or_not(cub3d->maps, j, i, 1))
			msg_error("0 not surrounded by wall\n", cub3d);
		i = ft_strlen(cub3d->maps[j]) - 1;
		if (cub3d->maps[j][i] != '1')
			msg_error("last 1\n", cub3d);
		i = 0;
	}
}

int	find(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!map)
		return (1);
	while (map[j])
	{
		while (map[j][i])
		{
			if (!valid_character(map[j][i]))
				return (1);
			i++;
		}
		j++;
		i = 0;
	}
	return (0);
}

int	countplayer(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	if (!map)
		return (1);
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'S' || map[j][i] == 'E'
				|| map[j][i] == 'W')
				count++;
			i++;
		}
		j++;
		i = 0;
	}
	return (count);
}
