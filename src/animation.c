/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:56:35 by anporced          #+#    #+#             */
/*   Updated: 2023/12/27 20:31:35 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	anime_player(t_data *data)
{
	overlay_img(data->assets.player
	[data->player.state][data->player.direction + data->frame],
		data->assets.textures[0], data, data->player.p_pos);
}

void	anime_ennemies(t_data *data)
{
	t_enemies	*enemies;

	enemies = data->enemies;
	while (enemies)
	{
		overlay_img(data->assets.enemies
		[enemies->state][enemies->direction + data->frame],
			data->assets.textures[0], data, enemies->z_pos);
		enemies = enemies->next;
	}
}

void	anime(t_data *data)
{
	if (data->clock != 1)
		data->clock++;
	else
	{
		data->clock = 0;
		if (data->frame == 1)
			data->frame = 0;
		else
			data->frame = 1;
	}
	anime_player(data);
	anime_ennemies(data);
}

void	evolve(t_data *data, t_axes dest_pos)
{
	t_collectibles	*collec;

	collec = find_by_pos(data, dest_pos);
	if (data->map.map[dest_pos.y][dest_pos.x] == 'C' && data->player.state < 8)
		data->player.state = collec->stone;
}
