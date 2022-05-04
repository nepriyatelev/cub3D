/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medeana <medeana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:09:50 by medeana           #+#    #+#             */
/*   Updated: 2022/05/03 18:27:02 by medeana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <mlx.h>
# include <math.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

# define BUFFER_SIZE 	1
# define KEY_PRESS 		2
# define KEY_RELEASE 	3
# define KEY_EXIT		17
# define SHEIGHT		720
# define SWIGHT			1280
# define TEXW			1024
# define TEXH			1024
# define W 				13
# define A 				0
# define D 				2
# define S 				1
# define ESC 			53
# define UP				126
# define DOWN			125
# define LEFT			123
# define RIGHT			124

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size;
	int		bpp;
	int		endian;
	int		h;
	int		w;
}	t_img;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		color_ceiling[3];
	int		color_floor[3];
}	t_texture;

typedef struct s_cub{
	void		*mlx;
	void		*win;
	char		**file;
	char		**map;
	double		pos_x;
	double		pos_y;
	double		dir_vector_x;
	double		dir_vector_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
	int			buf[SHEIGHT][SWIGHT];
	int			**texture;
	int			map_x;
	int			map_y;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall;
	double		wall_x;
	int			step_x;
	int			step_y;
	int			hit;
	int			forward;
	int			back;
	int			left;
	int			right;
	int			right2;
	int			left2;
	int			side;
	int			line_h;
	int			draw_start;
	int			draw_end;
	int			tex_num;
	int			tex_x;
	double		step;
	double		tex_pos;
	int			tex_y;
	int			text;
	t_img		img;
	t_texture	textur;
}	t_cub;

void	read_map(char *av, t_cub *cub);
void	ft_pixel_put(int y, int x, t_cub *cub, unsigned int color);
void	init_pos(t_cub *cub);
int		key_hook(int key, t_cub *cub);
void	init(t_cub *cub);
int		ft_key_press(t_cub *cub);
int		calc_and_save(t_cub *cub);
void	hit(t_cub *cub);
void	draw_line(t_cub *cub);
void	step(t_cub *cub);
void	load_texture(t_cub *cub);
void	load_img(t_cub *cub, int *texture, char *path, t_img *img);
int		main_loop(t_cub *cub);
int		init_texture(t_cub *cub);
int		ft_key_press(t_cub *cub);
void	if_forward(t_cub *cub);
void	if_back(t_cub *cub);
void	if_left(t_cub *cub);
void	if_right(t_cub *cub);
int		key_press(int keycode, t_cub *cub);
int		key_release(int keycode, t_cub *cub);
void	potolok(t_cub *cub);
void	image_draw(t_cub *cub);
void	parser(t_cub *data, char *file);
void	checking_the_extension(char *file);
void	print_error(char *s1, char *s2, char *s3, char *s4);
void	checking_card_information(char **split_file, int fd);
void	reading_a_file(char ***split_file, int fd, char *file);
void	recording_file_information(char **split_file, t_cub *cub);
void	error_read(int rd);
int		ft_hex(int r, int g, int b);
void	step(t_cub *cub);
void	right(t_cub *cub);
void	left(t_cub *cub);

#endif