/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:34:50 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/19 02:58:54 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

typedef union u_color
{
	struct
	{
		unsigned char	alpha;
		unsigned char	red;
		unsigned char	green;
		unsigned char	blue;
	};
	unsigned int	value;
}	t_color;
# else

typedef union u_color
{
	struct
	{
		unsigned char	blue;
		unsigned char	green;
		unsigned char	red;
		unsigned char	alpha;
	};
	unsigned int	value;
}	t_color;
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_map
{
	double	min_i;
	double	max_i;
	double	min_o;
	double	max_o;
}	t_map;

typedef union u_vec2
{
	struct
	{
		double	x;
		double	y;
	};
	double	data[2];
}	t_vec2;

typedef union u_vec3
{
	struct
	{
		double	x;
		double	y;
		double	z;
	};
	double	data[3];
}	t_vec3;

typedef union u_tri
{
	struct
	{
		t_vec3	p1;
		t_vec3	p2;
		t_vec3	p3;
	};
	t_vec3	pts[3];
}	t_tri;

typedef union u_vec4
{
	struct
	{
		double	x;
		double	y;
		double	z;
		double	w;
	};
	double	data[4];
}	t_vec4;

typedef union u_mtx3
{
	struct
	{
		t_vec3	col1;
		t_vec3	col2;
		t_vec3	col3;
	};
	double	data[9];
}	t_mtx3;

typedef union u_mtx4
{
	struct
	{
		t_vec4	col1;
		t_vec4	col2;
		t_vec4	col3;
		t_vec4	col4;
	};
	double	data[16];
}	t_mtx4;

typedef struct s_mesh
{
	t_tri	*mesh;
	int		tri_count;
	int		ver_count;
}	t_mesh;

typedef struct s_img
{
	void	*img;
	char	*data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_vec3_base
{
	const t_vec3	vec3_i;
	const t_vec3	vec3_j;
	const t_vec3	vec3_k;
	const t_vec3	vec3_null;
}	t_vec3_base;

typedef struct s_mtx3_base
{
	const t_mtx3	mtx3_null;
	const t_mtx3	mtx3_ident;
}	t_mtx3_base;

typedef struct s_draw_line
{
	t_vec2	delta;
	double	inc;
	double	side_check;
	double	x;
	double	y;
}	t_draw_line;

typedef struct s_get_verteces
{
	t_vec3	*vertices;
	char	*line;
	char	**datas;
	int		obj_file;
	int		index;
}	t_get_vert;

typedef struct s_get_tris
{
	t_tri	*tris;
	char	*line;
	char	**datas;
	int		obj_file;
	int		index;
}	t_get_tris;

typedef struct s_fdf_map
{
	t_vec3			*vertexes;
	unsigned int	*vertex_colors;
	int				map_x;
	int				map_y;
}	t_fdf_map;

typedef struct s_fdf_data
{
	char		**data;
	char		*line;
	int			fdf_file;
	int			i;
	int			j;
}	t_fdf_data;

typedef struct s_data
{
	t_mtx4		pers_mtx;
	t_mtx4		orto_mtx;
	void		*mlx;
	void		*win;
	t_img		img;
	t_mesh		mesh;
	int			time;
	t_fdf_map	*map;
}	t_data;

#endif
