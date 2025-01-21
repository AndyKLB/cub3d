/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:28:22 by wzeraig           #+#    #+#             */
/*   Updated: 2025/01/21 12:50:26 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int find(char *str) // il verifie ligne par ligne.
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] != 'N' && str[i] != 'S' && str[i] != 'W') && (str[i] != '0' && str[i] != 'E' && str[i] != '1'))
			return (1);
		i++;
	}
	return (0);
}
int countplayer(char *str) // a voir si je fais en map ou non
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			count++;
		i++;
	}
	return (count);
}

int check_wall(t_cub3d *cub3d, int position)
{
	int i;

	i = 0;
	if (cub3d->line)											// first
		while (cub3d->line[i] == ' ' || cub3d->line[i] == '\t') // tant que t egal a espace
			i++;
	if (cub3d->line[i] != '1')
		return (msg_error(cub3d));
	if (position) // first or last line
	{
		while (cub3d->line[i] == '1')
			i++;
		if (cub3d->line[i]) // il existe encore donc pas fini par 1.
			return (msg_error(cub3d));
	}
	if ()
}
int msg_error(t_cub3d *cub3d)
{
	return (printf("error"));
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
