/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:33:47 by anporced          #+#    #+#             */
/*   Updated: 2024/01/29 20:08:30 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(t_map map_infos, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_infos.map_dim.y)
	{
		j = -1;
		while (++j < map_infos.map_dim.x)
		{
			if (map[i][j] == '0')
				ft_printf("\x1b[92m");
			if (map[i][j] == '1')
				ft_printf("\x1b[91m");
			ft_printf("%c", map[i][j]);
			if (map[i][j] == '1' || map[i][j] == '0')
				ft_printf("\x1b[0m");
		}
		ft_printf("\n");
	}
}

char	**malloc_map_check(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	i = -1;
	map = malloc(sizeof(char *) * data->map.map_dim.y + 1);
	while (++i < data->map.map_dim.y)
	{
		j = -1;
		map[i] = malloc(sizeof(char) * data->map.map_dim.x + 1);
		while (++j < data->map.map_dim.x)
			map[i][j] = '0';
	}
	return (map);
}
