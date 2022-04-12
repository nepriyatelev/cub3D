/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:00:18 by modysseu          #+#    #+#             */
/*   Updated: 2022/04/12 21:04:41 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	checking_the_extension(char *file)
{
	int	i;

	i = (ft_strlen(file)) - 4;
	if (ft_strncmp(".cub\0", file + i, 4))
	{
		print_error("Incorrect file extension: ", file, "\n", NULL);
		exit (EXIT_FAILURE);
	}
}

void	parser(t_data *data, char *file)
{
	int		fd;
	char	**split_file;

	split_file = NULL;
	checking_the_extension(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		print_error("The file does not open: ", file, "\n", NULL);
		exit (EXIT_FAILURE);
	}
	reading_a_file(&split_file, fd, file);
	checking_card_information(split_file, fd);
	// if (checking_the_file(split_file, data))
	// 	perror("free matrix ");
	// recording_map(split_file + 6, &data->player.map);
	// for(int i = 0; data->player.map[i]; i++)
	// 	printf("%s\n", data->player.map[i]);
	// for (int i = 0; i < 3; i++)
	// 	printf("F = %d\n", data->texture.color_floor[i]);
	// for (int i = 0; i < 3; i++)
	// 	printf("C = %d\n", data->texture.color_ceiling[i]);
	for (int i = 0; split_file[i]; i++)
		printf("%s\n", split_file[i]);
	close(fd);
}
