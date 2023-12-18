/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:39:44 by anporced          #+#    #+#             */
/*   Updated: 2023/12/18 22:44:03 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	reload(t_data *data, t_axes new_pos)
{
	data->map[new_pos.y][new_pos.x] = 'P';
	data->map[data->p_pos.y][data->p_pos.x] = '0';
	print_img(data, data->assets.textures[0].img, data->p_pos);
	overlay_img(data->assets.player[0][0], data->assets.textures[0], data, new_pos);
	// data->count += 1;
	// ft_printf("move nb = %d\n", data->count);
	// display_moves(data);
	// if (data->count % 1 == 0)
	// 	enemies_move(data);
}

void	move_up(t_data *data)
{
	t_axes	new_pos;

	find_p_pos(data);
	printf("aaaaaaaaaaaaaaa\n");
	new_pos.y = data->p_pos.y - 1;
	new_pos.x = data->p_pos.x;
	if (0 <= new_pos.y && new_pos.y < data->map_dim.y)
	{
		move(data, new_pos);
	}
}

void	move_down(t_data *data)
{
	t_axes	new_pos;

	find_p_pos(data);
	new_pos.y = data->p_pos.y + 1;
	new_pos.x = data->p_pos.x;
	if (0 <= new_pos.y && new_pos.y < data->map_dim.y)
	{
		move(data, new_pos);
	}
}

void	move_left(t_data *data)
{
	t_axes	new_pos;

	find_p_pos(data);
	new_pos.y = data->p_pos.y;
	new_pos.x = data->p_pos.x - 1;
	if (0 <= new_pos.x && new_pos.x < data->map_dim.x)
	{
		move(data, new_pos);
	}
}

void	move_right(t_data *data)
{
	t_axes	new_pos;

	find_p_pos(data);
	new_pos.y = data->p_pos.y;
	new_pos.x = data->p_pos.x + 1;
	if (0 <= new_pos.x && new_pos.x < data->map_dim.x)
	{
		move(data, new_pos);
	}
}
