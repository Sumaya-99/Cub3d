/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnalnaq <amnalnaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:56:10 by suhelal           #+#    #+#             */
/*   Updated: 2024/10/11 16:32:20 by amnalnaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	white_space(t_map *game, size_t y)
{
	size_t	len_y;

	len_y = game->map_line;
	while (y < len_y)
	{
		if (check_x_axis(game, &y))
			return (1);
		if (check_y_axis(game, &y, &len_y))
			return (1);
		y++;
	}
	return (0);
}

int	verify_map(t_map *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	x = 0;
	if (check_char(game, x, y))
		return (printf("Error: Map is invalid\n"), exit (1), 1);
	if (check_wall(game, x, y))
		return (printf("Error: Map needs to be surrounded by walls\n")
			, exit (1), 1);
	if (white_space(game, y))
		return (printf("Error: Space needs to be surrounded by walls\n")
			, exit (1), 1);
	return (0);
}

int	iterate_map(t_map *game, char *line, int fd)
{
	size_t	i;
	char	*next_line;

	i = 1;
	game->map_line = game->total_line - game->map_index;
	game->map = (char **)malloc(sizeof(char *) * (game->map_line + 1));
	if (!game->map)
		return (free(line), printf("Error: Memory was not allocated\n")
			, exit (1), 0);
	game->map[0] = line;
	next_line = get_next_line(fd);
	while (i < game->map_line)
	{
		game->map[i++] = next_line;
		next_line = get_next_line(fd);
	}
	game->map[i] = NULL;
	if (verify_map(game))
		return (ft_free_word(game->map), 1);
	return (0);
}
