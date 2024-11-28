/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:42:40 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/28 15:30:49 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_color	ft_read_pixel(t_img *img, int x, int y)
{
	t_color32	pixel;
	t_color		color;

	pixel = img->data[x + (img->size_line * y)];
	color.a = pixel.alpha / 255.0;
	color.r = pixel.red / 255.0;
	color.g = pixel.green / 255.0;
	color.b = pixel.blue / 255.0;
	return (color);
}

void	ft_put_pixel(t_img *img, int x, int y, t_color color)
{
	t_color32	pixel;

	pixel.alpha = color.a * 255;
	pixel.red = color.r * 255;
	pixel.green = color.g * 255;
	pixel.blue = color.b * 255;
	img->data[x + (img->size_line * y)] = pixel;
}

void	ft_fill_img(t_win *win, t_img *img, t_color color)
{
	int	i;
	int	j;

	i = 0;
	while (i < win->width)
	{
		j = 0;
		while (j < win->height)
		{
			ft_put_pixel(img, i, j, color);
			j++;
		}
		i++;
	}
}
