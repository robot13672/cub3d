/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:46:51 by ikhristi          #+#    #+#             */
/*   Updated: 2023/11/19 17:56:55 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_extention(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 4)
		return (0);
	path += len - 4;
	return (strnstr(path, ".cub", 5));
}
