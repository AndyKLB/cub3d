/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:47:03 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/29 12:49:13 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void free_superstrs(char ***strs)
{
	int i;

	i = 0;
	if (!*strs || !**strs)
		return;
	while ((*strs)[i])
	{
		free((*strs)[i]);
		(*strs)[i] = NULL;
		i++;
	}
	free(*strs);
	*strs = NULL;
	return;
}
void free_strs(char **strs)
{
	int i;

	i = 0;
	if (!strs || !*strs)
		return;
	while (strs[i])
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	free(strs);
	strs = NULL;
	return;
}