/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:18:40 by modysseu          #+#    #+#             */
/*   Updated: 2022/04/09 19:01:45 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	ft_mlx_init(t_data	*data)
{
	(*data).mlx_ptr = mlx_init();
	if ((*data).mlx_ptr == NULL)
	{
		perror("mlx_init() ");
		exit(EXIT_FAILURE);
	}
}

void	ft_mlx_new_window(t_data	*data)
{
	(*data).mlx_win = mlx_new_window((*data).mlx_ptr, \
		WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
	if ((*data).mlx_win == NULL)
	{
		perror("mlx_new_window() ");
		free((*data).mlx_ptr);
		exit(EXIT_FAILURE);
	}
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length + x * (data->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_render_pixel(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	data->img.img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, \
			&data->img.line_length, &data->img.endian);
	ft_mlx_pixel_put(data, data->player.px, data->player.py, 0x00ffdae9);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img, 0, 0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == 13)
		data->player.py--;
	else if (keycode == 1)
		data->player.py++;
	else if (keycode == 0)
		data->player.px--;
	else if (keycode == 2)
		data->player.px++;
	ft_render_pixel(data);
	return (0);
}


int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		print_error("Not two arguments\n", NULL, NULL, NULL);
		return (EXIT_FAILURE);
	}
	parser(&data, argv[1]);
	// ft_mlx_init(&data);
	// ft_mlx_new_window(&data);
	// ft_render_pixel(&data);
	// mlx_hook(data.mlx_win, X_EVENT_KEY_PRESS, 0, &key_press, &data);
	// mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
