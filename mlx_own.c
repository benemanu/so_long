/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_own.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:03:58 by bhielsch          #+#    #+#             */
/*   Updated: 2022/11/17 14:44:36 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlx_make(t_m *m)
{
	m->w.mlx = mlx_init();
	m->w.win = mlx_new_window(m->w.mlx, m->col * 32, m->row * 32, "");
	if (read_images(m) == -1)
		return (-1);
	display_map(m);
	mlx_hook(m->w.win, 2, 1L << 0, input, m);
	mlx_hook(m->w.win, 17, 0, mouse_hook, m);
	mlx_loop(m->w.mlx);
	return (0);
}

int	read_images(t_m *m)
{
	m->w.p_col = m->p_px;
	m->w.p_row = m->p_py;
	m->i.ip = mlx_xpm_file_to_image(m->w.mlx, P, m->i.wid, m->i.h);
	m->i.ic = mlx_xpm_file_to_image(m->w.mlx, C, m->i.wid, m->i.h);
	m->i.iw = mlx_xpm_file_to_image(m->w.mlx, W, m->i.wid, m->i.h);
	m->i.ie = mlx_xpm_file_to_image(m->w.mlx, E, m->i.wid, m->i.h);
	m->i.in = mlx_xpm_file_to_image(m->w.mlx, B, m->i.wid, m->i.h);
	if (!m->i.ic || !m->i.in || !m->i.iw || !m->i.ie || !m->i.ip)
		return (-1);
	return (0);
}

void	display_map(t_m *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->row)
	{
		j = 0;
		while (j < m->col)
		{
			if (m->a[i][j] == '1')
				render_pixel(m, i, j, '1');
			else if (m->a[i][j] == '0')
				render_pixel(m, i, j, '0');
			else if (m->a[i][j] == 'E')
				render_pixel(m, i, j, 'E');
			else if (m->a[i][j] == 'P')
				render_pixel(m, i, j, 'P');
			else if (m->a[i][j] == 'C')
				render_pixel(m, i, j, 'C');
			j++;
		}
		i++;
	}
}

void	render_pixel(t_m *m, int y, int x, int index)
{
	int	i;
	int	j;

	i = x * 32;
	j = y * 32;
	if (index == 'C')
		mlx_put_image_to_window(m->w.mlx, m->w.win, m->i.ic, i, j);
	else if (index == '1')
		mlx_put_image_to_window(m->w.mlx, m->w.win, m->i.iw, i, j);
	else if (index == 'E')
		mlx_put_image_to_window(m->w.mlx, m->w.win, m->i.ie, i, j);
	else if (index == 'P')
		mlx_put_image_to_window(m->w.mlx, m->w.win, m->i.ip, i, j);
	else if (index == '0')
		mlx_put_image_to_window(m->w.mlx, m->w.win, m->i.in, i, j);
}

int	mouse_hook(t_m *m)
{
	free_maps(m);
	exit(0);
}
