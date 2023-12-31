INCLUDES_LINUX = -I/usr/include -Imlx -I .

INCLUDES_MAC = -I .

NAME = libft.a

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

MLX_FLAGS_LINUX = linux_lib/libftprintf.a linux_lib/get_next_line.a linux_lib/libft.a libmlx.a\
			-Bdynamic -L/usr/lib/X11 -lXext -lX11 -lm

MLX_FLAGS_MAC = mac_lib/libft.a mac_lib/get_next_line.a mac_lib/libftprintf.a mac_lib/libmlx.a -Bdynamic -framework OpenGL -framework AppKit

SRCS = mtx3_basic.c mtx4_basic.c transforms.c \
	utils_bresenham_line.c utils_display.c map.c utils.c vec_conv.c \
	vec2_double.c vec2_op.c vec2_vec2.c vec3_double.c vec3_op.c vec3_vec3.c\
	vec4_double.c vec4_op.c vec4_vec4.c mesh_init.c mesh_init_utils.c \
	colors.c gradient_line.c arrays.c pipeline.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	ft_isascii.c ft_isprint.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c  ft_split.c  ft_strmapi.c ft_putnbr_fd.c\
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c  \
	ft_strtrim.c ft_itoa.c

ifeq ($(shell uname),Linux)
	MLX_FLAGS = $(MLX_FLAGS_LINUX)
	INCLUDES = $(INCLUDES_LINUX)
else
	MLX_FLAGS = $(MLX_FLAGS_MAC)
	INCLUDES = $(INCLUDES_MAC)
endif

OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $(INCLUDES) $?

$(NAME): $(OBJ)
	ar -rcsl $(NAME) $(OBJ)

all: $(NAME)

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf *.o

re: fclean all
