/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:51:36 by anporced          #+#    #+#             */
/*   Updated: 2024/01/04 16:54:38 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize_random(void)
{
	srand(time(NULL));
}

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

int	z_is_walkable(char c, t_data *data)
{
	if (c == '0' || c == 'P')
	{
		if (c == 'P' && data->player.state != 0)
			return (0);
		return (1);
	}
	return (0);
}
