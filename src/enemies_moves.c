/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:14:54 by anporced          #+#    #+#             */
/*   Updated: 2024/01/08 13:14:00 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	enemies_moves(t_data *data, t_axes dest_pos, t_enemies *enemies)
{
	if (z_is_walkable(data->map.map[dest_pos.y][dest_pos.x], data))
	{
		print_img(data, data->assets.textures[0].img, enemies->z_pos);
		overlay_img(data->assets.enemies
		[enemies->state][enemies->direction],
			data->assets.textures[0], data, dest_pos);
		data->map.map[dest_pos.y][dest_pos.x] = 'Z';
		data->map.map[enemies->z_pos.y][enemies->z_pos.x] = '0';
		enemies->z_pos = dest_pos;
	}
	else
		overlay_img(data->assets.enemies
		[enemies->state][enemies->direction],
			data->assets.textures[0], data, enemies->z_pos);
}

int	z_move_up(t_data *data, t_enemies *enemies)
{
	t_axes	dest;

	enemies->direction = 2;
	dest.x = enemies->z_pos.x;
	dest.y = enemies->z_pos.y - 1;
	enemies_moves(data, dest, enemies);
}

int	z_move_down(t_data *data, t_enemies *enemies)
{
	t_axes	dest;

	enemies->direction = 0;
	dest.x = enemies->z_pos.x;
	dest.y = enemies->z_pos.y + 1;
	enemies_moves(data, dest, enemies);
}

int	z_move_left(t_data *data, t_enemies *enemies)
{
	t_axes	dest;

	enemies->direction = 4;
	dest.x = enemies->z_pos.x - 1;
	dest.y = enemies->z_pos.y;
	enemies_moves(data, dest, enemies);
}

int	z_move_right(t_data *data, t_enemies *enemies)
{
	t_axes	dest;

	enemies->direction = 6;
	dest.x = enemies->z_pos.x + 1;
	dest.y = enemies->z_pos.y;
	enemies_moves(data, dest, enemies);
}
