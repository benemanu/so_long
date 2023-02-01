/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:12:27 by bhielsch          #+#    #+#             */
/*   Updated: 2022/11/17 15:28:05 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	input(int key, t_m *m)
{
	mlx_clear_window(m->w.mlx, m->w.win);
	if (key == ESC)
		free_maps(m);
	if (key == UP && m->a[m->w.p_row - 1][m->w.p_col] != '1')
		row_move(m, -1);
	if (key == DOWN && m->a[m->w.p_row + 1][m->w.p_col] != '1')
		row_move(m, +1);
	if (key == RIGHT && m->a[m->w.p_row][m->w.p_col + 1] != '1')
		col_move(m, 1);
	if (key == LEFT && m->a[m->w.p_row][m->w.p_col - 1] != '1')
		col_move(m, -1);
	if (m->w.p_row == m->e_py && m->w.p_col == m->e_px && m->c_c == 0)
	{
		ft_printf("\nWell done, only took you %d moves\n", m->m_c);
		free_maps(m);
	}
	else if (m->w.p_row == m->e_py && m->w.p_col == m->e_px && m->c_c != 0)
		ft_printf("\nCollect all the collectibles first;)\n");
	display_map(m);
	return (0);
}

void	row_move(t_m *m, int input)
{
	ft_printf("movements counted: %d\n", ++m->m_c);
	m->a[m->w.p_row][m->w.p_col] = '0';
	m->w.p_row += input;
	c_check(m);
	m->a[m->w.p_row][m->w.p_col] = 'P';
	if (m->w.p_row - 1 == m->e_py && m->w.p_col == m->e_px)
		m->a[m->w.p_row - 1][m->w.p_col] = 'E';
	else if (m->w.p_row + 1 == m->e_py && m->w.p_col == m->e_px)
		m->a[m->w.p_row + 1][m->w.p_col] = 'E';
}

void	col_move(t_m *m, int input)
{
	ft_printf("movements counted: %d\n", ++m->m_c);
	m->a[m->w.p_row][m->w.p_col] = '0';
	m->w.p_col = m->w.p_col + input;
	c_check(m);
	m->a[m->w.p_row][m->w.p_col] = 'P';
	if (m->w.p_col - 1 == m->e_px && m->w.p_row == m->e_py)
		m->a[m->w.p_row][m->w.p_col - 1] = 'E';
	else if (m->w.p_col + 1 == m->e_px && m->w.p_row == m->e_py)
		m->a[m->w.p_row][m->w.p_col + 1] = 'E';
}

void	c_check(t_m *m)
{
	if (m->a[m->w.p_row][m->w.p_col] == 'C')
		m->c_c--;
}
