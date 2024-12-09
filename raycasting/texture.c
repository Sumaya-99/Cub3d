/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:51:18 by suhelal           #+#    #+#             */
/*   Updated: 2024/10/14 16:10:19 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_texture(t_map *game)
{
	int	h;

	h = 0;
	if (game->textures_pix)
		free_void((void **)game->textures_pix);
	game->textures_pix = ft_calloc(HEIGHT + 1, sizeof * game->textures_pix);
	if (!game->textures_pix)
	{
		printf("Error: Memory allocation failed\n");
		destroy_window(game);
	}
	while (h < HEIGHT)
	{
		game->textures_pix[h] = malloc(sizeof(t_tex) * (WIDTH + 1));
		if (!game->textures_pix)
		{
			printf("Error: Memory allocation failed\n");
			destroy_window(game);
		}
		h++;
	}
	game->textures_pix[h] = NULL;
}

void	texture_index(t_map *game, t_raycast *ray)
{
	if (ray->side == 0)
	{
		if (ray->x_ray_dir < 0)
			game->tex->i = 3;
		else
			game->tex->i = 2;
	}
	else
	{
		if (ray->y_ray_dir > 0)
			game->tex->i = 1;
		else
			game->tex->i = 0;
	}
}

void	update_tex(t_map *game, t_tex *texture, t_raycast *ray, int w)
{
	int	h;
	int	color;

	texture_index(game, ray);
	texture->x = (int)(ray->x_wall * texture->size);
	if ((ray->side == 0 && ray->x_ray_dir < 0)
		|| (ray->side == 1 && ray->y_ray_dir > 0))
		texture->x = texture->size - texture->x - 1;
	texture->step = 1.0 * texture->size / ray->height;
	texture->pos = (ray->start_draw - HEIGHT / 2
			+ ray->height / 2) * texture->step;
	h = ray->start_draw;
	while (h < ray->end_draw)
	{
		texture->y = (int)texture->pos & (texture->size - 1);
		texture->pos += texture->step;
		color = game->textures[texture->i][texture->size
			* texture->y + texture->x];
		if (texture->i == 0 || texture->i == 2)
			color = (color >> 1) & 8355711;
		if (color > 0)
			game->textures_pix[h][w] = color;
		h++;
	}
}

void	img_init(t_map *game, int w, int h)
{
	clean_img(game);
	game->img = mlx_new_image(game->mlx, w, h);
	if (game->img == NULL)
		return (printf("Error: Mlx image error\n"), exit (1));
	game->addr = (int *)mlx_get_data_addr(game->img, &game->bpp,
			&game->line_length, &game->endian);
	return ;
}

void	pixel_put(t_map *game, int w, int h, int color)
{
	int	pix;

	pix = h * (game->line_length / 4) + w;
	game->addr[pix] = color;
}
