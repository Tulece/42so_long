/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_switch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <anporced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:24:01 by anporced          #+#    #+#             */
/*   Updated: 2023/12/11 19:58:39 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	quit(t_data *data)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		mlx_destroy_image(data->mlx, data->assets.evoli[i].img);
		i++;
	}
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	exit(0);
}

int	hook_switch(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
			quit(data);
	// if (keycode == KEY_W) // Touche W
	// {
	// 	data->player.y -= TILE_SIZE;
	// }
	// else if (keycode == KEY_A) // Touche A
	// {
	// 	data->player.x -= TILE_SIZE;
	// }
	// else if (keycode == KEY_S) // Touche S
	// {
	// 	data->player.y += TILE_SIZE;
	// }
	// else if (keycode == KEY_D) // Touche D
	// {
	// 	data->player.x += TILE_SIZE;
	// }
	// update_display(data);
	return (0);
}
