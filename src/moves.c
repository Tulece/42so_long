/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:32:03 by anporced          #+#    #+#             */
/*   Updated: 2024/01/29 17:15:19 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	moves(t_data *data, t_axes dest_pos)
{
	evolve(data, dest_pos);
	if (is_walkable(dest_pos, data))
	{
		print_img(data, data->assets.textures[0].img, data->player.p_pos);
		overlay_img(data->assets.player
		[data->player.state][data->player.direction],
			data->assets.textures[0], data, dest_pos);
		data->map.map[data->player.p_pos.y][data->player.p_pos.x] = '0';
		data->player.step_count++;
		display_step_count(data);
		data->player.p_pos = dest_pos;
		if (data->map.map[dest_pos.y][dest_pos.x] == 'C')
		{
			data->player_glow = 1;
			delete_collec_by_pos(data, dest_pos);
		}
	}
	else
		overlay_img(data->assets.player
		[data->player.state][data->player.direction],
			data->assets.textures[0], data, data->player.p_pos);
	success_game(data);
}

void	move_up(t_data *data)
{
	t_axes	dest;

	dest.x = data->player.p_pos.x;
	dest.y = data->player.p_pos.y - 1;
	if (data->player.direction != 2)
		turn(data, data->player.p_pos, 2);
	else
	{
		data->player.direction = 2;
		moves(data, dest);
	}
}

void	move_down(t_data *data)
{
	t_axes	dest;

	dest.x = data->player.p_pos.x;
	dest.y = data->player.p_pos.y + 1;
	if (data->player.direction != 0)
		turn(data, data->player.p_pos, 0);
	else
	{
		data->player.direction = 0;
		moves(data, dest);
	}
}

void	move_left(t_data *data)
{
	t_axes	dest;

	dest.x = data->player.p_pos.x - 1;
	dest.y = data->player.p_pos.y;
	if (data->player.direction != 4)
		turn(data, data->player.p_pos, 4);
	else
	{
		data->player.direction = 4;
		moves(data, dest);
	}
}

void	move_right(t_data *data)
{
	t_axes	dest;

	dest.x = data->player.p_pos.x + 1;
	dest.y = data->player.p_pos.y;
	if (data->player.direction != 6)
		turn(data, data->player.p_pos, 6);
	else
	{
		data->player.direction = 6;
		moves(data, dest);
	}
}
