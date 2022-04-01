/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:04:20 by modysseu          #+#    #+#             */
/*   Updated: 2022/04/01 18:27:55 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include "../minilibx/mlx.h"

# define WINDOW_WIDTH	640
# define WINDOW_HEIGHT	480

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
}	t_data;

#endif