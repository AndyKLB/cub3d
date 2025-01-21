/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:28:22 by wzeraig           #+#    #+#             */
/*   Updated: 2025/01/21 15:53:55 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int find(char **map) // il verifie ligne par ligne.
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[j][i])
	{
		while (map[j][i])
		{
			if ((map[j][i] != 'N' && map[j][i] != 'S' && map[j][i] != 'W') && (map[j][i] != '0' && map[j][i] != 'E' && map[i] != '1'))
				return (1);
			i++;
		}
		j++;
		i = 0;
	}
	return (0);
}
int countplayer(char **map) // a voir si je fais en map ou non
{
	int i;
	int j;
	int count;
	i = 0;
	j = 0;
	count = 0;
	while (map[j][i])
	{
		while (map[j][i])
		{
			if (map[i] == 'N' || map[i] == 'S' || map[i] == 'E' || map[i] == 'W')
				count++;
			i++;
		}
		return (count);
	}
}
int checktricky(t_cub3d *cub3d, char **map, int i, int j)
{
	if (j == 0) // first
	{
		j++;
		while (map[j][i])
		{
			if (map[j][i] == '1')
				break;
			if (map[j][i] == ' ')
				j++;
			else
				return (msg_error(cub3d));
		}
	}
	else // last
	{
		j--;
		while (map[j][i])
		{
			if (map[j][i] == '1')
				break;
			if (map[j][i] == ' ')
				j--;
			else
				return (msg_error(cub3d));
		}
	}
}
int check_wall(t_cub3d *cub3d)
{
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	while (cub3d->map[j][i])
	{
		while (cub3d->map[j][i] == ' ' || cub3d->map[j][i] == '\t') // tant que t egal a espace ou tab nimporte quel line
			i++;
		if (cub3d->map[j][i] != '1') // first 1
			return (msg_error(cub3d));
		if (j == 0 || !cub3d->map[j + 1]) // first or last
		{
			while (cub3d->map[j][i])
			{
				if (cub3d->map[j][i] == ' ')
					checktricky(cub3d, cub3d->map, j, i);
			}
		}
	}
	i = ft_strlen(cub3d->map) - 1;
	if (cub3d->map[j][i] != '1') // 1 de fin
		return (msg_error(cub3d));
	j++;
}

int msg_error(t_cub3d *cub3d)
{
	return (printf("error"));
}

void checkmap(t_cub3d *cub3d)
{
	if (find(cub3d->line)) // autre caractere
		return (msg_error(cub3d));
	if (countplayer(cub3d->map) > 1) // pus dun player
		return (msg_error(cub3d));
	check_wall(cub3d); // entourer de mur
	if (check_elements_order(cub3d))
		return (msg_error(cub3d));
}
// si ya un espace tu cherches jusqua trouver quelque chose si cest autre chose qu'un 1 cest error
// check les 1, si ya pas full 1 apres le premier 1 trouver cest 0.
// extension cub.
// count pour compter le nombre de joueur.
// pour voir si ya au moins un joueur.

// wall
// peut commmencer par espace first and final caractere 1 et apres peut avoir des espace pour la ligne 1.
// ensuite peut commencer par espace mais le premier caractere doit etre 1. donc sois espace soit 1, et apres le 1 ce que tu veux. mais doit avoir 1 pour boucler et apres espace.
// peut commencer par un espace derniere first et final caractere 1