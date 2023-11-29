/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:24:16 by ikhristi          #+#    #+#             */
/*   Updated: 2023/11/29 13:08:24 by ikhristi         ###   ########.fr       */
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

void	init_facing_direction(t_game *game)
{
	if (game->player_direction == 'E')
	{
		game->rays->dir_x = -1;
		game->rays->plane_y = 0.66;
	}
	if (game->player_direction == 'N')
	{
		game->rays->dir_y = -1;
		game->rays->plane_x = -0.66;
	}
	if (game->player_direction == 'W')
	{
		game->rays->dir_x = 1;
		game->rays->plane_y = -0.66;
	}
	if (game->player_direction == 'S')
	{
		game->rays->dir_y = 1;
		game->rays->plane_x = 0.66;
	}
}

int	init_game_vars(t_game *game)
{
	game->mlx = mlx_init();
	game->screen_width = 1200;
	game->screen_height = 900;
	game->rays->mlx = game->mlx;
	game->tex_width = TEX_SIZE;
	game->tex_height = TEX_SIZE;
	game->movespeed = 0.06;
	game->rotspeed = 0.04;
	game->key_w = 0;
	game->key_s = 0;
	game->key_a = 0;
	game->key_d = 0;
	game->key_esc = 0;
	game->key_right = 0;
	game->key_left = 0;
	game->win = mlx_new_window(game->mlx, game->screen_width, \
									game->screen_height, "Game");
	game->rays->win = game->win;
	game->texture = (uint32_t **) ft_calloc(sizeof(uint32_t *), 4);
	if (game->texture == NULL)
		return (0);
	return (1);
}

void	init_map_data(t_game *game, char *path)
{
	char	**file_content;

	file_content = read_map(game, path);
	init_map_vars(game, file_content);
	init_map(game, file_content);
	matrix_free(file_content);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game->rays = ft_calloc(sizeof(t_raycast), 1);
	if (game == NULL)
		throw_error(game, MEM_ALLOCATION);
	if (argc != 2)
		throw_error(game, ARGS_ERROR);
	if (!check_extention)
		throw_error(game, "Wrong extension\n");
	if (!init_game_vars(game))
		throw_error(game, MEM_ALLOCATION);
	init_map_data(game, argv[1]);
	init_facing_direction(game);
	if (!init_textures(game))
		throw_error(game, MEM_ALLOCATION);
}
