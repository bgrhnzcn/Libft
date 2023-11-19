/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:50:51 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/19 03:10:40 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	deg_to_rad(double deg)
{
	return ((deg / 180) * PI);
}

double	rad_to_deg(double rad)
{
	return (rad * (180 / PI));
}

void	put_pixel(t_img *img, int x, int y, unsigned int color)
{
	char	*point;

	point = (img->data) + ((img->bits_per_pixel / 8) * x) + (img->size_line * y);
	if (img->endian == 1)
	{
		point[0] = (color >> 24);
		point[1] = (color >> 16) & 0xFF;
		point[2] = (color >> 8) & 0xFF;
		point[3] = (color) & 0xFF;
	}
	else if (img->endian == 0)
	{
		point[0] = (color) & 0xFF;
        point[1] = (color >> 8) & 0xFF;
        point[2] = (color >> 16) & 0xFF;
        point[3] = (color >> 24);
	}
}
