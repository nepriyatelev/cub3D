/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recording_file_information.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medeana <medeana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:17:48 by modysseu          #+#    #+#             */
/*   Updated: 2022/04/14 14:30:37 by medeana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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

static void	writing_colors_to_an_array(char ***tmp_split, \
	int *color, char **line)
{
	int	i;
	int	tmp_d;

	i = 0;
	while (i < 3)
	{
		tmp_d = ft_atoi((*tmp_split)[i]);
		if (tmp_d <= 255 && tmp_d >= 0)
			color[i++] = tmp_d;
		else
			print_error("Incorrect color: ", *line, "\n", NULL);
	}
	free(*line);
	ft_free_matrix(*tmp_split);
}

static void	recording_color(char *line, int	*color)
{
	int		i;
	int		j;
	int		tmp_d;
	char	**tmp_split;
	char	*tmp_substr;

	i = 1;
	while (ft_isspace(line[i]))
		i++;
	j = i;
	find_color(&j, line);
	tmp_substr = ft_substr(line, i, j - i);
	if (tmp_substr == NULL)
		print_error("Memory allocation error in the function: ", \
		"recording_color ", "tmp_substr == NULL\n", NULL);
	tmp_split = ft_split(tmp_substr, ',');
	i = 0;
	while (tmp_split[i])
		i++;
	if (i != 3)
		print_error("Incorrect color: ", tmp_substr, "\n", NULL);
	writing_colors_to_an_array(&tmp_split, color, &tmp_substr);
}

void	recording_file_information(char **split_file, t_cub *cub)
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
			recording_textures(&split_file[i][j], &cub->textur.north, 0);
		else if (!(ft_strncmp(&split_file[i][j], "SO", 2)))
			recording_textures(&split_file[i][j], &cub->textur.south, 0);
		else if (!(ft_strncmp(&split_file[i][j], "WE", 2)))
			recording_textures(&split_file[i][j], &cub->textur.west, 0);
		else if (!(ft_strncmp(&split_file[i][j], "EA", 2)))
			recording_textures(&split_file[i][j], &cub->textur.east, 0);
		else if (!(ft_strncmp(&split_file[i][j], "F", 1)))
			recording_color(&split_file[i][j], cub->textur.color_floor);
		else if (!(ft_strncmp(&split_file[i][j], "C", 1)))
			recording_color(&split_file[i][j], cub->textur.color_ceiling);
		i++;
	}
}
