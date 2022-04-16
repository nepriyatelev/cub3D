/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_the_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:30:16 by modysseu          #+#    #+#             */
/*   Updated: 2022/04/16 23:05:59 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	map_height(t_data *data)
{
	int	i;

	i = 0;
	while (data->player.map[i])
		i++;
	data->player.map_h = i;
}

void	map_width(t_data *data)
{
	int	i;
	int	j;

	data->player.map_w = 0;
	i = 0;
	while (data->player.map[i])
	{
		j = 0;
		while (data->player.map[i][j])
			j++;
		if (j > data->player.map_w)
			data->player.map_w = j;
		i++;
	}
}

void	visualization_map_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < MAP_HEIGHT)
	{
		j = 0;
		while (j < MAP_WIDTH)
		{
			ft_mlx_pixel_put(data, j, i, 0x1f1f2e);
			j++;
		}
		i++;
	}
}

void	map_visualization(t_data *data, int i_map, int j_map)
{
	int	i;
	int	j;
	int	offset_h;
	int	offset_w;
	offset_h = MAP_HEIGHT - (MAP_HEIGHT / data->player.map_h \
		* data->player.map_h);
	offset_w = MAP_WIDTH - (MAP_WIDTH / data->player.map_w \
		* data->player.map_w);
	i = 0;
	while (i < (MAP_HEIGHT / data->player.map_h))
	{
		j = 0;
		while (j < (MAP_WIDTH / data->player.map_w))
		{
			if ((j_map * (MAP_WIDTH / data->player.map_w) + j) < MAP_WIDTH \
				&& (i_map * (MAP_HEIGHT / data->player.map_h) + i) < MAP_HEIGHT)
				ft_mlx_pixel_put(data, \
				(j_map * (MAP_WIDTH / data->player.map_w) + j) + offset_w / 2, \
				(i_map * MAP_HEIGHT / data->player.map_h + i) + offset_h / 2, \
				0xf0f0f5);
			j++;
		}
		i++;
	}
}

void	drawing_the_map(t_data *data)
{
	int	i;
	int	j;

	data->img.img = mlx_new_image(data->mlx_ptr, MAP_WIDTH, MAP_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, \
		&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	map_height(data);
	map_width(data);
	visualization_map_background(data);
	i = 0;
	while (data->player.map[i])
	{
		j = 0;
		while (data->player.map[i][j])
		{
			if (data->player.map[i][j] == '1')
				map_visualization(data, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, \
		data->img.img, 1070, 10);
}
