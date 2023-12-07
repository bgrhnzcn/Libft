/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:20:27 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/12/06 18:06:02 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
//Use X11 on Linux and OpenGL on MAC.
# if GRAPHICS == TRUE
#  include <math.h>
#  include <errno.h>
#  include <fcntl.h>
#  include "structs.h"
#  ifdef __linux__
#   include <X11/keysym.h>
#   define ESC_KEY 65307
#  else
#   define ESC_KEY 53
#  endif
# endif

# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

# if GRAPHICS == TRUE
//Camera Options
//Camera Options
#  define HEIGHT			1000
#  define WIDTH 			1000
#  define TOP				-10.
#  define BOT				10.
#  define RIGHT				-10.
#  define LEFT				10.
#  define NEAR 				1.
#  define FAR 				1000.
//Error codes
#  define INVALID_FORMAT	0
#  define LOAD_ERROR		1
#  define MLX_ERROR			2
//Math Value
#  define PI				3.14159265358979323846
# endif

void	*ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strdup(const char *s);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

# if GRAPHICS == TRUE
/*Gets numbers of strings inside of string arrays.
String arrays must be null-ended.*/
size_t		ft_strarrlen(char **arr);
//Free all the arrays inside double array.
void		free_str_arr(char **str_arr);
/*Hexadecimal version of atoi().
It works both of uppercase and lowercase versions.*/
int			ft_atoi_hex(const char *str);
//Degree to Radian conversions.
double		deg_to_rad(double deg);
//Radian to Degree conversions.
double		rad_to_deg(double rad);
//----------------------------- Mapping ----------------------------------

//Initializes map from given values to use inside map function.
t_map		map_init(double min_i, double max_i, double min_o, double max_o);
/*Gives normalized value (0 to 1 range value)
of given value inside specified range.*/
double		normalize(double val, double min, double max);
/*Gets normalized value (0 to 1 range value)
and gives the value corresponding on specified range.*/
double		lerp(double val, double min, double max);
//This function uses t_map to convert value from one range to another.
double		map(double val, t_map map);

//------------------ Basic Vector Operations -----------------------------

//2D vector setter.
t_vec2		vec2_set(double x, double y);
//2D vector substraction.
t_vec2		vec2_sub(t_vec2	vec1, t_vec2 vec2);
//2D vector addition.
t_vec2		vec2_add(t_vec2 vec1, t_vec2 vec2);
//2D vector multiplication.
t_vec2		vec2_mul(t_vec2 vec, double mul);
//2D vector division.
t_vec2		vec2_div(t_vec2 vec, double div);

//3D vector setter.
t_vec3		vec3_set(double x, double y, double z);
//3D vector substraction.
t_vec3		vec3_sub(t_vec3	vec1, t_vec3 vec2);
//3D vector addition.
t_vec3		vec3_add(t_vec3 vec1, t_vec3 vec2);
//3D vector multiplication.
t_vec3		vec3_mul(t_vec3 vec, double mul);
//3D vector division.
t_vec3		vec3_div(t_vec3 vec, double div);

//4D vector setter.
t_vec4		vec4_set(double x, double y, double z, double w);
//4D vector substraction.
t_vec4		vec4_sub(t_vec4 vec1, t_vec4 vec2);
//4D vector addition.
t_vec4		vec4_add(t_vec4 vec1, t_vec4 vec2);
//4D vector multiplication.
t_vec4		vec4_mul(t_vec4 vec, double mul);
//4D vector division.
t_vec4		vec4_div(t_vec4 vec, double div);

/*This function normalizes 2D vectors.
For detailed info https://en.wikipedia.org/wiki/Unit_vector */
t_vec2		vec2_norm(t_vec2 vec);

/*2D versions of dot product.
For detailed info https://en.wikipedia.org/wiki/Dot_product */
double		vec2_dot(t_vec2 vec1, t_vec2 vec2);
//2D verison of distance function.
double		get_dist2(t_vec2 point1, t_vec2 point);
//2D version of magnitude function. This function gives lenght of 2D vectors.
double		vec2_mag(t_vec2 vec);

/*This function normalizes 3D vectors.
For detailed info https://en.wikipedia.org/wiki/Unit_vector */
t_vec3		vec3_norm(t_vec3 vec);
/*This function gives result of cross product of two 3D vectors.
For detailed info https://en.wikipedia.org/wiki/Cross_product */
t_vec3		vec3_cross(t_vec3 vec1, t_vec3 vec2);

