/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnalnaq <amnalnaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:11:01 by suhelal           #+#    #+#             */
/*   Updated: 2024/10/11 16:51:02 by amnalnaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	rotate_left_right(t_map *game, double rotat_speed)
{
	double	temp;

	temp = game->player->x_dir;
	game->player->x_dir = game->player->x_dir
		* cos(rotat_speed) - game->player->y_dir * sin(rotat_speed);
	game->player->y_dir = temp
		* sin(rotat_speed) + game->player->y_dir * cos(rotat_speed);
	temp = game->player->x_nxt_pos;
	game->player->x_nxt_pos = game->player->x_nxt_pos * cos(rotat_speed)
		- game->player->y_nxt_pos * sin(rotat_speed);
	game->player->y_nxt_pos = temp * sin(rotat_speed)
		+ game->player->y_nxt_pos * cos(rotat_speed);
	return (1);
}

int	rotation(t_map *game, double rotation)
{
	double	rotat_speed;
	int		moved;

	moved = 0;
	rotat_speed = 0.015 * rotation;
	moved += rotate_left_right(game, rotat_speed);
	return (moved);
}

int	key_press(int key, t_map *game)
{
	if (key == ESC)
		destroy_window(game);
	if (key == A)
		game->player->x_step = -1;
	if (key == S)
		game->player->y_step = -1;
	if (key == D)
		game->player->x_step = 1;
	if (key == W)
		game->player->y_step = 1;
	if (key == ARROW_KEY_RIGHT)
		game->player->rt_s += 1;
	if (key == ARROW_KEY_LEFT)
		game->player->rt_s -= 1;
	return (0);
}

int	key_release(int key, t_map *game)
{
	if (key == ESC)
		destroy_window(game);
	if (key == A && game->player->x_step == -1)
		game->player->x_step += 1;
	if (key == S && game->player->y_step == -1)
		game->player->y_step = 0;
	if (key == D && game->player->x_step == 1)
		game->player->x_step -= 1;
	if (key == W && game->player->y_step == 1)
		game->player->y_step = 0;
	if (key == ARROW_KEY_RIGHT && game->player->rt_s >= -1)
		game->player->rt_s = 0;
	if (key == ARROW_KEY_LEFT && game->player->rt_s <= 1)
		game->player->rt_s = 0;
	return (0);
}
