/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:41:35 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/12/06 17:43:22 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	normalize(double val, double min, double max)
{
	return ((val - min) / (max - min));
}

double	lerp(double val, double min, double max)
{
	return ((val * (max - min)) + min);
}

double	map(double val, t_map map)
{
	return (lerp(normalize(val, map.min_i, map.min_o), map.min_o, map.max_o));
}

t_map	map_init(double min_i, double max_i, double min_o, double max_o)
{
	t_map	map;

	map.max_i = max_i;
	map.max_o = max_o;
	map.min_i = min_i;
	map.min_o = min_o;
	return (map);
}
