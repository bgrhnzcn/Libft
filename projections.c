/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:53:25 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/19 01:23:12 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mtx4	orto_init(void)
{
	t_mtx4	mtx;
	t_vec4	col1;
	t_vec4	col2;
	t_vec4	col3;
	t_vec4	col4;

	col1 = vec4_set(2 / (RIGHT - LEFT), 0, 0, 0);
	col2 = vec4_set(0, 2 / (TOP - BOT), 0, 0);
	col3 = vec4_set(0, 0, -2 / (FAR - NEAR), 0);
	col4 = vec4_set(-((RIGHT + LEFT) / (RIGHT - LEFT)),
	-((TOP + BOT) / (TOP - BOT)), -((FAR + NEAR) / (FAR - NEAR)), 1);
	mtx.col1 = col1;
	mtx.col2 = col2;
	mtx.col3 = col3;
	mtx.col4 = col4;
	return (mtx);
}

t_mtx4	pers_init(void)
{
	t_mtx4	mtx;
	t_vec4	col1;
	t_vec4	col2;
	t_vec4	col3;
	t_vec4	col4;

	col1 = vec4_set(0, 0, 0, 0);
	col2 = vec4_set(0, 0, 0, 0);
	col3 = vec4_set(0, 0, 0, 0);
	col4 = vec4_set(0, 0, 0, 0);
	mtx.col1 = col1;
	mtx.col2 = col2;
	mtx.col3 = col3;
	mtx.col4 = col4;
	return (mtx);
}
