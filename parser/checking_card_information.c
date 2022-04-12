/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_card_information.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:15:12 by modysseu          #+#    #+#             */
/*   Updated: 2022/04/12 21:28:49 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// static void	error_checking_nswefc(char ***split_file, int fd, \
// 		char *nswefc, int count)
// {
// 	char	*c;

// 	c = ft_itoa(count);
// 	if (c == NULL)
// 		print_error("Memory allocation error in the function: ", \
// 		"\nft_itoa()", "\nc == NULL\n", NULL);
// 	print_error("There are invalid characters in the file: the number of \"", \
// 		nswefc, "\" = ", c);
// 	write(2, "\n", 2);
// 	free(c);
// 	ft_free_matrix(*split_file);
// 	close(fd);
// 	exit(EXIT_FAILURE);
// }

// static void	checking_nswe(char ***split_file, char *nswe, int fd)
// {
// 	int		i;
// 	int		count;

// 	i = 0;
// 	count = 0;
// 	while (i < 6)
// 	{
// 		if (!(ft_strncmp((*split_file)[i], nswe, 2)) \
// 			&& !(ft_strncmp(&(*split_file)[i][2], " ", 1)))
// 			count++;
// 		i++;
// 	}
// 	if (count != 1)
// 		error_checking_nswefc(split_file, fd, nswe, count);
// }

// static void	checking_color(char ***split_file, char *color, int fd)
// {
// 	int		i;
// 	int		count;

// 	i = 0;
// 	count = 0;
// 	while (i < 6)
// 	{
// 		if (!(ft_strncmp((*split_file)[i], color, 1)) \
// 			&& !(ft_strncmp(&(*split_file)[i][1], " ", 1)))
// 			count++;
// 		i++;
// 	}
// 	if (count != 1)
// 		error_checking_nswefc(split_file, fd, color, count);
// }

void	checking_line(char *line)
{
	int	i;
	int	count_word;

	i = 0;
	count_word = 0;
	if (!(ft_isspace(line[i])))
		count_word++;
	while (line[i])
	{
		if (ft_isspace(line[i]))
		{
			while (ft_isspace(line[i]) && line[i])
				i++;
			if (line[i] != '\0')
				count_word++;
		}
		else
			i++;
	}
	if (count_word != 2)
		print_error("Incorrectly submitted information: \"", line, "\".\n", NULL);
}

void	checking_card_information(char **split_file, int fd)
{
	int	i;

	i = 0;
	while(i < 6)
	{
		checking_line(split_file[i]);
		i++;
	}
}


// checking_nswe(split_file, "NO", fd);
// 	checking_nswe(split_file, "SO", fd);
// 	checking_nswe(split_file, "WE", fd);
// 	checking_nswe(split_file, "EA", fd);
// 	checking_color(split_file, "F", fd);
// 	checking_color(split_file, "C", fd);