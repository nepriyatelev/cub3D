/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:18:40 by modysseu          #+#    #+#             */
/*   Updated: 2022/04/01 17:38:19 by modysseu         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_data	data;

	ft_mlx_init(&data);
	ft_mlx_new_window(&data);
	mlx_loop(data.mlx_ptr);

	return (EXIT_SUCCESS);
}
