/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:57:03 by anporced          #+#    #+#             */
/*   Updated: 2023/12/22 12:27:04 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	data_init(t_data *data)
{
	data->player.nb_p = 0;
	data->enemies.nb_z = 0;
	data->collectibles.nb_c = 0;
	data->portal.nb_e = 0;
	data->player.step_count = 0;
	data->player.p_pos.x = 0;
	data->player.p_pos.y = 0;
	data->clock = 0;
	data->frame = 0;
	data->direction = 0;
	data->player.dest_pos.x = 0;
	data->player.dest_pos.y = 0;
	data->player.state = 0;
}

char	*path_creator(char *pokemon, int i)
{
	char	*number;
	char	*str;
	char	*path;

	number = ft_itoa(i);
	str = ft_strjoin(pokemon, number);
	free(number);
	path = ft_strjoin(str, ".xpm");
	free(str);
	return (path);
}

void	player_finder(t_data *data)
{
	t_axes	i;

	i.y = 0;
	while (i.y < data->map.map_dim.y)
	{
		i.x = 0;
		while (i.x < data->map.map_dim.x)
		{
			if (data->map.map[i.y][i.x] == 'P')
				data->player.p_pos = i;
			i.x++;
		}
		i.y++;
	}
}
