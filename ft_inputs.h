/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 21:20:28 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/24 15:52:48 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INPUTS_H
# define FT_INPUTS_H

# define MAX_KEY_COUNT 34

# define ESC_KEY 0
# define Q_KEY 1
# define W_KEY 2
# define E_KEY 3
# define R_KEY 4
# define T_KEY 5
# define Y_KEY 6
# define U_KEY 7
# define I_KEY 8
# define O_KEY 9
# define P_KEY 10
# define A_KEY 11
# define S_KEY 12
# define D_KEY 13
# define F_KEY 14
# define G_KEY 15
# define H_KEY 16
# define J_KEY 17
# define K_KEY 18
# define L_KEY 19
# define Z_KEY 20
# define X_KEY 21
# define C_KEY 22
# define V_KEY 23
# define B_KEY 24
# define N_KEY 25
# define M_KEY 26
# define SPACE_KEY 27
# define RIGHT_KEY 28
# define LEFT_KEY 29
# define UP_KEY 30
# define DOWN_KEY 31
# define SHIFT_KEY 32
# define CTRL_KEY 33

# ifdef __linux__

#  include <X11/keysym.h>

static const int	g_keysym_to_keycode[MAX_KEY_COUNT] = {
[ESC_KEY] = XK_Escape,
[Q_KEY] = XK_q,
[W_KEY] = XK_w,
[E_KEY] = XK_e,
[R_KEY] = XK_r,
[T_KEY] = XK_t,
[Y_KEY] = XK_y,
[U_KEY] = XK_u,
[I_KEY] = XK_i,
[O_KEY] = XK_o,
[P_KEY] = XK_p,
[A_KEY] = XK_a,
[S_KEY] = XK_s,
[D_KEY] = XK_d,
[F_KEY] = XK_f,
[G_KEY] = XK_g,
[H_KEY] = XK_h,
[J_KEY] = XK_j,
[K_KEY] = XK_k,
[L_KEY] = XK_l,
[Z_KEY] = XK_z,
[X_KEY] = XK_x,
[C_KEY] = XK_c,
[V_KEY] = XK_v,
[B_KEY] = XK_b,
[N_KEY] = XK_n,
[M_KEY] = XK_m,
[SPACE_KEY] = XK_space,
[RIGHT_KEY] = XK_Right,
[LEFT_KEY] = XK_Left,
[UP_KEY] = XK_Up,
[DOWN_KEY] = XK_Down,
[SHIFT_KEY] = XK_Shift_L,
[CTRL_KEY] = XK_Control_L
};

# else

static const int	g_keysym_to_keycode[MAX_KEY_COUNT] = {
[ESC_KEY] = 53,
[Q_KEY] = 12,
[W_KEY] = 13,
[E_KEY] = 14,
[R_KEY] = 15,
[T_KEY] = 17,
[Y_KEY] = 16,
[U_KEY] = 32,
[I_KEY] = 34,
[O_KEY] = 31,
[P_KEY] = 35,
[A_KEY] = 0,
[S_KEY] = 1,
[D_KEY] = 2,
[F_KEY] = 3,
[G_KEY] = 5,
[H_KEY] = 4,
[J_KEY] = 38,
[K_KEY] = 40,
[L_KEY] = 37,
[Z_KEY] = 6,
[X_KEY] = 7,
[C_KEY] = 8,
[V_KEY] = 9,
[B_KEY] = 11,
[N_KEY] = 45,
[M_KEY] = 46,
[SPACE_KEY] = 49,
[RIGHT_KEY] = 124,
[LEFT_KEY] = 123,
[UP_KEY] = 126,
[DOWN_KEY] = 125,
[SHIFT_KEY] = 56,
[CTRL_KEY] = 59
};

# endif

typedef enum e_mlx_event
{
	KeyPress = 2,
	KeyRelease = 3,
	ButtonPress = 4,
	ButtonRelease = 5,
	MotionNotify = 6,
	Expose = 12,
	Destroy = 17
}	t_mlx_event;

typedef enum e_mlx_event_mask
{
	KeyPressMask = (1L<<0),
	KeyReleaseMask = (1L<<1),
	ButtonPressMask = (1L<<2),
	ButtonReleaseMask = (1L<<3),
	MotionNotifyMask = (1L<<6),
	ExposeMask = (1L<<15),
	DestroyMask = (1L<<17)
}	t_mlx_event_mask;

#endif
