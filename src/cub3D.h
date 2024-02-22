/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:38:01 by inicole-          #+#    #+#             */
/*   Updated: 2023/11/16 02:18:13 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <mlx.h>
# include "stdlib.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

//LIMITS
# define INT_MAX 2147483647
# define INT_MIN -2147483648

// CONSTANTS TO CALCULATIONS
# define PI 3.14159265
# define TWO_PI 6.28318530
// FOV_ANGLE = (60 * (PI / 180))
# define FOV_ANGLE 1.0471975511965976

typedef enum e_textures
{
	SO,
	NO,
	WE,
	EA,
}	t_textures;

typedef struct s_window
{
	void	*win_ptr;
	int		width;
	int		height;
}	t_window;

typedef struct s_image
{
	void	*addr;
	int		width;
	int		height;
	int		x;
	int		y;
}	t_image;

typedef struct s_rectangle
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rectangle;

typedef struct s_line
{
	int		begin_x;
	int		begin_y;
	int		end_x;
	int		end_y;
	int		color;
	int		pixels;
	int		delta_x;
	int		delta_y;
	double	pixel_x;
	double	pixel_y;
}	t_line;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		*color_buffer;
}	t_img;

typedef struct s_game
{
	void		*mlx_ptr;
	char		**map;
	int			moves;
	int			collectibles;
	t_window	window;
	t_img		wall;
	t_img		space;
	t_img		tux;
	t_img		coin;
	t_img		door;
	t_img		img;
	t_img		img2;
}	t_game;

typedef struct s_file
{
	char	*name;
	int		fd;
}	t_file;

typedef struct s_cord
{
	int	x;
	int	y;
}	t_cord;

typedef struct s_map_dimensions
{
	int		columns;
	int		rows;
	int		col_offset;
}	t_map_dimensions;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		alpha;
	char	*color_str;
}	t_color;

typedef struct s_map
{
	t_map_dimensions	dimensions;
	t_list				*map_list;
	char				**matrix;
	t_file				map_file;
	char				*no_file;
	char				*so_file;
	char				*we_file;
	char				*ea_file;
	t_color				floor_color;
	t_color				ceiling_color;
	int					found_player;
}	t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	width;
	double	height;
	int		turn_direction;
	int		walk_direction;
	int		walk_side_direction;
	double	rotation_angle;
	double	walk_speed;
	double	turn_speed;
	t_line	*line;
	char	player_char;
}	t_player;

typedef struct s_ray
{
	double		ray_angle;
	double		wall_hit_x;
	double		wall_hit_y;
	double		dist;
	int			has_hit_vertical;
	t_textures	texture;
}	t_ray;

typedef struct s_intersection
{
	double	x_intercept;
	double	y_intercept;
	double	x_step;
	double	y_step;
	double	next_x;
	double	next_y;
	double	wall_hit_x;
	double	wall_hit_y;
	double	x_to_check;
	double	y_to_check;
	double	dist;

}	t_intersection;

typedef struct s_wall
{
	int	wall_top_pixel;
	int	wall_bottom_pixel;
	int	wall_height;
	int	wall_offset;
	int	text_offset_y;
	int	dist_from_top;
	int	color;
	int	wall_point;

}	t_wall;

typedef struct s_coordinates
{
	double	x;
	double	y;
}	t_coordinates;

typedef struct s_cubd
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_game		*game;
	t_player	*player;
	t_ray		rays[1280];
	t_img		img_game;
	t_img		textures[4];
}	t_cubd;

int			init_game(t_cubd *cub3D, char *argv[]);
void		init_textures(t_cubd *cub3d);
void		init_texture(t_cubd *cub3d, t_img *img, char *path);
int			exit_with_message(int status_code, char *message);
int			has_valid_args(int argc);
void		exit_with_message_and_free(t_cubd *cub3d, int status_code,
				char *message);
void		game_loop_events(t_cubd *cub3D);
int			ft_open_ext(char *file_path, char *extension);
void		set_file(t_file *file, char *file_path, char *extension);
void		set_texture_path(t_cubd *cub3D, char **texture, char *texture_path);
void		set_floor_ceiling_color(t_cubd *cub3D, t_color *color,
				char *color_str);
int			ft_read_and_validate_map(t_cubd *cub3D, char *map_file);
int			ft_check_map_properties(t_cubd *cub3D);
void		ft_move_line_while_white_space(char **line);
void		ft_return_line_while_white_space(char *start_ptr, char **line);
int			ft_check_player_and_content(t_cubd *cub3D, char *line,
				int is_first_or_last_row);
int			is_new_line(char *line);
int			ft_lstsize_no_new_line(t_list *lst);
t_cord		ft_search_player_in_map(char **map, t_map_dimensions *dim);
size_t		ft_str_trim_len(char *str);
size_t		ft_find_char_position(char *str);
size_t		ft_strclp_new_line(char *dst, const char *src, size_t size);
int			ft_load_color_rgb(char **colors_split, t_color *color);
int			ft_is_new_line_in_list(t_list *h_list);
int			ft_delta(int current, int next, int delta);
void		set_floor_ceiling_color(t_cubd *cub3D, t_color *color,
				char *color_str);
void		ft_load_map(t_cubd *cub3D, t_list	*h_list);
int			ft_check_map_properties(t_cubd *cub3D);
int			ft_load_color_rgb(char **colors_split, t_color *color);
int			ft_check_player_cord(t_cord cord);
void		ft_init_player_position(char **map, t_player *player, t_cord cord);
int			game_exit(t_cubd *cub3D);
void		close_fd(int fd);
void		game_clear(t_cubd *cub3D);
void		clear_matrix(t_cubd *cub3D);
void		clear_player(t_cubd *cub3D);
void		destroy_textures(t_cubd *cub3D);
int			game_render(t_cubd *cub3D);
t_window	ft_get_window(t_map *map);
void		init_player(t_cubd *cub3d);
void		img_pix_put(t_img *img, int x, int y, int color);
void		create_img(t_cubd *cub3d, t_img *img, int width, int height);
void		render_img_to_window(t_cubd *cub3d, t_img *img, int x, int y);
int			key_up(int key, t_cubd *cub3d);
int			key_down(int key, t_cubd *cub3d);
void		cast_all_rays(t_cubd *cub3d, t_player *player);
int			ft_point_down(double angle);
int			ft_point_up(double angle);
int			ft_point_right(double angle);
int			ft_point_left(double angle);
double		get_y_horizontal_intercept(t_player *player);
double		get_y_vertical_intercept(t_player *player, double angle,
				double x_intercept);
double		get_x_horizontal_intercept(t_player *player, double angle,
				double y_intercept);
double		get_x_vertical_intercept(t_player *player);
void		increment_y_horizontal_intercept(double *y_intercept, double angle);
void		increment_x_vertical_intercept(double *x_intercept, double angle);
void		ft_invert_y_vertical(double *y_step, double angle);
void		ft_invert_x_vertical(double *x_step, double angle);
void		ft_invert_x_horizontal(double *x_step, double angle);
void		ft_invert_y_horizontal(double *y_step, double angle);
void		normalize_angle(double *angle);
int			is_inside_map(t_window window, double new_x, double new_y);
int			ft_collision(char **map, double new_x, double new_y, t_cubd *cub3d);
double		ft_dist_between_points(double x1, double y1,
				double x2, double y2);
void		ft_draw_wall(t_cubd *cub3d);
int			rgb_to_hex(t_color color);
void		color_intensity(int *color, double factor);
int			get_color_pixel(t_cubd *cub3d, int wall_point,
				int wall_offset, int text_offset_y);
double		ft_perpendicular_distance(t_ray *ray, t_player *player);
double		ft_projection_on_the_plane(void);
double		get_projected_wall_height(double perp_dist,
				double dist_project_plan);
int			ft_ceil_pixel(int wall_strip_height);
int			ft_floor_pixel(int wall_strip_height);
void		vertical_intersection(t_cubd *cub3d,
				t_intersection *intersec, double ray_angle);
void		set_rays_vert(t_cubd *cub3d, t_intersection *intersec,
				int column, double angle);
void		horizontal_intersection(t_cubd *cub3d, t_intersection *intersec,
				double ray_angle);
void		set_rays_horz(t_cubd *cub3d, t_intersection *intersec,
				int column, double angle);
void		cast_all_rays(t_cubd *cub3d, t_player *player);
void		calc_wall_hit(t_cubd *cub3d, t_intersection *intersec,
				double ray_angle, int is_horz);
void		cast_all_rays(t_cubd *cub3d, t_player *player);
int			ft_valid_wall(char **matrix);
int			ft_offset(t_ray *ray);

#endif
