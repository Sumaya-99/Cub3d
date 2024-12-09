/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:46:22 by suhelal           #+#    #+#             */
/*   Updated: 2024/10/14 13:47:24 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init(t_map *game, t_player *player, t_raycast *ray, t_tex *texture)
{
	ft_bzero(game, sizeof(t_map));
	ft_bzero(player, sizeof(t_player));
	ft_bzero(ray, sizeof(t_raycast));
	ft_bzero(texture, sizeof(t_tex));
	player->dir = '\0';
	game->comp.no = NULL;
	game->comp.so = NULL;
	game->comp.we = NULL;
	game->comp.ea = NULL;
	game->comp.floor_color = -1;
	game->comp.ceiling_color = -1;
	game->player = player;
	game->ray = ray;
	game->speed = 0.018;
	texture->size = 128;
	game->tex = texture;
}

void	check_filename(char *filename)
{
	size_t	length;

	length = ft_strlen(filename);
	if ((ft_strcmp(filename + (length - 4), ".cub")) != 0)
	{
		printf("Error: Wrong file name\n");
		exit(1);
	}
}

int	count_line(char *filename)
{
	char	*line;
	int		fd;
	int		count;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Cannot open the file\n");
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = NULL;
		line = get_next_line(fd);
		count++;
	}
	free(line);
	line = NULL;
	return (count);
}

void	init_pl_pos(t_map *game, t_player *player)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->map_line)
	{
		x = 0;
		while (x < ft_strlen(game->map[y]))
		{
			if (game->map[y][x] == 'N' || game->map[y][x] == 'E'
				|| game->map[y][x] == 'W' || game->map[y][x] == 'S')
			{
				player->x_pos = x;
				player->y_pos = y;
				player->dir = game->map[y][x];
				game->map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	parsing(t_map *game, char *av, t_player *player)
{
	check_filename(av);
	game->total_line = count_line(av);
	parse_map(game, av);
	game->height = get_height(game->map);
	game->width = get_width(game->map);
	init_pl_pos(game, player);
	init_direction(player);
}
