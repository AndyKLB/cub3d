/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:28:22 by wzeraig           #+#    #+#             */
/*   Updated: 2025/01/23 12:59:02 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int find(char **map) // il verifie ligne par ligne.
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] != 'N' && map[j][i] != 'S' && map[j][i] != 'W' && map[j][i] != '0' && map[j][i] != 'E' && map[j][i] != '1' && map[j][i] != ' ')
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
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'S' || map[j][i] == 'E' || map[j][i] == 'W')
				count++;
			i++;
		}
		j++;
		i = 0;
	}
	return (count);
}
int checktricky(char **map, int j, int i)
{
	if (j == 0) // first
	{
		j++;
		while (map[j])
		{
			if (map[j][i] == '1')
				return (0);
			else if (map[j][i] == ' ')
				j++;
			else
				return (msg_error("0 not surrounded by wall"));
		}
	}
	else // last
	{
		while (map[j])
		{
			if (map[j][i] == '1')
				return (0);
			else if (map[j][i] == ' ')
				j--;
			else
				return (msg_error("0 not surrounded by wall"));
		}
	}
	return (msg_error("not enclosed by wall"));
}

void check_wall(t_cub3d *cub3d)
{
	int i;
	int j;
	int flag;

	i = 0;
	flag = 0;
	j = 0;
	while (cub3d->maps[j])
	{
		while (cub3d->maps[j][i] == ' ' || cub3d->maps[j][i] == '\t') // tant que t egal a espace ou tab nimporte quel line
			i++;
		if (cub3d->maps[j][i] != '1') // first 1
			msg_error("first 1");
		if (j == 0 || !cub3d->maps[j + 1]) // first or last
		{
			while (cub3d->maps[j][i])
			{
				if (cub3d->maps[j][i] == ' ')
					checktricky(cub3d->maps, j, i);
				else if (cub3d->maps[j][i] != ' ' && cub3d->maps[j][i] != '1')
					msg_error("in first or last only 1 or space");
				i++;
			}
		}
		else
		{
			while (cub3d->maps[j][i])
			{
				if ((cub3d->map[j][i] == '0' && i > (int)ft_strlen(cub3d->map[j - 1]) - 1) || (cub3d->map[j][i] == '0' && i > (int)ft_strlen(cub3d->map[j + 1]) - 1))
					msg_error("0 not surrounded by wall", cub3d);
				else if (cub3d->map[j][i] == 0)
					flag = 1;
				else if (cub3d->maps[j][i] == 1 && flag)
					flag = 0;
				i++;
			}
		}
		i = ft_strlen(cub3d->maps[j]) - 1;
		if (cub3d->maps[j][i] != '1') // 1 de fin
			msg_error("last 1");
		j++;
		i = 0;
	}
}

int checkformat(char *path)
{
	int len;
	int fd;

	len = ft_strlen(path);
	if (open(path, __O_DIRECTORY) >= 0)
	{
		fd = open(path, __O_DIRECTORY);
		close(fd);
		msg_error(ERRDIR);
	}
	else
	{
		if (ft_strncmp(path + len - 4, ".cub", 4) != 0)
			msg_error(ERREXT);
		fd = open(path, O_RDONLY);
		if (read(fd, 0, 0) < 0)
			msg_error(ERRFD);
		close(fd);
	}
	return (Success);
}

int msg_error(char *error)
{
	printf("%s", error);
	// if (cub3d->line)
	// 	free(cub3d->line);
	exit(1);
}

void checkmap(t_cub3d *cub3d)
{
	if (find(cub3d->maps)) // autre caractere
		msg_error("find");
	if (countplayer(cub3d->maps) > 1) // plus dun player
		msg_error("countplayer");
	check_wall(cub3d); // entourer de mur
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

// relire ma fonction.
// et relire le parsing de so_long et reflechir a tout type de parsing demandez aux autres.

// autre que la premeire et la derniere
// si ya un espace il doit y avoir forcement 1 avant et apres lespace.

// cas du 0 et 0 quand ya un espace qui arrive en colone
// bien limager.

// if == 0
// if i > a la colone du haut c cuit
// if i > a la colone du bas c cuit

// tester le code juste au dessus dans les commentaire le if i >
// remodeler le code avec andy, et lui dire pour les news de karandeep au cas ou il a pas vu.