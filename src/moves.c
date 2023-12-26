/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:59:49 by anporced          #+#    #+#             */
/*   Updated: 2023/12/22 12:28:18 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	moves(t_data *data, t_axes dest_pos)
{
	print_img(data, data->assets.textures[0].img, data->player.p_pos);
	overlay_img(data->assets.player[data->player.state][data->direction],
		data->assets.textures[0], data, dest_pos);
	data->map.map[dest_pos.y][dest_pos.x] = 'P';
	data->map.map[data->player.p_pos.y][data->player.p_pos.x] = '0';
}

int	move_up(t_data *data)
{
	t_axes	dest;

	player_finder(data);
	data->direction = 2;
	dest.x = data->player.p_pos.x;
	dest.y = data->player.p_pos.y - 1;
	moves(data, dest);
}

int	move_down(t_data *data)
{
	t_axes	dest;

	player_finder(data);
	data->direction = 0;
	dest.x = data->player.p_pos.x;
	dest.y = data->player.p_pos.y + 1;
	moves(data, dest);
}

int	move_left(t_data *data)
{
	t_axes	dest;

	player_finder(data);
	data->direction = 4;
	dest.x = data->player.p_pos.x - 1;
	dest.y = data->player.p_pos.y;
	moves(data, dest);
}

int	move_right(t_data *data)
{
	t_axes	dest;

	player_finder(data);
	data->direction = 6;
	dest.x = data->player.p_pos.x + 1;
	dest.y = data->player.p_pos.y;
	moves(data, dest);
}
