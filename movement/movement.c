/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:15:53 by suhelal           #+#    #+#             */
/*   Updated: 2024/10/14 14:50:53 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	forward(t_map *game)
{
	double	x;
	double	y;

	x = game->player->x_pos + (game->player->x_dir * game->speed);
	y = game->player->y_pos + (game->player->y_dir * game->speed);
	return (collision_check(game, x, y));
}

int	backword(t_map *game)
{
	double	x;
	double	y;

	x = game->player->x_pos - (game->player->x_dir * game->speed);
	y = game->player->y_pos - (game->player->y_dir * game->speed);
	return (collision_check(game, x, y));
}

int	left(t_map *game)
{
	double	x;
	double	y;

	x = game->player->x_pos + (game->player->y_dir * game->speed);
	y = game->player->y_pos - (game->player->x_dir * game->speed);
	return (collision_check(game, x, y));
}

int	right(t_map *game)
{
	double	x;
	double	y;

	x = game->player->x_pos - (game->player->y_dir * game->speed);
	y = game->player->y_pos + (game->player->x_dir * game->speed);
	return (collision_check(game, x, y));
}

int	movement(t_map *game)
{
	game->player->moved += player_movement(game);
	if (game->player->moved == 0)
		return (0);
	raycast(game);
	return (0);
}
