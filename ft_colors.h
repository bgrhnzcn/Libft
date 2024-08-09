/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 21:34:36 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/07/20 20:12:41 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLORS_H
# define FT_COLORS_H

# include "ft_structs.h"

//---------------------Pre-Defi3ned Colors----------------------//

static const t_color	g_red = (t_color){.value = 0x00ff0000};
static const t_color	g_green = (t_color){.value = 0x0000ff00};
static const t_color	g_blue = (t_color){.value = 0x000000ff};
static const t_color	g_dark_blue = (t_color){.value = 0x0000008b};
static const t_color	g_white = (t_color){.value = 0x00ffffff};
static const t_color	g_black = (t_color){.value = 0x00000000};
static const t_color	g_gray = (t_color){.value = 0x00808080};
static const t_color	g_magenta = (t_color){.value = 0x00ff00ff};
static const t_color	g_cyan = (t_color){.value = 0x0000ffff};
static const t_color	g_yellow = (t_color){.value = 0x00ffff00};
//static const t_color	g_red = (t_color){.value = 0x00ff0000};
//static const t_color	g_red = (t_color){.value = 0x00ff0000};
//static const t_color	g_red = (t_color){.value = 0x00ff0000};

#endif
