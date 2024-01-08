/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_switch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:24:01 by anporced          #+#    #+#             */
/*   Updated: 2024/01/08 13:06:07 by anporced         ###   ########.fr       */
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
	// printf("%d\n", keycode);
	if (keycode == KEY_ESC)
		quit(data);
	if (keycode == KEY_W)
	{
		move_up(data);
		data->player.direction = INDEX_UP;
	}
	else if (keycode == KEY_A)
	{
		move_left(data);
		data->player.direction = INDEX_LEFT;
	}
	else if (keycode == KEY_S)
	{
		move_down(data);
		data->player.direction = INDEX_DOWN;
	}
	else if (keycode == KEY_D)
	{
		move_right(data);
		data->player.direction = INDEX_RIGHT;
	}
	return (0);
}

void	z_move(t_data *data, int random_num, t_enemies *enemies)
{
	if (random_num == 0)
	{
		z_move_up(data, enemies);
		enemies->direction = INDEX_UP;
	}
	else if (random_num == 1)
	{
		z_move_left(data, enemies);
		enemies->direction = INDEX_LEFT;
	}
	else if (random_num == 2)
	{
		z_move_down(data, enemies);
		enemies->direction = INDEX_DOWN;
	}
	else if (random_num == 3)
	{
		z_move_right(data, enemies);
		enemies->direction = INDEX_RIGHT;
	}
}

int	enemies_switch(t_data *data)
{
	t_enemies	*enemies;
	int			random_num;

	initialize_random();
	enemies = data->enemies;
	while (enemies)
	{
		random_num = generate_random_number();
		z_move(data, random_num, enemies);
		enemies = enemies->next;
	}
	return (0);
}
