/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:25:07 by modysseu          #+#    #+#             */
/*   Updated: 2022/04/14 16:22:45 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{	
		if (str[i])
		{
			free(str[i]);
		}
		i++;
	}
	if (str[i])
	{
		free(str[i]);
	}
	free(str);
}
