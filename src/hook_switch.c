/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_switch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:24:01 by anporced          #+#    #+#             */
/*   Updated: 2023/12/20 17:07:28 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	quit(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	exit(0);
}

int	hook_switch(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
			quit(data);
	if (keycode == KEY_W)
	{
		move_up(data);
		data->direction = 0 + data->frame;
	}
	else if (keycode == KEY_A)
	{
		move_left(data);
		data->direction = 2 + data->frame;
	}
	else if (keycode == KEY_S)
	{
		move_down(data);
		data->direction = 4 + data->frame;
	}
	else if (keycode == KEY_D)
	{
		move_right(data);
		data->direction = 6 + data->frame;
	}
	return (0);
}