/*3D versions of dot product.
For detailed info https://en.wikipedia.org/wiki/Dot_product */
double		vec3_dot(t_vec3 vec1, t_vec3 vec2);
//3D verison of distance function.
double		get_dist3(t_vec3 point1, t_vec3 point);
//3D version of magnitude function. This function gives lenght of 3D vectors.
double		vec3_mag(t_vec3 vec);

/*This function normalizes 4D vectors.
For detailed info https://en.wikipedia.org/wiki/Unit_vector */
t_vec4		vec4_norm(t_vec4 vec);

/*4D versions of dot product.
For detailed info https://en.wikipedia.org/wiki/Dot_product */
double		vec4_dot(t_vec4 vec1, t_vec4 vec2);
//4D version of magnitude function. This function gives lenght of 4D vectors.
double		vec4_mag(t_vec4 vec);

//----------------------- Basic Graphics Pipeline --------------------------

/*This function creates transformation matrix.
t = Translation, r = Rotation, s = Scale*/
t_mtx4		transform_mtx(t_vec3 t, t_vec3 r, t_vec3 s);
/*Starting point of pipeline.
For detailed info https://en.wikipedia.org/wiki/Graphics_pipeline */
t_vec3		graphic_pipeline(t_mtx4 proj, t_mtx4 mtx_glob,
				t_mtx4 mtx_loc, t_vec3 vec);

//------------------------------ Basic Matrix Functions ---------------------

//3D matrix row setter.
void		set_row3(t_mtx3 *mtx, int row_val, t_vec3 row);
//Get values in row of 3D matrix.
t_vec3		get_row3(t_mtx3 mtx, int row_val);
//3D matrix 3D vector multiplication.
t_vec3		mtx_vec_mul3(t_mtx3 mtx, t_vec3 vec);
//3D matrix 3D matrix multiplication.
t_mtx3		mtx_mtx_mul3(t_mtx3 mtx1, t_mtx3 mtx2);

//4D matrix row setter.
void		set_row4(t_mtx4 *mtx, int row_val, t_vec4 row);
//Get values in row of 4D matrix.
t_vec4		get_row4(t_mtx4 mtx, int row_val);
//4D matrix 4D vector multiplication.
t_vec4		mtx_vec_mul4(t_mtx4 mtx, t_vec4 vec);
//4D matrix 4D matrix multiplication.
t_mtx4		mtx_mtx_mul4(t_mtx4 mtx1, t_mtx4 mtx2);

//3D vector to 4D vector conversion.
t_vec4		vec3_to_vec4(t_vec3 vec3, double w);
//4D vector to 3D vector conversion.
t_vec3		vec4_to_vec3(t_vec4 vec4);

//------------------------- Color Functions ---------------------------

/*4 channel int value color setter.
a = Alpha, r = Red, g = Green, b = Blue*/
t_color		set_color(__uint8_t a, __uint8_t r, __uint8_t g, __uint8_t b);
//Returns gradient value from given normalized value.
t_color		get_gradient_val(t_color from, t_color to, double value);
//Gradient initializer.
t_gradient	set_gradient(t_color from, t_color to);
//Gradient inverter.
t_gradient	inv_gradient(t_gradient in);

//---------------------------- Draw Functions --------------------------

void		put_pixel(t_img *img, int x, int y, t_color color);
void		fill_img(t_img *img, t_color color);
void		draw_line(t_img *img, t_vec3 pt1, t_vec3 pt2, t_color color);
void		gradient_line(t_img *img, t_vec3 pt1, t_vec3 pt2, t_gradient grad);
void		draw_tri(t_data *data, t_tri *tris, int j, t_color color);

//----------------------------- Mesh Functions -------------------------

int			data_counter(int obj_file, char type);
int			get_vertex_data(t_get_vert *ver);
t_vec3		*get_vertices(char *obj_path, int *ver_count);
int			get_triangle_data(t_get_tris *tris, t_vec3 *vertices);
t_tri		*get_triangles(char *obj_path, t_vec3 *vertices, int *tri_count);
t_mesh		mesh_init(char *obj_path);

//------------------------------ Projections ----------------------------

//Orthographic projection initializer.
t_mtx4		orto_init(void);
//Perspective projection initializer.
t_mtx4		pers_init(void);

# endif
#endif