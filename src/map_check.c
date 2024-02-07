/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:13:25 by anporced          #+#    #+#             */
/*   Updated: 2024/02/07 11:57:13 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_entity(char c, t_data *data)
{
	char	charset[7];
	int		i;

	charset[0] = '1';
	charset[1] = '0';
	charset[2] = 'P';
	charset[3] = 'C';
	charset[4] = 'E';
	charset[5] = 'Z';
	charset[6] = '\0';
	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	ft_printf("At least one character is wrong, you can only use \
	'P', 'C', 'Z', 'E', '0' and '1'.\n");
	quit_early(data);
	return (0);
}

void	get_content(t_data *data)
{
	t_axes	i;

	i.y = 0;
	while (i.y < data->map.map_dim.y)
	{
		i.x = 0;
		while (i.x < data->map.map_dim.x)
		{
			if (data->map.map[i.y][i.x] == 'C')
				lst_collec(data, i);
			else if (data->map.map[i.y][i.x] == 'Z')
				lst_enemies(data, i);
			else if (data->map.map[i.y][i.x] == 'E')
				data->map.nb_e++;
			else if (data->map.map[i.y][i.x] == 'P')
				data->map.nb_p++;
			i.x++;
		}
		i.y++;
	}
	data->map.nb_c = collec_lst_size(data->collectibles);
}

int	check_wall(t_data *data)
{
	t_axes	size;
	t_axes	i;

	i.y = -1;
	size = data->map.map_dim;
	while (++i.y < size.y)
	{
		i.x = -1;
		while (++i.x < size.x)
		{
			if (i.y == 0 || i.y == size.y - 1 || i.x == 0 || i.x == size.x - 1)
				if (data->map.map[i.y][i.x] != '1')
					return (0);
			if (is_entity(data->map.map[i.y][i.x], data) == 0)
				return (0);
			if (data->map.nb_p != 1 || data->map.nb_e != 1
				|| data->map.nb_c < 1)
			{
				ft_printf("You need one 'P' and 'E' and at least one 'C'.\n");
				return (0);
			}
		}
	}
	return (1);
}

void	dfs(t_axes pos, char **visited, t_data *data)
{
	t_axes	neighbors[4];
	int		i;

	i = -1;
	if (pos.y < 0 || pos.y >= data->map.map_dim.y || pos.x < 0
		|| pos.x >= data->map.map_dim.x)
		return ;
	if (data->map.map[pos.y][pos.x] == '1' || visited[pos.y][pos.x] == '1')
		return ;
	visited[pos.y][pos.x] = '1';
	if (data->map.map[pos.y][pos.x] == 'C')
		data->map.accessible_c++;
	if (data->map.map[pos.y][pos.x] == 'E')
		data->map.accessible_e++;
	if (data->map.map[pos.y][pos.x] == 'P')
		data->map.accessible_p++;
	while (++i < 4)
		neighbors[i] = find_dir(pos, i * 2);
	i = -1;
	while (++i < 4)
		dfs(neighbors[i], visited, data);
}

void	check_map(t_data *data)
{
	init_map(data);
	get_content(data);
	data->map.map_checker = malloc_map_check(data);
	player_finder(data);
	if (!check_wall(data))
		quit_early(data);
	dfs(data->player.p_pos, data->map.map_checker, data);
	if (data->map.accessible_c != data->map.nb_c
		|| data->map.accessible_e != data->map.nb_e)
	{
		ft_printf("All your collectibles and the exit must be accessible.\n");
		quit_early(data);
	}
}
