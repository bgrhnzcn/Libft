/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec2_vec2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:32:30 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/06/16 00:34:19 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec2	ft_vec2_inv(t_vec2 vec)
{
	t_vec2	vec2_res;

	vec2_res.x = -vec.x;
	vec2_res.y = -vec.y;
	return (vec2_res);
}

t_vec2	ft_vec2_norm(t_vec2 vec)
{
	return (ft_vec2_div(vec, ft_vec2_mag(vec)));
}

t_vec2	ft_vec2_rot(t_vec2 vec, float deg)
{
	t_vec2	res;
	float	rad;

	rad = ft_deg_to_rad(deg);
	res.x = ((vec.x * cos(rad)) - (vec.y * sin(rad)));
	res.y = ((vec.x * sin(rad)) + (vec.y * cos(rad)));
	return (res);
}
