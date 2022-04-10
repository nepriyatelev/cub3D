/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:00:18 by modysseu          #+#    #+#             */
/*   Updated: 2022/04/10 20:54:27 by modysseu         ###   ########.fr       */
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

void	reading_a_file(char ***split_file, int fd, char *file)
{
	char	buf[2];
	char	*tmp;
	ssize_t	rd;

	tmp = ft_strdup("");
	if (tmp == NULL)
		error_ft_strdup(fd);
	buf[1] = '\0';
	rd = read(fd, &buf[0], 1);
	if (rd < 1)
		error_read(fd, &tmp, rd, file);
	tmp = ft_strjoin(tmp, buf);
	if (tmp == NULL)
		error_ft_strjoin(&tmp, fd);
	while ((read(fd, &buf[0], 1)) > 0)
	{
		tmp = ft_strjoin(tmp, buf);
		if (tmp == NULL)
			error_ft_strjoin(&tmp, fd);
	}
	*split_file = ft_split(tmp, '\n');
	if (*split_file == NULL)
		error_ft_split(&tmp, fd);
	free(tmp);
}

void	checking_nswefc(char ***split_file)
{
	int		i;
	char	search[2][3];

	search = { {N, O, \0}, {N, O, \0} };

	// search[0] = {"NO"};
	// search[1][0] = "SO";
	// search[2][0] = "WE";
	// search[3][0] = "EA";
	i = 0;
	for (; i < 2; i++)
		printf("%s\n", search[i]);
	// checking_nswe(split_file, "NO");
	// checking_nswe(split_file, "SO");
	// checking_nswe(split_file, "WE");
	// checking_nswe(split_file, "EA");
	// checking_color(split_file, "F");
	// checking_color(split_file, "C");
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
		print_error("The file does not exist: ", file, "\n", NULL);
		close(fd);
		exit (EXIT_FAILURE);
	}
	reading_a_file(&split_file, fd, file);
	checking_nswefc(&split_file);
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