/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnalnaq <amnalnaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:42:32 by suhelal           #+#    #+#             */
/*   Updated: 2024/10/11 16:25:30 by amnalnaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	no_direction(char *next_line, t_map *game)
{
	int	fd;

	game->comp.no = ft_strtrim(next_line + 2, " ");
	if (!game->comp.no)
		return (printf("Error: memmory allocation failure\n")
			, exit (1));
	fd = open(game->comp.no, O_RDONLY);
	if (fd == -1)
		return (printf("Error: Texture not found\n"), exit(1));
	game->no_flag++;
}

void	so_direction(char *next_line, t_map *game)
{
	int	fd;

	game->comp.so = ft_strtrim(next_line + 2, " ");
	if (!game->comp.so)
		return (printf("Error: memmory allocation failure\n")
			, exit (1));
	fd = open(game->comp.so, O_RDONLY);
	if (fd == -1)
		return (printf("Error: Texture not found\n"), exit(1));
	game->so_flag++;
}

void	ea_direction(char *next_line, t_map *game)
{
	int	fd;

	game->comp.ea = ft_strtrim(next_line + 2, " ");
	if (!game->comp.ea)
		return (printf("Error: memmory allocation failure\n")
			, exit (1));
	fd = open(game->comp.ea, O_RDONLY);
	if (fd == -1)
		return (printf("Error: Texture not found\n"), exit(1));
	game->ea_flag++;
}

void	we_direction(char *next_line, t_map *game)
{
	int	fd;

	game->comp.we = ft_strtrim(next_line + 2, " ");
	if (!game->comp.we)
		return (printf("Error: memmory allocation failure\n")
			, exit (1));
	fd = open(game->comp.we, O_RDONLY);
	if (fd == -1)
		return (printf("Error: Texture not found\n"), exit(1));
	game->we_flag++;
}
