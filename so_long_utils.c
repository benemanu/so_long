/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:45:20 by bhielsch          #+#    #+#             */
/*   Updated: 2022/11/17 14:48:37 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

int	get_col(char *map)
{
	int	i;

	i = ft_strlen(map) - 1;
	if (i == -1)
		return (-1);
	return (i);
}

int	get_rows(char *map_name)
{
	char	*mybuffer;
	int		i;
	int		j;
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	j = 0;
	i = 1;
	mybuffer = malloc(sizeof (char *) * 1);
	while (i != 0)
	{
		i = read(fd, mybuffer, 1);
		if (i == -1)
			return (-1);
		if (i == 0)
			break ;
		if (mybuffer[0] == '\n')
			j++;
	}
	j++;
	free (mybuffer);
	close(fd);
	return (j);
}

int	check_s(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

void	get_dup(t_m *m)
{
	int	i;

	i = 0;
	while (i < m->row)
	{
		m->s[i] = ft_strdup(m->a[i]);
		i++;
	}
}

int	check_char(char c)
{
	if (c == 'E' || c == 'C' || c == 'P' )
		return (0);
	else if (c == '1' || c == '0' || c == '\n')
		return (0);
	else
		return (-1);
}
