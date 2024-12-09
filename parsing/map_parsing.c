/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnalnaq <amnalnaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:55:26 by suhelal           #+#    #+#             */
/*   Updated: 2024/10/11 16:23:21 by amnalnaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*read_line(char *filename, int *fd)
{
	char	*line;

	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
	{
		printf("Error: Cannot open the file\n");
		exit(1);
	}
	line = get_next_line(*fd);
	if (!line)
	{
		printf("Error: file is empty\n");
		exit(1);
	}
	return (line);
}

void	save_map(t_map *game, char *line, int fd)
{
	if (game->so_flag != 1 || game->no_flag != 1 || game->ea_flag != 1
		|| game->we_flag != 1 || game->f_flag != 1 || game->c_flag != 1)
		return (free(line), printf("Error: Mising components for map\n")
			, exit(1));
	if (iterate_map(game, line, fd))
		return (free(line), printf("Error: Invalid Map\n"), exit (1));
}

void	parse_map(t_map *game, char *filename)
{
	char	*next_line;
	char	*line;
	int		fd;

	line = read_line(filename, &fd);
	while (line)
	{
		next_line = ft_strtrim(line, "\n");
		if (!next_line)
			return (printf("Error: Memory was not allocated\n")
				, exit (1));
		game->line_length = ft_strlen(next_line);
		if (parse_line(next_line, game))
			break ;
		free(line);
		free (next_line);
		line = get_next_line(fd);
		game->map_index++;
	}
	save_map(game, line, fd);
}
