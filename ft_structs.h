/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:34:50 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/07/20 20:12:12 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H
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

typedef enum e_bool
{
	error = -1,
	false,
	true
}	t_bool;

typedef struct s_vector
{
	size_t	type_size;
	size_t	buffer_size;
	size_t	lenght;
	char	buffer[1];
}	t_vector;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	int		count;
	t_list	*top;
}	t_stack;

typedef enum e_types
{
	type_str = sizeof(void *),
	type_int = sizeof(int),
	type_char = sizeof(char),
	type_pointer = sizeof(void *)
}	t_types;
//can be changed
typedef struct s_kv_pair
{
	void				*key;
	void				*value;
	t_bool				is_filled;
	struct s_kv_pair	*next;
}	t_kv_pair;
//make more research about listing collision
typedef struct s_hash_table
{
	size_t		(*hash)(void *data, size_t type);
	t_kv_pair	*table;
	t_types		key_type;
	t_types		value_type;
	size_t		table_size;
}	t_hash_table;

typedef struct s_map
{
	float	min_i;
	float	max_i;
	float	min_o;
	float	max_o;
}	t_map;

typedef union u_vec2
{
	struct
	{
		float	x;
		float	y;
	};
	float	data[2];
}	t_vec2;

typedef union u_vec3
{
	struct
	{
		float	x;
		float	y;
		float	z;
	};
	float	data[3];
}	t_vec3;

typedef struct s_gradient
{
	t_color	from;
	t_color	to;
}	t_gradient;

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
		float	x;
		float	y;
		float	z;
		float	w;
	};
	float	data[4];
}	t_vec4;

typedef union u_mtx3
{
	struct
	{
		t_vec3	col1;
		t_vec3	col2;
		t_vec3	col3;
	};
	float	data[9];
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
	float	data[16];
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
	t_color	*data;
	int		bits_per_pixel;
	int		size_line;
	int		line_count;
	int		endian;
}	t_img;

typedef struct s_draw_line
{
	t_vec2	delta;
	float	inc;
	float	side_check;
	float	x;
	float	y;
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

typedef struct s_win
{
	void	*win;
	int		width;
	int		height;
}	t_win;

typedef struct s_mlx
{
	void		*mlx;
	t_win		win;
	t_img		img;
	int			time;
}	t_mlx;

#endif
