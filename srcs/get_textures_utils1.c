/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:19:37 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/30 14:29:10 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_nbr_value(char *floor_or_celling)
{
	int	i;
	int	nb_spc;
	int	is_not_digit;
	int	is_digit;

	is_digit = 1;
	is_not_digit = 0;
	nb_spc = 0;
	i = 0;
	while (floor_or_celling[i])
	{
		if (!ft_isdigit(floor_or_celling[i])
			&& !ft_isspace(floor_or_celling[i]))
			is_not_digit++;
		if (floor_or_celling[i] == ' ')
		{
			nb_spc++;
			if (ft_isdigit(floor_or_celling[i + 1]))
				is_digit++;
		}
		i++;
	}
	if (nb_spc != 2 || is_not_digit || is_digit != 3)
		return (1);
	return (0);
}

int	check_value(char *floor_or_ceilling)
{
	int		i;
	int		j;
	char	*value;

	value = 0;
	i = 0;
	j = 0;
	while (floor_or_ceilling[i])
	{
		while (ft_isspace(floor_or_ceilling[i]))
			i++;
		while (!ft_isdigit(floor_or_ceilling[i]))
			i++;
		j = i;
		while (ft_isdigit(floor_or_ceilling[j]))
			j++;
		value = ft_substr(floor_or_ceilling, i, (j - i));
		i = j;
		if (ft_atoi(value) > 255)
			return (free(value), 1);
		free(value);
	}
	return (0);
}

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
