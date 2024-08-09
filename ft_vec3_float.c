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
	return (sqrt(ft_vec3_dot(point1, point2)));
}

float	ft_vec3_mag(t_vec3 vec)
{
	return (ft_vec3_dist(ft_vec3_set(0, 0, 0), vec));
}
