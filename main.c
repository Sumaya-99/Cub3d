/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:14:05 by suhelal           #+#    #+#             */
/*   Updated: 2024/10/16 15:41:04 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_img(t_map *game)
{
	game->img = NULL;
	game->addr = NULL;
	game->bpp = 0;
	game->line_length = 0;
	game->endian = 0;
}

void	get_texture(t_map *game, char *texture)
{
	clean_img(game);
	game->img = mlx_xpm_file_to_image(game->mlx, texture,
			&game->tex->size, &game->tex->size);
	if (game->img == NULL)
		return (printf("Error: Mlx Image Error\n"), exit (1));
	game->addr = (int *)mlx_get_data_addr(game->img, &game->bpp,
			&game->line_length, &game->endian);
	return ;
}

int	*get_img(t_map *game, char *texture)
{
	int	*buffer;
	int	x;
	int	y;

	get_texture(game, texture);
	buffer = ft_calloc(1, sizeof * buffer * game->tex->size * game->tex->size);
	if (!buffer)
		return (printf("Error: Memory was not allocated\n"), exit (1), NULL);
	y = 0;
	while (y < game->tex->size)
	{
		x = 0;
		while (x < game->tex->size)
		{
			buffer[y * game->tex->size + x]
				= game->addr[y * game->tex->size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, game->img);
	return (buffer);
}

void	init_text(t_map *game)
{
	game->textures = ft_calloc(5, sizeof * game->textures);
	if (!game->textures)
		return (printf("Error: Malloc allocation \n"), exit(1));
	game->textures[0] = get_img(game, game->comp.no);
	game->textures[1] = get_img(game, game->comp.so);
	game->textures[2] = get_img(game, game->comp.ea);
	game->textures[3] = get_img(game, game->comp.we);
}

int	main(int ac, char **av)
{
	t_map		game;
	t_player	player;
	t_raycast	ray;
	t_tex		texture;

	if (ac == 2)
	{
		init(&game, &player, &ray, &texture);
		parsing(&game, av[1], &player);
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "CUB3D");
		init_text(&game);
		raycast(&game);
		mlx_hook(game.win, X_EXIT_KEY, 1L << 17, destroy_window, &game);
		mlx_hook(game.win, KEY_PRESS, 1L << 0, key_press, &game);
		mlx_hook(game.win, KEY_RELEASE, 1L << 1, key_release, &game);
		mlx_loop_hook(game.mlx, movement, &game);
		mlx_loop(game.mlx);
		destroy_window(&game);
	}
	else
		return (printf("Error: Wrong number of arguments\n"), 1);
}
