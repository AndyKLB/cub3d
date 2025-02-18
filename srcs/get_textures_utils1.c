/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:19:37 by ankammer          #+#    #+#             */
/*   Updated: 2025/02/18 11:19:56 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_nbr_value(char *floor_or_celling)
{
	int	i;
	int	nb_spc;
	int	is_not_digit;

	is_not_digit = 0;
	nb_spc = 0;
	i = 0;
	while (floor_or_celling[i])
	{
		if (!ft_isdigit(floor_or_celling[i]) && !ft_isspace(floor_or_celling[i])
			&& floor_or_celling[i] != '-')
			is_not_digit++;
		if (floor_or_celling[i] == ' ' && floor_or_celling[i + 1]
			&& floor_or_celling[i + 1] != ' ')
			nb_spc++;
		i++;
	}
	if (nb_spc != 2 || is_not_digit)
		return (1);
	return (0);
}

int	check_invalid_input(char *value, t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (value[i])
	{
		if ((!ft_isdigit(value[i]) && value[i]) || (value[i] == '-' && i == 0))
		{
			if (ft_atoi(value) > 255 || ft_atoi(value) < 0)
			{
				return (cub3d->outrange = 1, 1);
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_value(char *floor_or_ceilling, int floor, t_cub3d *cub3d, t_utils *u)
{
	while (floor_or_ceilling[u->i])
	{
		while (ft_isspace(floor_or_ceilling[u->i]) && floor_or_ceilling[u->i])
			u->i++;
		u->j = u->i;
		while (!ft_isspace(floor_or_ceilling[u->j]) && floor_or_ceilling[u->j])
			u->j++;
		u->value = ft_substr(floor_or_ceilling, u->i, (u->j - u->i));
		if (check_invalid_input(u->value, cub3d))
			return (free(u->value), 1);
		u->i = u->j;
		if (ft_atoi(u->value) > 255 || ft_atoi(u->value) < 0)
			return (cub3d->outrange = 1, free(u->value), 1);
		if (floor)
			cub3d->map->f_tab[u->k] = ft_atoi(u->value);
		else
			cub3d->map->c_tab[u->k] = ft_atoi(u->value);
		free(u->value);
		u->k++;
	}
	return (0);
}

void	set_position(int x, int y, char direction, t_cub3d *cub3d)
{
	cub3d->player_x = x;
	cub3d->player_y = y;
	cub3d->player_direction = direction;
}

void	get_chararacter_pos(char **map, t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				set_position(j, i, 'N', cub3d);
			else if (map[i][j] == 'S')
				set_position(j, i, 'S', cub3d);
			else if (map[i][j] == 'W')
				set_position(j, i, 'W', cub3d);
			else if (map[i][j] == 'E')
				set_position(j, i, 'E', cub3d);
			j++;
		}
		i++;
	}
}
