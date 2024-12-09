/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:38:39 by suhelal           #+#    #+#             */
/*   Updated: 2024/10/14 14:47:25 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initialize_dir(t_raycast *ray, t_player *player)
{
	if (ray->x_ray_dir < 0)
	{
		ray->x_step = -1;
		ray->x_ray_mov = (player->x_pos
				- ray->x_map) * ray->x_next_wall;
	}
	else
	{
		ray->x_step = 1;
		ray->x_ray_mov = (ray->x_map + 1.0
				- player->x_pos) * ray->x_next_wall;
	}
	if (ray->y_ray_dir < 0)
	{
		ray->y_step = -1;
		ray->y_ray_mov = (player->y_pos
				- ray->y_map) * ray->y_next_wall;
	}
	else
	{
		ray->y_step = 1;
		ray->y_ray_mov = (ray->y_map + 1.0
				- player->y_pos) * ray->y_next_wall;
	}
}

void	set_param(t_raycast *ray, t_player *player, int w)
{
	ray->view_x = 2 * w / (double)WIDTH - 1;
	ray->x_ray_dir = player->x_dir + player->x_nxt_pos * ray->view_x;
	ray->y_ray_dir = player->y_dir + player->y_nxt_pos * ray->view_x;
	ray->x_map = (int)player->x_pos;
	ray->y_map = (int)player->y_pos;
	if (ray->x_ray_dir == 0)
		ray->x_next_wall = 1e30;
	else
		ray->x_next_wall = fabs(1 / ray->x_ray_dir);
	if (ray->y_ray_dir == 0)
		ray->y_next_wall = 1e30;
	else
		ray->y_next_wall = fabs(1 / ray->y_ray_dir);
}

void	wall_collide(t_map *game, t_raycast *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->x_ray_mov < ray->y_ray_mov)
		{
			ray->x_ray_mov += ray->x_next_wall;
			ray->x_map += ray->x_step;
			ray->side = 0;
		}
		else
		{
			ray->y_ray_mov += ray->y_next_wall;
			ray->y_map += ray->y_step;
			ray->side = 1;
		}
		if (ray->y_map < 0.25 || ray->x_map < 0.25
			|| ray->y_map > game->height - 0.25
			|| ray->x_map > game->width - 1.25)
			break ;
		else if (game->map[ray->y_map][ray->x_map] > '0')
			hit = 1;
	}
}

void	raycast(t_map *game)
{
	int	w;

	w = 0;
	init_texture(game);
	while (w < WIDTH)
	{
		set_param(game->ray, game->player, w);
		initialize_dir(game->ray, game->player);
		wall_collide(game, game->ray);
		wall(game->ray, game->player);
		update_tex(game, game->tex, game->ray, w);
		w++;
	}
	drawing(game);
}
