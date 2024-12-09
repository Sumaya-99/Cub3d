/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnalnaq <amnalnaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:55:56 by suhelal           #+#    #+#             */
/*   Updated: 2024/10/11 16:50:18 by amnalnaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	no_collide(t_map *game, double x, double y)
{
	if (game->map[(int)y][(int)x] == '0')
		return (true);
	return (false);
}

bool	valid_pos_map(t_map *game, double x, double y)
{
	if (x < 0.25 || x >= game->width - 1.25)
		return (false);
	if (y < 0.25 || y >= game->height - 0.25)
		return (false);
	return (true);
}

int	collision_check(t_map *game, double x, double y)
{
	int	moved;

	moved = 0;
	if (no_collide(game, x, y) && valid_pos_map(game, x, y))
	{
		game->player->x_pos = x;
		game->player->y_pos = y;
		moved = 1;
	}
	return (moved);
}

int	player_movement(t_map *game)
{
	int	moved;

	moved = 0;
	if (game->player->y_step == 1)
		moved += forward(game);
	if (game->player->y_step == -1)
		moved += backword(game);
	if (game->player->x_step == -1)
		moved += left(game);
	if (game->player->x_step == 1)
		moved += right(game);
	if (game->player->y_step == 1)
		moved += forward(game);
	if (game->player->rt_s != 0)
		moved += rotation(game, game->player->rt_s);
	return (moved);
}
