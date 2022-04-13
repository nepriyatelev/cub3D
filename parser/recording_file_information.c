/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recording_file_information.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:17:48 by modysseu          #+#    #+#             */
/*   Updated: 2022/04/13 19:10:20 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	recording_textures(char *line, char **nswe, int rd)
{
	int		fd;
	int		i;
	int		j;
	char	c;

	fd = 0;
	i = 2;
	while (ft_isspace(line[i]))
		i++;
	j = i;
	while (line[j] && line[j] != '\n' && !(ft_isspace(line[j])))
		j++;
	*nswe = ft_substr(line, i, j - i);
	if (*nswe == NULL)
		print_error("Memory allocation error in the function: ", \
		"recording_textures ", "*nswe == NULL\n", NULL);
	fd = open(*nswe, O_RDONLY);
	if (fd < 0)
		print_error("The file does not open: ", *nswe, "\n", NULL);
	rd = read(fd, &c, 1);
	if (rd < 1)
		error_read(rd);
	close(fd);
}

static void	find_color(int *j, char *line)
{
	while (line[*j] && line[*j] != '\n' && !ft_isspace(line[*j]))
	{
		if (ft_isdigit(line[*j]) || line[*j] == ',')
			(*j)++;
		else
			print_error("Incorrect color: ", line, "\n", NULL);
	}
}

static void	wrapper_alloc_color(int **color)
{
	*color = (int *)malloc(sizeof(int) * 3);
	if (*color == NULL)
		print_error("Memory allocation error in the function: ", \
		"recording_color ", "*color == NULL\n", NULL);
}

static void	recording_color(char *line, int	**color)
{
	int		i;
	int		j;
	int		tmp_d;
	char	**tmp;

	i = 1;
	while (ft_isspace(line[i]))
		i++;
	j = i;
	find_color(&j, line);
	wrapper_alloc_color(color);
	tmp = ft_split(ft_substr(line, i, j - i), ',');
	if ((ft_strlen(*tmp)) != 3)
		print_error("Incorrect color: ", line, "\n", NULL);
	i = 0;
	while (i < 3)
	{
		tmp_d = ft_atoi(tmp[i]);
		if (tmp_d <= 255 && tmp_d >= 0)
			(*color)[i++] = tmp_d;
		else
			print_error("Incorrect color: ", line, "\n", NULL);
	}
}

void	recording_file_information(char **split_file, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (split_file[i])
	{
		j = 0;
		while (ft_isspace(split_file[i][j]))
			j++;
		if (!(ft_strncmp(&split_file[i][j], "NO", 2)))
			recording_textures(&split_file[i][j], &data->texture.north, 0);
		else if (!(ft_strncmp(&split_file[i][j], "SO", 2)))
			recording_textures(&split_file[i][j], &data->texture.south, 0);
		else if (!(ft_strncmp(&split_file[i][j], "WE", 2)))
			recording_textures(&split_file[i][j], &data->texture.west, 0);
		else if (!(ft_strncmp(&split_file[i][j], "EA", 2)))
			recording_textures(&split_file[i][j], &data->texture.east, 0);
		else if (!(ft_strncmp(&split_file[i][j], "F", 1)))
			recording_color(&split_file[i][j], &data->texture.color_floor);
		else if (!(ft_strncmp(&split_file[i][j], "C", 1)))
			recording_color(&split_file[i][j], &data->texture.color_ceiling);
		i++;
	}
}
