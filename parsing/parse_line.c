/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnalnaq <amnalnaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:30:07 by suhelal           #+#    #+#             */
/*   Updated: 2024/10/11 16:01:55 by amnalnaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_map(char *next_line, t_map *game)
{
	if (game->line_length > 3)
	{
		if (ft_strncmp(next_line, "NO ", 3) == 0)
			no_direction(next_line, game);
		else if (ft_strncmp(next_line, "SO ", 3) == 0)
			so_direction(next_line, game);
		else if (ft_strncmp(next_line, "WE ", 3) == 0)
			we_direction(next_line, game);
		else if (ft_strncmp(next_line, "EA ", 3) == 0)
			ea_direction(next_line, game);
		else if (ft_strncmp(next_line, "F ", 2) == 0
			|| ft_strncmp(next_line, "C ", 2) == 0)
			parse_color(game, next_line);
		else
			return (free(next_line), 1);
	}
	if (game->line_length < 1)
		return (0);
	return (0);
}

int	parse_line(char *next_line, t_map *game)
{
	int	i;

	i = 0;
	while (next_line[i] != '\0' && (next_line[i] == 32
			|| (next_line[i] >= 9 && next_line[i] <= 13)))
		i++;
	if (check_map(next_line, game))
		return (1);
	return (0);
}
