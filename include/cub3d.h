/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:04:20 by modysseu          #+#    #+#             */
/*   Updated: 2022/04/10 20:05:17 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# define WINDOW_WIDTH			1280
# define WINDOW_HEIGHT			960
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_release	3
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC				53
# define KEY_Q					12
# define KEY_W					13
# define KEY_E					14
# define KEY_R					15
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		*color_ceiling;
	int		*color_floor;
}	t_texture;

typedef struct s_player
{
	float	px;
	float	py;
	char	**map;
}	t_player;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		img;
	t_player	player;
	t_texture	texture;
}	t_data;

void	parser(t_data *data, char *file);
void	print_error(char *s1, char *s2, char *s3, char *s4);

void	error_ft_strdup(int fd);
void	error_ft_strjoin(char **tmp, int fd);
void	error_ft_split(char **tmp, int fd);
void	error_read(int fd, char **tmp, int rd, char *file);

#endif