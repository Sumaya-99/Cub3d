/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:50:03 by suhelal           #+#    #+#             */
/*   Updated: 2024/10/16 15:32:18 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	destroy_window(t_map *game)
{
	printf("Game Over!!!!!");
	if (game->map)
		ft_free_word(game->map);
	if (game->comp.no)
		free(game->comp.no);
	if (game->comp.so)
		free(game->comp.so);
	if (game->comp.ea)
		free(game->comp.ea);
	if (game->comp.we)
		free(game->comp.we);
	if (game->textures_pix)
		free_void((void **)game->textures_pix);
	if (game->textures)
		free_void((void **)game->textures);
	exit (0);
	return (0);
}
