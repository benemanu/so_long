/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:56:26 by bhielsch          #+#    #+#             */
/*   Updated: 2022/11/17 14:57:35 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map(char *map_name, t_m *m)
{
	int	i;
	int	fd;

	get_struct_params(m);
	fd = get_fd(map_name);
	m->row = get_rows(map_name);
	if (m->row == -1)
		return (-1);
	i = 0;
	m->a = malloc(sizeof(char *) * m->row);
	m->s = malloc(sizeof(char *) * m->row);
	if (!m->a || !m->s)
		return (-1);
	while (i < m->row)
	{
		m->a[i] = get_next_line(fd);
		i++;
	}
	i = get_col(m->a[0]);
	if (i == -1)
		return (-1);
	m->col = i;
	return (0);
}

int	get_fd(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	return (fd);
}

void	get_struct_params(t_m *m)
{
	int	i;

	i = 32;
	m->wa = 0;
	m->p = 0;
	m->c = 0;
	m->e = 0;
	m->col = 0;
	m->row = 0;
	m->p_c = 0;
	m->e_c = 0;
	m->c_c = 0;
	m->p_px = 0;
	m->p_py = 0;
	m->m_c = 0;
	m->e_px = 0;
	m->e_py = 0;
	m->i.wid = &i;
	m->i.h = &i;
}

void	print_map(t_m *m)
{
	int	i;

	i = -1;
	ft_printf("\na:\n");
	while (++i < m->row)
		ft_printf("%s", m->a[i]);
	ft_printf("\ns:\n");
	i = -1;
	while (++i < m->row)
		ft_printf("%s", m->s[i]);
	ft_printf("\n");
}
