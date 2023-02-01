/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:28:51 by bhielsch          #+#    #+#             */
/*   Updated: 2022/11/17 15:41:02 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <unistd.h>

# define C "sprites/beer-32.xpm"
# define W "sprites/square-dashed-rounded-32.xpm"
# define E "sprites/exit-32.xpm"
# define P "sprites/running-man-32.xpm"
# define B "sprites/square-32.xpm"

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

typedef struct s_window
{
	int			p_row;
	int			p_col;
	void		*mlx;
	void		*win;
}				t_window;

typedef struct s_image
{
	void		*ic;
	void		*ie;
	void		*ip;
	void		*in;
	void		*iw;
	int			*wid;
	int			*h;
}				t_image;

typedef struct s_m
{
	int			wa;
	int			p;
	int			c;
	int			e;
	int			col;
	int			row;
	int			p_c;
	int			e_c;
	int			c_c;
	int			p_px;
	int			p_py;
	int			m_c;
	int			e_px;
	int			e_py;
	char		**a;
	char		**s;
	t_window	w;
	t_image		i;
}				t_m;

int				main(int argc, char **argv);
int				get_col(char *map);
int				get_rows(char *map_name);
int				check_s(char *str);
void			get_dup(t_m *m);
int				check_exit(t_m *m);
int				input(int key, t_m *m);
int				mlx_make(t_m *m);
int				read_images(t_m *m);
void			display_map(t_m *m);
void			render_pixel(t_m *m, int y, int x, int index);
int				check_map(t_m *m);
int				check_rectangle(t_m *m);
int				check_player(t_m *m);
int				check_walls(t_m *m);
int				check_path(t_m *m, int row, int col);
int				get_map(char *m_name, t_m *m);
int				get_fd(char *str);
void			get_struct_params(t_m *m);
void			print_map(t_m *m);
void			free_maps(t_m *m);
int				mouse_hook(t_m *m);
void			c_check(t_m *m);
void			col_move(t_m *m, int input);
void			row_move(t_m *m, int input);
int				read_images(t_m *m);
void			display_map(t_m *m);
void			render_pixel(t_m *m, int y, int x, int index);
int				mouse_hook(t_m *m);
int				check_char(char c);

#endif