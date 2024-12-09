/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnalnaq <amnalnaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:18:20 by suhelal           #+#    #+#             */
/*   Updated: 2024/10/11 15:25:50 by amnalnaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	valid_n(t_map *game, size_t x, size_t y)
{
	if (y == 0 || game->map[y - 1][x] == ' ' ||
		game->map[y - 1][x] == '\n' || game->map[y - 1][x] == '\0')
		return (1);
	return (0);
}

int	valid_e(t_map *game, size_t x, size_t y)
{
	if (game->map[y][x + 1] == '\0' || game->map[y][x + 1] == ' ' ||
		game->map[y][x + 1] == '\n')
		return (1);
	return (0);
}

int	valid_s(t_map *game, size_t x, size_t y)
{
	if (game->map[y + 1][x] == '\0' || game->map[y + 1][x] == ' ' ||
		game->map[y + 1][x] == '\n')
		return (1);
	return (0);
}

int	valid_w(t_map *game, size_t x, size_t y)
{
	if (x == 0 || game->map[y][x - 1] == '\0' || game->map[y][x - 1] == ' ' ||
		game->map[y][x - 1] == '\n')
		return (1);
	return (0);
}

int	valid_pos(t_map *game, size_t x, size_t y)
{
	if (game->map[y][x] == 'N')
	{
		if (valid_n(game, x, y))
			return (1);
	}
	else if (game->map[y][x] == 'E')
	{
		if (valid_e(game, x, y))
			return (1);
	}
	else if (game->map[y][x] == 'S')
	{
		if (valid_s(game, x, y))
			return (1);
	}
	else if (game->map[y][x] == 'W')
	{
		if (valid_w(game, x, y))
			return (1);
	}
	return (0);
}
