/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:58:24 by buozcan           #+#    #+#             */
/*   Updated: 2024/01/18 18:34:54 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_vec3_dot(t_vec3 vec1, t_vec3 vec2)
{
	float	res;

	res = 0;
	res += vec1.x * vec2.x;
	res += vec1.y * vec2.y;
	res += vec1.z * vec2.z;
	return (res);
}

float	ft_vec3_dist(t_vec3 point1, t_vec3 point2)
{
	t_vec3	sub;

	sub = ft_vec3_sub(point1, point2);
	return (sqrt(ft_vec3_dot(sub, sub)));
}

float	ft_vec3_mag(t_vec3 vec)
{
	return (ft_vec3_dist(g_vec3_null, vec));
}

t_bool	ft_vec3_equ(t_vec3 vec1, t_vec3 vec2)
{
	if (fabs(vec1.x) - fabs(vec2.x) < EPSILON
		&& fabs(vec1.y) - fabs(vec2.y) < EPSILON
		&& fabs(vec1.z) - fabs(vec2.z) < EPSILON)
		return (true);
	return (false);
}
