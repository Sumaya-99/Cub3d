/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnalnaq <amnalnaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:31:01 by suhelal           #+#    #+#             */
/*   Updated: 2024/10/11 16:51:50 by amnalnaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	north_south(t_player *player)
{
	if (player->dir == 'S')
	{
		player->x_dir = 0;
		player->y_dir = 1;
		player->x_nxt_pos = -0.66;
		player->y_nxt_pos = 0;
	}
	else if (player->dir == 'N')
	{
		player->x_dir = 0;
		player->y_dir = -1;
		player->x_nxt_pos = 0.66;
		player->y_nxt_pos = 0;
	}
	else
		return ;
}

void	init_direction(t_player *player)
{
	north_south(player);
	if (player->dir == 'W')
	{
		player->x_dir = -1;
		player->y_dir = 0;
		player->x_nxt_pos = 0;
		player->y_nxt_pos = -0.66;
	}
	else if (player->dir == 'E')
	{
		player->x_dir = 1;
		player->y_dir = 0;
		player->x_nxt_pos = 0;
		player->y_nxt_pos = 0.66;
	}
}
