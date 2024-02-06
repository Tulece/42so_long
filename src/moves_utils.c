/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:27:42 by anporced          #+#    #+#             */
/*   Updated: 2024/01/29 16:44:45 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_walkable(t_axes pos, t_data *data)
{
	char	c;

	c = data->map.map[pos.y][pos.x];
	if (z_find_by_pos(data, pos))
		return (0);
	if (c == 'C' || c == '0' || (c == 'E'
			&& (data->player.got_c == data->map.nb_c)))
		return (1);
	return (0);
}

void	turn(t_data *data, t_axes dest_pos, int dir)
{
	evolve(data, dest_pos);
	if (dir != data->player.direction)
	{
		data->player.direction = dir;
		overlay_img(data->assets.player[data->player.state]
		[data->player.direction], data->assets.textures[0],
			data, data->player.p_pos);
	}
}

t_axes	find_dir(t_axes pos, int dir)
{
	if (dir == 0)
		pos.y++;
	else if (dir == 2)
		pos.y--;
	else if (dir == 4)
		pos.x--;
	else if (dir == 6)
		pos.x++;
	return (pos);
}
