/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:00:18 by modysseu          #+#    #+#             */
/*   Updated: 2022/04/05 21:06:41 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	checking_the_extension(char *file)
{
	int	i;

	i = (ft_strlen(file)) - 4;
	if (ft_strncmp(".cub\0", file + i, 4))
	{
		perror("ft_strncmp() ");
		exit (EXIT_FAILURE);
	}
}

void	reading_a_file(t_data *data, int fd)
{
	char	*buf;
	char	*tmp;

	buf = (char *)malloc(2 * sizeof(char));
	if (buf == NULL)
	{
		perror("buf == NULL ");
		exit(EXIT_FAILURE);
	}
	tmp = ft_strdup("");
	if (tmp == NULL)
	{
		perror("tmp == NULL ");
		free(buf);
		exit(EXIT_FAILURE);
	}
	buf[1] = '\0';
	while ((read(fd, &buf[0], 1)) > 0)
	{
		tmp = ft_strjoin(tmp, buf);
		if (tmp == NULL)
		{
			perror("buf == NULL ");
			free(buf);
			free(tmp);
			exit(EXIT_FAILURE);
		}
	}
	free(buf);
	data->player.map = ft_split(tmp, '\n');
	free(tmp);
}

void	checking_the_file(char **map, t_data *data)
{
	
}

void	parser(t_data *data, char *file)
{
	int	fd;

	checking_the_extension(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("fd < 0 ");
		exit (EXIT_FAILURE);
	}
	reading_a_file(data, fd);
	close(fd);
}