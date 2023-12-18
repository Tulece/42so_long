/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:32:36 by anporced          #+#    #+#             */
/*   Updated: 2023/12/18 22:41:51 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_p_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_dim.y)
	{
		j = 0;
		while (j < data->map_dim.x)
		{
			if (data->map[i][j] == 'P')
			{
				data->p_pos.x = j;
				data->p_pos.y = i;
			}
			j++;
		}
		i++;
	}
}

void	move(t_data *data, t_axes new_pos)
{
	if (data->map[new_pos.y][new_pos.x] == '0')
		reload(data, new_pos);
	else if (data->map[new_pos.y][new_pos.x] == 'C')
	{
		data->nb_collec--;
		reload(data, new_pos);
	}
	else if (data->map[new_pos.y][new_pos.x] == 'E')
	{
		if (data->nb_collec == 0)
		{
			printf("Tu a gagné!\n");
			end(data);
		}
	}
	{
		printf("Tu es mort\n");
		end(data);
	}
}

int	hook_switch(int keycode, t_data *data)
{
	if (keycode == KEY_W)
	{
		move_up(data);
	}
	if (keycode == KEY_S)
	{
		move_down(data);
		printf("aaaaaaaaaaa\n");
	}
	if (keycode == KEY_A)
		move_left(data);
	if (keycode == KEY_D)
		move_right(data);
	if (keycode == KEY_ESC)
		end(data);
	return (0);
}

int	close_window(t_data *data)
{
	end(data);
	return (0);
}
