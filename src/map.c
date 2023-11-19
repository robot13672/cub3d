/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:03:32 by ikhristi          #+#    #+#             */
/*   Updated: 2023/11/19 16:52:51 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	count_lines(int fd)
{
	int		i;
	char	*s;

	i = 0;
	s = get_next_line(fd);
	while (s)
	{
		free(s);
		s = get_next_line(fd);
		i++;
	}
	return (i);
}

char	**read_map(t_game *game, char *map)
{
	char	**res;
	int		fd;
	char	*str;
	int		i;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		throw_error(game, FILE_ERROR);
	res = ft_calloc(sizeof(char *), count_lines(fd) + 1);
	close(fd);
	if (!res)
		return (NULL);
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	i = 0;
	while (str)
	{
		res[i] = str;
		i++;
	}
	res[i] = NULL;
	close(fd);
	return (res);
}
