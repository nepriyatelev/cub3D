/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_reading_a_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:56:21 by modysseu          #+#    #+#             */
/*   Updated: 2022/04/10 20:07:38 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	error_ft_strdup(int fd)
{
	print_error("Memory allocation error in the function: ", \
		"\nreading_a_file()", "\ntmp == NULL\n", NULL);
	close(fd);
	exit(EXIT_FAILURE);
}

void	error_read(int fd, char **tmp, int rd, char *file)
{
	if (rd == 0)
		print_error("The file ", file, " is empty.\n", NULL);
	else
		print_error("File is ", file, " reading error.\n", NULL);
	free(*tmp);
	close(fd);
	exit(EXIT_FAILURE);
}

void	error_ft_strjoin(char **tmp, int fd)
{
	print_error("The function ft_strjoin() returned NULL: ", \
		"\nreading_a_file()", "\ntmp == NULL\n", NULL);
	free(*tmp);
	close(fd);
	exit(EXIT_FAILURE);
}

void	error_ft_split(char **tmp, int fd)
{
	print_error("The function ft_split() returned NULL: ", \
		"\nreading_a_file()", "\n*split_file == NULL\n", NULL);
	free(*tmp);
	close(fd);
	exit(EXIT_FAILURE);
}
