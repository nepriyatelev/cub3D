/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:00:18 by modysseu          #+#    #+#             */
/*   Updated: 2022/04/09 18:44:48 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	checking_the_extension(char *file)
{
	int	i;

	i = (ft_strlen(file)) - 4;
	if (ft_strncmp(".cub\0", file + i, 4))
	{
		ft_putstr_fd("\033[1;31mError\n\033[0m", 2);
		ft_putstr_fd("\033[3;31mIncorrect file extension: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd("\n\033[0m", 2);
		exit (EXIT_FAILURE);
	}
}

void	reading_a_file(char ***split_file, int fd)
{
	char	*buf;
	char	*tmp;

	buf = (char *)malloc(2 * sizeof(char));
	if (buf == NULL)
	{
		ft_putstr_fd("\033[1;31mError\n\033[0m", 2);
		ft_putstr_fd("\033[3;31mMemory allocation error in the function: ", 2);
		ft_putstr_fd("reading_a_file\n\033[0m", 2);
		close(fd);
		exit(EXIT_FAILURE);
	}
	tmp = ft_strdup("");
	if (tmp == NULL)
	{
		ft_putstr_fd("\033[1;31mError\n\033[0m", 2);
		ft_putstr_fd("\033[3;31mMemory allocation error in the function: ", 2);
		ft_putstr_fd("ft_strdup()\n\033[0m", 2);
		free(buf);
		close(fd);
		exit(EXIT_FAILURE);
	}
	buf[1] = '\0';
	while ((read(fd, &buf[0], 1)) > 0)
	{
		tmp = ft_strjoin(tmp, buf);
		if (tmp == NULL)
		{
			ft_putstr_fd("\033[1;31mError\n\033[0m", 2);
			ft_putstr_fd("\033[3;31mMemory allocation error in the function: ", 2);
			ft_putstr_fd("reading_a_file\n\033[0m", 2);
			free(buf);
			free(tmp);
			close(fd);
			exit(EXIT_FAILURE);
		}
	}
	free(buf);
	*split_file = ft_split(tmp, '\n');
	if (*split_file == NULL)
	{
		
	}
	free(tmp);
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
		ft_putstr_fd("\033[1;31mError\n\033[0m", 2);
		ft_putstr_fd("\033[3;31mThe file does not exist: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd("\n\033[0m", 2);
		close(fd);
		exit (EXIT_FAILURE);
	}
	reading_a_file(&split_file, fd);
	// if (checking_nswe(split_file, "NO"))
	// 	puts("no valid no");
	// if (checking_nswe(split_file, "SO"))
	// 	puts("no valid so");
	// if (checking_nswe(split_file, "WE"))
	// 	puts("no valid we");
	// if (checking_nswe(split_file, "EA"))
	// 	puts("no valid ea");
	// if (checking_color(split_file, "F"))
	// 	puts("no valid f");
	// if (checking_color(split_file, "C"))
	// 	puts("no valid c");
	// if (checking_the_file(split_file, data))
	// 	perror("free matrix ");
	// recording_map(split_file + 6, &data->player.map);
	// for(int i = 0; data->player.map[i]; i++)
	// 	printf("%s\n", data->player.map[i]);
	// for (int i = 0; i < 3; i++)
	// 	printf("F = %d\n", data->texture.color_floor[i]);
	// for (int i = 0; i < 3; i++)
	// 	printf("C = %d\n", data->texture.color_ceiling[i]);
	close(fd);
}