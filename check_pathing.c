/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pathing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:49:00 by bhielsch          #+#    #+#             */
/*   Updated: 2022/11/17 14:52:40 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_path(t_m *m, int row, int col)
{
	char	*current;

	current = &m->s[row][col];
	if (*current == 'E')
		return (1);
	if (*current == '0' || *current == 'P' || *current == 'C')
	{
		*current = 'X';
		if (check_path(m, row + 1, col) || check_path(m, row, col + 1))
		{
			*current = 'X';
			return (1);
		}
		else if (check_path(m, row - 1, col) || check_path(m, row, col - 1))
		{
			*current = 'X';
			return (1);
		}
	}
	return (0);
}
