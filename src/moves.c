/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:59:49 by anporced          #+#    #+#             */
/*   Updated: 2024/01/08 12:24:49 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	moves(t_data *data, t_axes dest_pos)
{
	evolve(data, dest_pos);
	if (is_walkable(data->map.map[dest_pos.y][dest_pos.x]))
	{
		print_img(data, data->assets.textures[0].img, data->player.p_pos);
		overlay_img(data->assets.player
		[data->player.state][data->player.direction],
			data->assets.textures[0], data, dest_pos);
		data->map.map[data->player.p_pos.y][data->player.p_pos.x] = '0';
		data->player.p_pos = dest_pos;
		if (data->map.map[dest_pos.y][dest_pos.x] == 'C')
			data->player.got_c++;
	}
	else
		overlay_img(data->assets.player
		[data->player.state][data->player.direction],
			data->assets.textures[0], data, data->player.p_pos);
}

int	move_up(t_data *data)
{
	t_axes	dest;

	data->player.direction = 2;
	dest.x = data->player.p_pos.x;
	dest.y = data->player.p_pos.y - 1;
	moves(data, dest);
}

int	move_down(t_data *data)
{
	t_axes	dest;

	data->player.direction = 0;
	dest.x = data->player.p_pos.x;
	dest.y = data->player.p_pos.y + 1;
	moves(data, dest);
}

int	move_left(t_data *data)
{
	t_axes	dest;

	data->player.direction = 4;
	dest.x = data->player.p_pos.x - 1;
	dest.y = data->player.p_pos.y;
	moves(data, dest);
}

int	move_right(t_data *data)
{
	t_axes	dest;

	data->player.direction = 6;
	dest.x = data->player.p_pos.x + 1;
	dest.y = data->player.p_pos.y;
	moves(data, dest);
}
