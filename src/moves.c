// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   moves.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/12/19 11:59:49 by anporced          #+#    #+#             */
// /*   Updated: 2023/12/19 12:17:03 by anporced         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../includes/so_long.h"

void	player_finder(t_data *data)
{
	t_axes	i;
	i.y = 0;
	while (i.y < data->map_dim.y)
	{
		i.x = 0;
		while (i.x < data->map_dim.x)
		{
			if (data->map[i.y][i.x] == 'P')
				data->p_pos = i;
			i.x++;
		}
		i.y++;
	}
}

void	moves(t_data *data, t_axes dest_pos)
{
	print_img(data, data->assets.textures[0].img, data->p_pos);
	// printf("%d %d direction =\n", data->p_pos.y, data->p_pos.x, data->direction);
	overlay_img(data->assets.player[data->player.state][data->direction], data->assets.textures[0], data, dest_pos);
	data->map[dest_pos.y][dest_pos.x] = 'P';
	data->map[data->p_pos.y][data->p_pos.x] = '0';
}
int	move_up(t_data *data)
{
		t_axes		dest;

		player_finder(data);
		data->direction = 2;
		dest.x = data->p_pos.x;
		dest.y = data->p_pos.y - 1;
		moves(data, dest);
}

int	move_down(t_data *data)
{
		t_axes	dest;

		player_finder(data);
		data->direction = 0;
		dest.x = data->p_pos.x;
		dest.y = data->p_pos.y + 1;
		moves(data, dest);
}

int	move_left(t_data *data)
{
		t_axes dest;

		player_finder(data);
		data->direction = 4;
		dest.x = data->p_pos.x - 1;
		dest.y = data->p_pos.y;
		moves(data, dest);
}

int	move_right(t_data *data)
{
		t_axes dest;

		player_finder(data);
		data->direction = 6;
		dest.x = data->p_pos.x + 1;
		dest.y = data->p_pos.y;
		moves(data, dest);
}
