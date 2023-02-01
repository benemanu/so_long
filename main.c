/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:58:05 by bhielsch          #+#    #+#             */
/*   Updated: 2022/11/17 15:00:02 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_m	map1;
	t_m	*pmap1;
	int	i;

	pmap1 = &map1;
	i = 0;
	if (argc != 2)
	{
		ft_printf("\nError:\nToo much input!! :(");
		return (0);
	}
	if (get_map(argv[1], pmap1) == -1)
	{
		ft_printf("\nError:\nan error occure");
		return (0);
	}
	if (check_map(pmap1) < 0)
		return (0);
	if (mlx_make(pmap1) == -1)
	{
		ft_printf("\nError:\nMap could not be generated");
		return (0);
	}
	free_maps(pmap1);
	return (0);
}
