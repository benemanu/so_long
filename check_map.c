/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:28:29 by bhielsch          #+#    #+#             */
/*   Updated: 2022/11/18 14:24:12 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_m *m)
{
	if (check_rectangle(m) == -1)
		return (-1);
	if (check_player(m) == -1 || check_exit(m) == -1)
	{
		ft_printf("Error:\nItems not working :(");
		return (-2);
	}
	if (check_walls(m) == -1)
		return (-3);
	get_dup(m);
	if (check_path(m, m->p_py, m->p_px) == 0)
	{
		ft_printf("Error:\nNo path to the exit :(");
		return (-4);
	}
	ft_printf("\nThis is a valid map :) ");
	return (0);
}

int	check_rectangle(t_m *m)
{
	int	i;

	i = 1;
	while (i < m->row - 1)
	{
		if (ft_strlen(m->a[i]) == -1 || ft_strlen(m->a[i]) - 1 != m->col)
		{
			ft_printf("Error:\nno rectangle :(");
			return (-1);
		}	
		i++;
	}
	if (ft_strlen(m->a[i]) == -1 || ft_strlen(m->a[i]) != m->col)
	{
		ft_printf("Error:\nno rectangle :(");
		return (-1);
	}
	return (0);
}

int	check_player(t_m *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->row)
	{
		j = 0;
		while (m->a[i][j])
		{
			if (m->a[i][j] == 'P')
			{
				m->p_c = m->p_c + 1;
				m->p_px = m->p_px + j;
				m->p_py = m->p_py + i;
			}
			if (check_char(m->a[i][j]) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	if (m->p_c != 1)
		return (-1);
	return (0);
}

int	check_walls(t_m *m)
{
	int	i;

	i = 1;
	while (m->a[i] && i < m->row - 1)
	{
		if (m->a[i][0] == '1' && m->a[i][m->col - 1] == '1')
			i++;
		else
		{
			ft_printf("Error:\nMap-walls are bad :(");
			return (-1);
		}
	}
	if (check_s(m->a[0]) == -1 || check_s(m->a[m->row - 1]) == -1)
	{
		ft_printf("Error:\nMap-walls are bad :(");
		return (-1);
	}	
	return (0);
}

int	check_exit(t_m *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->row)
	{
		j = 0;
		while (m->a[i][j])
		{
			if (m->a[i][j] == 'E')
			{
				m->e_c = m->e_c + 1;
				m->e_px += j;
				m->e_py += i;
			}
			else if (m->a[i][j] == 'C')
				m->c_c += 1;
			j++;
		}
		i++;
	}
	if (m->e_c != 1 || m->c_c < 1)
		return (-1);
	return (0);
}
