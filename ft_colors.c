/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 02:59:42 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/12/01 03:04:28 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color	ft_set_color(uint8_t a, uint8_t r, uint8_t g, uint8_t b)
{
	t_color	color;

	color.a = a / 255.0;
	color.r = r / 255.0;
	color.g = g / 255.0;
	color.b = b / 255.0;
	return (color);
}

t_color	ft_get_gradient_val(t_color from, t_color to, float value)
{
	t_color	color;

	color.a = ft_lerp(value, from.a, to.a);
	color.r = ft_lerp(value, from.r, to.r);
	color.g = ft_lerp(value, from.g, to.g);
	color.b = ft_lerp(value, from.b, to.b);
	return (color);
}

t_color32	ft_color_to_color32(t_color color)
{
	t_color32	color32;

	color32.alpha = color.a * 255;
	color32.red = color.r * 255;
	color32.green = color.g * 255;
	color32.blue = color.b * 255;
	return (color32);
}

t_color	ft_color32_to_color(t_color32 color32)
{
	t_color	color;

	color.a = color32.alpha / 255.0;
	color.r = color32.red / 255.0;
	color.g = color32.green / 255.0;
	color.b = color32.blue / 255.0;
	return (color);
}