/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:10:43 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/28 13:35:35 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	find(char **map) // il verifie ligne par ligne.
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!map)
		return (1);
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] != 'N' && map[j][i] != 'S' && map[j][i] != 'W'
				&& map[j][i] != '0' && map[j][i] != 'E' && map[j][i] != '1'
				&& map[j][i] != ' ')
				return (1);
			i++;
		}
		j++;
		i = 0;
	}
	return (0);
}
int	countplayer(char **map) // a voir si je fais en map ou non
{
	int i;
	int j;
	int count;
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
int	checktricky(t_cub3d *cub3d, char **map, int j, int i)
{
	if (!map)
		return (1);
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
				return (msg_error("0 not surrounded by wall", cub3d));
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
				return (msg_error("0 not surrounded by wall", cub3d));
		}
	}
	return (msg_error("not enclosed by wall", cub3d));
}

void	check_wall(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	j = 0;
	if (!cub3d->maps)
		return ;
	while (cub3d->maps[j])
	{
		while (cub3d->maps[j][i] == ' ' || cub3d->maps[j][i] == '\t')
			// tant que t egal a espace ou tab nimporte quel line
			i++;
		if (cub3d->maps[j][i] != '1') // first 1
			msg_error("first 1", cub3d);
		if (j == 0 || !cub3d->maps[j + 1]) // first or last
		{
			while (cub3d->maps[j][i])
			{
				if (cub3d->maps[j][i] == ' ')
					checktricky(cub3d, cub3d->maps, j, i);
				else if (cub3d->maps[j][i] != ' ' && cub3d->maps[j][i] != '1')
					msg_error("in first or last only 1 or space", cub3d);
				i++;
			}
		}
		else
		{
			while (cub3d->maps[j][i])
			{
				if ((cub3d->maps[j][i] == '0'
						&& i > (int)ft_strlen(cub3d->maps[j - 1]) - 1)
					|| (cub3d->maps[j][i] == '0'
						&& i > (int)ft_strlen(cub3d->maps[j + 1]) - 1))
					msg_error("0 not surrounded by wall", cub3d);
				else if (cub3d->maps[j][i] == '0')
					flag = 1;
				else if (cub3d->maps[j][i] == '1' && flag)
					flag = 0;
				i++;
			}
		}
		i = ft_strlen(cub3d->maps[j]) - 1;
		if (cub3d->maps[j][i] != '1') // 1 de fin
			msg_error("last 1", cub3d);
		j++;
		i = 0;
	}
}

int	checkformat(t_cub3d *cub3d, char *path)
{
	int	len;
	int	fd;

	len = ft_strlen(path);
	if (open(path, __O_DIRECTORY) >= 0)
	{
		fd = open(path, __O_DIRECTORY);
		close(fd);
		msg_error(ERRDIR, cub3d);
	}
	else
	{
		if (ft_strncmp(path + len - 4, ".cub", 4) != 0)
			msg_error(ERREXT, cub3d);
		fd = open(path, O_RDONLY);
		if (fd < 0)
		{
			perror(strerror(fd));
			exit(1);
		}
		if (read(fd, 0, 0) < 0)
		{
			perror(strerror(fd));
			exit(1);
		}
		close(fd);
	}
	return (Success);
}



void	checkmap(t_cub3d *cub3d)
{
	if (find(cub3d->maps)) // autre caractere
		msg_error("find", cub3d);
	if (countplayer(cub3d->maps) != 1) // plus dun player
		msg_error("countplayer", cub3d);
	check_wall(cub3d); // entourer de mur
	fill_space_one(cub3d->maps);
}
int	msg_error(char *msg, t_cub3d *cub3d)
{
	if (cub3d->celling)
		free(cub3d->celling);
	if (cub3d->floor)
		free(cub3d->floor);
	if (cub3d->east_element)
		free(cub3d->east_element);
	if (cub3d->west_element)
		free(cub3d->west_element);
	if (cub3d->north_element)
		free(cub3d->north_element);
	if (cub3d->south_element)
		free(cub3d->south_element);
	if (cub3d->maps && *cub3d->maps)
		free_strs(cub3d->maps);
	ft_printf_fd(2, msg);
	exit(1);
}

// si ya un espace tu cherches jusqua trouver quelque chose si cest autre chose qu'un 1 cest error
// check les 1, si ya pas full 1 apres le premier 1 trouver cest 0.
// extension cub.
// count pour compter le nombre de joueur.
// pour voir si ya au moins un joueur.

// wall
// peut commmencer par espace first and final caractere 1 et apres peut avoir des espace pour la ligne 1.
// ensuite peut commencer par espace mais le premier caractere doit etre 1. donc sois espace soit 1, et apres le 1 ce que tu veux.mais doit avoir 1 pour boucler et apres espace.
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