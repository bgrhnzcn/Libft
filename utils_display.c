/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:42:40 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/19 02:37:24 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	draw_tri(t_data *data, t_tri *tris, int j, unsigned int color)
{
	draw_line(&(data)->img, tris[j].pts[0],
		tris[j].pts[1], color);
	draw_line(&(data)->img, tris[j].pts[1],
		tris[j].pts[2], color);
	draw_line(&(data)->img, tris[j].pts[2],
		tris[j].pts[0], color);
}

void	fill_img(t_data *data, unsigned int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			put_pixel(&(data->img), i, j, color);
			j++;
		}
		i++;
	}
}
