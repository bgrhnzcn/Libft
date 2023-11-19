/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bresenham_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:06:06 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/19 01:22:32 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	drw_ln_hlpr_high(t_draw_line *d)
{
	d->x += d->inc;
	d->side_check = d->side_check + (2 * (d->delta.x - d->delta.y));
}

static void	drw_ln_hlpr_low(t_draw_line *d)
{
	d->y += d->inc;
	d->side_check = d->side_check + (2 * (d->delta.y - d->delta.x));
}

static void	draw_line_low(t_img *img, t_vec3 pt1, t_vec3 pt2, unsigned int color)
{
	t_draw_line	d;

	d.delta.x = pt2.x - pt1.x;
	d.delta.y = pt2.y - pt1.y;
	d.inc = 1;
	if (d.delta.y < 0)
	{
		d.inc = -1;
		d.delta.y = -d.delta.y;
	}
	d.side_check = (2 * d.delta.y) - d.delta.x;
	d.y = pt1.y;
	d.x = pt1.x;
	while (d.x < pt2.x && d.x < WIDTH && d.x > 0)
	{
		if (d.y <= HEIGHT && d.y >= 0 && d.x <= WIDTH && d.x >= 0)
			put_pixel(img, d.x, d.y, color);
		if (d.side_check > 0)
			drw_ln_hlpr_low(&d);
		else
			d.side_check = d.side_check + (2 * d.delta.y);
		d.x++;
	}
}

static void	draw_line_high(t_img *img, t_vec3 pt1, t_vec3 pt2, unsigned int color)
{
	t_draw_line	d;

	d.delta.x = pt2.x - pt1.x;
	d.delta.y = pt2.y - pt1.y;
	d.inc = 1;
	if (d.delta.x < 0)
	{
		d.inc = -1;
		d.delta.x = -d.delta.x;
	}
	d.side_check = (2 * d.delta.x) - d.delta.y;
	d.x = pt1.x;
	d.y = pt1.y;
	while (d.y <= pt2.y)
	{
		if (d.y <= HEIGHT && d.y >= 0 && d.x <= WIDTH && d.x >= 0)
			put_pixel(img, d.x, d.y, color);
		if (d.side_check > 0)
			drw_ln_hlpr_high(&d);
		else
			d.side_check = d.side_check + (2 * d.delta.x);
		d.y++;
	}
}

void	draw_line(t_img *img, t_vec3 pt1, t_vec3 pt2, unsigned int color)
{
	if (fabs(pt2.y - pt1.y) < fabs(pt2.x - pt1.x))
	{
		if (pt1.x > pt2.x)
			draw_line_low(img, pt2, pt1, color);
		else
			draw_line_low(img, pt1, pt2, color);
	}
	else
	{
		if (pt1.y > pt2.y)
			draw_line_high(img, pt2, pt1, color);
		else
			draw_line_high(img, pt1, pt2, color);
	}
}
