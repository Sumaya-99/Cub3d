/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:09:24 by suhelal           #+#    #+#             */
/*   Updated: 2024/10/16 15:27:42 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./utils/get_next_line.h"
# include "./mlx/mlx.h"
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdint.h>

# define WIDTH 800
# define HEIGHT 800

# define KEY_PRESS			2
# define KEY_RELEASE		3

# define ESC				53
# define W					13
# define A					0
# define S					1
# define D					2
# define ARROW_KEY_LEFT		123
# define ARROW_KEY_RIGHT	124
# define X_EXIT_KEY		17

typedef struct s_raycast
{
	double	view_x;
	double	x_ray_dir;
	double	y_ray_dir;
	double	x_ray_mov;
	double	y_ray_mov;
	double	x_next_wall;
	double	y_next_wall;
	double	wall_dis;
	double	x_wall;
	int		x_map;
	int		y_map;
	int		side;
	int		x_step;
	int		y_step;
	int		start_draw;
	int		end_draw;
	int		height;
}				t_raycast;

typedef struct s_player
{
	double	x_nxt_pos;
	double	y_nxt_pos;
	double	x_dir;
	double	y_dir;
	double	x_pos;
	double	y_pos;
	char	dir;
	int		x_step;
	int		y_step;
	int		moved;
	int		rt_s;
}				t_player;

typedef struct s_comp
{
	int		floor_color;
	int		ceiling_color;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}				t_comp;

typedef struct s_tex
{
	int		*f;
	int		*c;
	int		i;
	int		x;
	int		y;
	int		size;
	char	*n;
	char	*s;
	char	*w;
	char	*e;
	double	step;
	double	pos;
}				t_tex;

typedef struct s_map
{
	int			**textures_pix;
	int			line_length;
	int			total_line;
	int			**textures;
	int			map_index;
	int			no_flag;
	int			so_flag;
	int			ea_flag;
	int			we_flag;
	int			height;
	int			endian;
	int			c_flag;
	int			f_flag;
	int			width;
	int			*addr;
	int			mouse;
	int			bpp;
	char		**map;
	void		*mlx;
	void		*win;
	void		*img;
	double		speed;
	t_raycast	*ray;
	t_player	*player;
	size_t		map_line;
	t_comp		comp;
	t_tex		*tex;
}				t_map;

/* UTILS */
int		ft_strcmp(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
void	ft_free_word(char **spl);
int		ft_isdigit(char *str);
int		ft_atoi(const char *str);
int		len_withot_space(char *str);
char	ft_isdigit_char(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		destroy_window(t_map *game);
int		get_height(char **str);
int		get_width(char **str);
void	*ft_calloc(size_t count, size_t size);
void	free_void(void **text);

/* PARSING */
void	parsing(t_map *game, char *av, t_player *player);
void	parse_map(t_map *map, char *filename);
void	no_direction(char *next_line, t_map *map);
void	so_direction(char *next_line, t_map *map);
void	ea_direction(char *next_line, t_map *map);
void	we_direction(char *next_line, t_map *map);
int		parse_line(char *next_line, t_map *map);
void	parse_color(t_map *map, char *next_line);
void	save_map(t_map *map, char *line, int fd);
int		iterate_map(t_map *game, char *line, int fd);
int		check_char(t_map *game, size_t x, size_t y);
int		check_top_bottom(t_map *game);
int		check_wall(t_map *game, size_t x, size_t y);
int		white_space(t_map *game, size_t y);
int		check_y_axis(t_map *game, size_t *y, size_t *len_y);
int		check_x_axis(t_map *game, size_t *y);
int		valid_pos(t_map *game, size_t x, size_t y);
void	init(t_map *game, t_player *player, t_raycast *ray, t_tex *texture);
void	init_pl_pos(t_map *game, t_player *player);

/* EXECUTION */
void	raycast(t_map *game);
void	set_param(t_raycast *ray, t_player *player, int w);
void	init_direction(t_player *player);
void	wall(t_raycast *ray, t_player *player);
void	init_texture(t_map *game);
void	clean_img(t_map *game);
void	img_init(t_map *game, int w, int h);
void	pixel_put(t_map *game, int w, int h, int color);
void	update_tex(t_map *game, t_tex *texture, t_raycast *ray, int w);
void	drawing(t_map *game);

/* MOVEMENT */
int		movement(t_map *game);
int		player_movement(t_map *game);
int		key_release(int key, t_map *game);
int		key_press(int key, t_map *game);
int		collision_check(t_map *game, double x, double y);
int		rotation(t_map *game, double rotation);
int		forward(t_map *game);
int		right(t_map *game);
int		backword(t_map *game);
int		left(t_map *game);

#endif
