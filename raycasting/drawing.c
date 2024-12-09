/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:20:13 by suhelal           #+#    #+#             */
/*   Updated: 2024/10/14 16:09:52 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	wall(t_raycast *ray, t_player *player)
{
	if (ray->side == 0)
		ray->wall_dis = ray->x_ray_mov - ray->x_next_wall;
	else
		ray->wall_dis = ray->y_ray_mov - ray->y_next_wall;
	ray->height = (int)(HEIGHT / ray->wall_dis);
	ray->start_draw = -(ray->height) / 2 + HEIGHT / 2;
	if (ray->start_draw < 0)
		ray->start_draw = 0;
	ray->end_draw = ray->height / 2 + HEIGHT / 2;
	if (ray->end_draw >= HEIGHT)
		ray->end_draw = HEIGHT - 1;
	if (ray->side == 0)
		ray->x_wall = player->y_pos + ray->wall_dis * ray->y_ray_dir;
	else
		ray->x_wall = player->x_pos + ray->wall_dis * ray->x_ray_dir;
	ray->x_wall -= floor(ray->x_wall);
}

void	drawing(t_map *game)
{
	int	h;
	int	w;

	h = 0;
	game->img = NULL;
	img_init(game, WIDTH, HEIGHT);
	while (h < HEIGHT)
	{
		w = 0;
		while (w < WIDTH)
		{
			if (game->textures_pix[h][w] > 0)
				pixel_put(game, w, h, game->textures_pix[h][w]);
			else if (h < HEIGHT / 2)
				pixel_put(game, w, h, game->comp.ceiling_color);
			else if (h < HEIGHT - 1)
				pixel_put(game, w, h, game->comp.floor_color);
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	mlx_destroy_image(game->mlx, game->img);
}
