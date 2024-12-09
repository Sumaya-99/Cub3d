/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnalnaq <amnalnaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:17:31 by suhelal           #+#    #+#             */
/*   Updated: 2024/10/11 16:41:26 by amnalnaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_char(t_map *game, size_t x, size_t y)
{
	int	counter;

	counter = 0;
	while (y < game->map_line)
	{
		x = 0;
		while (x < ft_strlen(game->map[y]))
		{
			if (game->map[y][x] == 'N' || game->map[y][x] == 'E'
				|| game->map[y][x] == 'W' || game->map[y][x] == 'S')
			{
				if (valid_pos(game, x, y))
					return (1);
				counter++;
			}
			else if (game->map[y][x] != '1' && game->map[y][x] != ' '
				&& game->map[y][x] != '\n' && game->map[y][x] != '0')
				return (1);
			x++;
		}
		y++;
	}
	if (counter > 1 || counter < 1)
		return (1);
	return (0);
}

int	check_top_bottom(t_map *game)
{
	size_t	len_y;
	size_t	len_x;
	size_t	x;
	size_t	y;

	len_y = game->map_line;
	y = 0;
	while (y < len_y)
	{
		x = 0;
		len_x = ft_strlen(game->map[y]);
		while (x < len_x)
		{
			if (game->map[0][x] != '1' && game->map[0][x] != ' ')
				return (1);
			if (game->map[len_y - 1][x] != '1'
				&& game->map[len_y - 1][x] != ' ')
				return (1);
			if (game->map[len_y - 1][x + 1] == '\0'
				|| game->map[0][x + 1] == '\0')
				return (0);
			x++;
		}
	}
	return (0);
}

int	check_wall(t_map *game, size_t x, size_t y)
{
	size_t	len_y;
	size_t	len_x;

	len_y = game->map_line;
	while (y < len_y)
	{
		x = 0;
		len_x = len_withot_space(game->map[y]) + 1;
		while (x < len_x && game->map[y][x] == ' ')
			x++;
		if (game->map[y][x] != '1' || game->map[y][len_x - 1] != '1')
			return (1);
		y++;
	}
	if (check_top_bottom(game))
		return (1);
	return (0);
}

int	check_x_axis(t_map *game, size_t *y)
{
	size_t	len_x;
	size_t	x;

	x = 0;
	len_x = len_withot_space(game->map[*y]) + 1;
	while (x < len_x && game->map[*y][x] == ' ')
		x++;
	while (x < len_x)
	{
		while ((game->map[*y][x] != ' ') && x < len_x)
			x++;
		if ((game->map[*y][x] == ' ' && game->map[*y][x - 1] != '1' &&
			x < len_x && game->map[*y][x - 1] != ' '))
			return (1);
		while (game->map[*y][x] == ' ' && x < len_x &&
			(game->map[*y][x + 1] == ' ' || game->map[*y][x + 1] == '1' ))
			x++;
		if ((game->map[*y][x] == ' ' && game->map[*y][x + 1] != '1' &&
			x < len_x))
			return (1);
	}
	return (0);
}

int	check_y_axis(t_map *game, size_t *y, size_t *len_y)
{
	size_t	len_x;
	size_t	x;

	x = 0;
	len_x = len_withot_space(game->map[*y]) + 1;
	while (x < len_x && game->map[*y][x] == ' ')
		x++;
	while (x < len_x)
	{
		while ((game->map[*y][x] != ' ') && x < len_x)
			x++;
		if (game->map[*y][x] == ' ' && *y > 0 && game->map[*y - 1][x] != '1'
			&& game->map[*y - 1][x] != ' ' && game->map[*y - 1][x] != '\0')
			return (1);
		if (*y < *len_y - 1 && game->map[*y][x] == ' '
			&& game->map[*y + 1][x] != '1' && game->map[*y + 1][x] != ' '
			&& game->map[*y + 1][x] != '\0')
			return (1);
		if (game->map[*y][x] == ' ' && x < len_x &&
			(game->map[*y][x + 1] == ' ' || game->map[*y][x + 1] == '1' ))
			x++;
	}
	return (0);
}
