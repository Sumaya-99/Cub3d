/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:01:01 by suhelal           #+#    #+#             */
/*   Updated: 2024/10/16 15:38:22 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_comma(char *color)
{
	int	comma;
	int	i;

	i = 0;
	comma = 0;
	while (color[i])
	{
		if (color[i] == ',')
			comma++;
		if (color[i] == '+' || color[i] == '-')
			return (free(color), printf("Error: Invalid color\n"), exit (1));
		i++;
	}
	if (comma != 2)
	{
		free(color);
		printf("Error: Colors require 3 numbers seperated by comma\n");
		exit (1);
	}
}

int	rgb_converter(char **rgb, char *color_s)
{
	int	color;
	int	i;

	i = 0;
	free(color_s);
	while (i < 3)
	{
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
		{
			ft_free_word(rgb);
			return (printf("Error: Color range should be from 0-255\n")
				, exit(1), 1);
		}
		i++;
	}
	color = ft_atoi(rgb[0]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]);
	return (color);
}

int	convert_color(char *color)
{
	char	**rgb;
	int		i;

	i = 0;
	rgb = ft_split(color, ',');
	if (!rgb)
		return (printf("Error: Memory was not allocated\n"),
			free(color), exit(1), 1);
	while (rgb[i])
		i++;
	if (i != 3)
	{
		ft_free_word(rgb);
		free(color);
		return (printf("Error: Three numbers are required for color\n")
			, exit(1), 1);
	}
	i = 0;
	while (rgb[i])
	{
		if (ft_isdigit(rgb[i++]))
			return (free(color), ft_free_word(rgb),
				printf("Error: Invalid Color\n"), exit(1), 1);
	}
	return (rgb_converter(rgb, color));
}

void	parse_color(t_map *game, char *next_line)
{
	char	*color_f;
	char	*color_c;

	color_f = NULL;
	color_c = NULL;
	if (next_line[0] == 'F')
		color_f = ft_strtrim(next_line + 1, " ");
	else if (next_line[0] == 'C')
		color_c = ft_strtrim(next_line + 1, " ");
	if (color_c)
	{
		check_comma(color_c);
		game->comp.ceiling_color = convert_color(color_c);
		game->c_flag++;
	}
	if (color_f)
	{
		check_comma(color_f);
		game->comp.floor_color = convert_color(color_f);
		game->f_flag++;
	}
}
