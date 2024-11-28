/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 02:59:42 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/28 00:01:54 by bgrhnzcn         ###   ########.fr       */
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
