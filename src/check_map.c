/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:13:25 by anporced          #+#    #+#             */
/*   Updated: 2023/12/22 15:18:37 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	get_content(t_data *data)
// {
// }

// int	is_walkable(char c)
// {
// 	if (c == 'C' || c == 'E' || c == '0' || c == 'P')
// 		return (1);
// 	return (0);
// }

// int	check_rectangle(t_data *data)
// {

// }

// int	is_entity(char c)
// {
// 	char	charset[7];
// 	int		i;

// 	charset[0] = '1';
// 	charset[1] = '0';
// 	charset[2] = 'P';
// 	charset[3] = 'C';
// 	charset[4] = 'E';
// 	charset[5] = 'Z';
// 	charset[6] = '\0';
// 	i = 0;
// 	while (charset[i])
// 	{
// 		if (c == charset[i])
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int	check_wall(t_data *data)
// {
// 	t_axes	size;
// 	t_axes	i;

// 	i.y = 0;
// 	size = data->map.map_dim;
// 	while (i.y < size.y)
// 	{
// 		i.x = 0;
// 		while (i.x < size.x)
// 		{
// 			if (i.y == 0 || i.y == size.y - 1 || i.x == 0 || i.x == size.x - 1)
// 				if (data->map.map[i.y][i.x] != '1')
// 					return (0);
// 			if (is_entity(data->map.map[i.y][i.x]) == 0)
// 				return (-1);
// 			i.x++;
// 		}
// 		i.y++;
// 	}
// 	return (1);
// }

// void	check_path(t_data *data)
// {

// }

// void	check_map()
// {
// 	check rectangle
// 	check caracteres map(e = 1, p = 1, c > 1)
// 	check path (flood fill) puis destroy ma map si probleme
// }

