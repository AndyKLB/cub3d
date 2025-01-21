/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:14:57 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/21 12:32:36 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	**map_reader(char *path)
{
	int		fd;
	char	*line;
	char	*buff;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buff = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		buff = ft_strjoin(buff, line);
		free(line);
	}
	map = ft_split(buff, '\n');
	free(buff);
	close(fd);
	return (map);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int c;
	char **map;
	int i = 0;

	map = map_reader("./maps/good/subject_map.cub");
	while (map[i])
	{
		ft_printf_fd(1, map[i]);
		ft_printf_fd(1, "\n");
		i++;
	}
	c = check_order_elements(map);
	ft_printf_fd(1, "\n");
	if (c == 1)
		ft_printf_fd(1, "invalid map\n\n");
	else
		ft_printf_fd(1, "valid map\n\n");
	i = 0;
	while (map[i])
	{
		ft_printf_fd(1, map[i]);
		ft_printf_fd(1, "\n");
		i++;
	}
}