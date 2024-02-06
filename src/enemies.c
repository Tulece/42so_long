/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:51:36 by anporced          #+#    #+#             */
/*   Updated: 2024/01/26 20:22:47 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	generate_random_number(void)
{
	int	random_num;

	random_num = rand() % 4;
	return (random_num);
}

void	enemies_clock(t_data *data)
{
	if (data->z_clock == 20)
	{
		data->z_clock = 0;
		if (data->frame == 1)
			data->frame = 0;
		else
			data->frame = 1;
		enemies_switch(data);
	}
	else
		data->z_clock++;
}

int	z_is_walkable(char c, t_data *data, t_axes dest_pos)
{
	if ((dest_pos.x == data->player.p_pos.x
			&& dest_pos.y == data->player.p_pos.y) && data->player.state > 0)
		return (0);
	if (z_find_by_pos(data, dest_pos))
		return (0);
	if (c == '0' || (c == 'P' && data->player.state == 0))
		return (1);
	else
		return (0);
}

t_enemies	*z_find_by_pos(t_data *data, t_axes pos)
{
	t_enemies	*enemies;

	enemies = data->enemies;
	while (enemies)
	{
		if (enemies->z_pos.x == pos.x && enemies->z_pos.y == pos.y)
			return (enemies);
		enemies = enemies->next;
	}
	return (NULL);
}

void	delete_enemy_by_pos(t_data *data, t_axes pos)
{
	t_enemies	*current;
	t_enemies	*prev;

	current = data->enemies;
	prev = NULL;
	if (current != NULL && current->z_pos.x == pos.x
		&& current->z_pos.y == pos.y)
	{
		data->enemies = current->next;
		free(current);
		return ;
	}
	while (current != NULL && (current->z_pos.x != pos.x
			|| current->z_pos.y != pos.y))
	{
		prev = current;
		current = current->next;
	}
	if (current == NULL)
		return ;
	prev->next = current->next;
	free(current);
}
