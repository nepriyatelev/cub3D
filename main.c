/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:18:40 by modysseu          #+#    #+#             */
/*   Updated: 2022/04/16 23:06:56 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	ft_mlx_init(t_data	*data)
{
	(*data).mlx_ptr = mlx_init();
	if ((*data).mlx_ptr == NULL)
		print_error("Initialization error: (*data).mlx_ptr == NULL\n", \
			NULL, NULL, NULL);
}

void	ft_mlx_new_window(t_data	*data)
{
	(*data).mlx_win = mlx_new_window((*data).mlx_ptr, \
		WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
	if ((*data).mlx_win == NULL)
		print_error("Initialization error: (*data).mlx_win == NULL\n", \
				NULL, NULL, NULL);
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length \
		+ x * (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// void draw_rectangle(int win_w, int wint_h, size_t rect_x, size_t rext_y, size_t rect_w, size_t rext_h, t_data data)
// {
// 	for (size_t i=0; i<rect_w; i++) {
//         for (size_t j=0; j<rext_h; j++) {
//             size_t cx = rect_x+i;
//             size_t cy = rext_y+j;
//             ft_mlx_pixel_put(&data, cx, cy, 0x00FF0000);
//         }
//     }
// }

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		print_error("Not two arguments\n", NULL, NULL, NULL);
	parser(&data, argv[1]);
	ft_mlx_init(&data);
	ft_mlx_new_window(&data);
	data.img.img = mlx_new_image(data.mlx_ptr, MAP_WIDTH, MAP_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length,
								&data.img.endian);
	int h = 0;
	while (data.player.map[h])
		h++;
	int w = ft_strlen(data.player.map[0]);
	printf("%d\n", w);
	int x = 0;
	int y = 0;
	int cx = 0;
	int cy = 0;
	int	rect_h = MAP_HEIGHT / h;
	int	rect_w = MAP_WIDTH / w;
	printf("%d\t%d\n", rect_h, rect_w);
	for (int i = 0; i < MAP_HEIGHT; i++)
		for (int j = 0; j < MAP_WIDTH; j++)
			ft_mlx_pixel_put(&data,	j , i, 0xff0000);
	for(int i = 0; data.player.map[i]; i++)
		for (int j = 0; data.player.map[i][j]; j++)
		{
			if (data.player.map[i][j] == '1')
			{
				x = j * rect_w;
				y = i * rect_h;
				for (int k = 0; k < rect_h; k++)
				{	for (int l = 0; l < rect_w; l++)
					{
						cx = x + l;
						cy = y + k;
						if (cx <= MAP_WIDTH && cy <= MAP_HEIGHT)
							ft_mlx_pixel_put(&data,	cx , cy, 0xf0f0f5);
					
					}
			}
			}
		}

		// for (int j = 0; j < MAP_WIDTH; j++)
		// 		ft_mlx_pixel_put(&data,	j , 0, 0xf0f0f5);
		// for (int j = 0; j < MAP_WIDTH; j++)
		// 		ft_mlx_pixel_put(&data,	j , MAP_HEIGHT - 1, 0xf0f0f5);
		// for (int j = 0; j < MAP_HEIGHT; j++)
		// 		ft_mlx_pixel_put(&data,	MAP_WIDTH - 1, j, 0xf0f0f5);
		// for (int j = 0; j < MAP_HEIGHT; j++)
		// 		ft_mlx_pixel_put(&data,	0 , j, 0xf0f0f5);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img.img, 1060, 10);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}



//0x1f1f2e