/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:03:49 by anporced          #+#    #+#             */
/*   Updated: 2023/12/18 22:22:52 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_entity(char c)
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
	return (0);
}

int	check_wall(t_data *data)
{
	t_axes	size;
	t_axes	i;

	i.y = 0;
	size = data->map_dim;
	while (i.y < size.y)
	{
		i.x = 0;
		while (i.x < size.x)
		{
			if (i.y == 0 || i.y == size.y - 1 || i.x == 0 || i.x == size.x - 1)
				if (data->map[i.y][i.x] != '1')
					return (0);
			if (is_entity(data->map[i.y][i.x]) == 0)
				return (-1);
			i.x++;
		}
		i.y++;
	}
	return (1);
}

void	set_entity(t_data *data, t_axes i, int *j, int *j_z)
{
	find_p_pos(data);
	if (data->map[i.y][i.x] == 'C')
	{
		data->c_pos[*j] = i;
		(*j)++;
		if (path_exist(data->p_pos, i, data) == 0)
			ft_error("Error collectible unreachable", data);
	}
	if (data->map[i.y][i.x] == 'Z')
	{
		data->z_pos[*j_z] = i;
		(*j_z)++;
	}
	if (data->map[i.y][i.x] == 'E')
	{
		data->e_pos = i;
		if (path_exist(data->p_pos, i, data) == 0)
			ft_error("Error exit unreachable", data);
	}
}

void	get_entity_pos(t_data *data)
{
	t_axes		i;
	int			j;
	int			j_z;

	i.y = 0;
	j = 0;
	j_z = 0;
	while (i.y < data->map_dim.y)
	{
		i.x = 0;
		while (i.x < data->map_dim.x)
		{
			set_entity(data, i, &j, &j_z);
			i.x++;
		}
		i.y++;
	}
}

void	check_map(t_data *data)
{
	int	p;
	int	e;

	if (check_wall(data) == 0)
		ft_error("Error map not closed", data);
	if (check_wall(data) == -1)
		ft_error("Error unknown char", data);
	p = nb_char(data, 'P');
	e = nb_char(data, 'E');
	if (p != 1)
		ft_error("Error you should have one player", data);
	if (e != 1)
		ft_error("Error you should have one exit", data);
	if (data->nb_collec < 1)
		ft_error("Error you should have at least one collectible", data);
	get_entity_pos(data);
}
