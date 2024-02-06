/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:56:35 by anporced          #+#    #+#             */
/*   Updated: 2024/01/29 20:08:36 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	anime_player(t_data *data)
{
	t_axes	dest_pos;

	dest_pos = data->player.p_pos;
	if (data->player_glow)
	{
		overlay_img(data->assets.evolutions[data->player.direction / 2],
			data->assets.textures[0], data, dest_pos);
		data->player_glow = 0;
		printf("a\n");
	}
	else
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

void	anime_exit(t_data *data)
{
	if (data->player.got_c == data->map.nb_c)
	{
		if (data->portal.state < 6 && data->portal.anim_direction == 0)
		{
			data->portal.state++;
			if (data->portal.state == 5)
				data->portal.anim_direction = 1;
		}
		else if (data->portal.state >= 0 && data->portal.anim_direction == 1)
		{
			data->portal.state--;
			if (data->portal.state == 0)
				data->portal.anim_direction = 0;
		}
	}
	overlay_img(data->assets.portal[data->portal.state],
		data->assets.textures[0], data, data->portal.e_pos);
}

int	anime(t_data *data)
{
	enemies_clock(data);
	if (data->clock == 1)
	{
		data->clock = 0;
		if (data->frame == 1)
			data->frame = 0;
		else
			data->frame = 1;
	}
	else
		data->clock++;
	anime_player(data);
	anime_ennemies(data);
	anime_exit(data);
	mlx_do_sync(data->mlx);
	usleep(70000);
	return (0);
}

void	evolve(t_data *data, t_axes dest_pos)
{
	t_collectibles	*collec;

	collec = find_by_pos(data, dest_pos);
	if (data->map.map[dest_pos.y][dest_pos.x] == 'C' && data->player.state < 8)
	{
		data->player.got_c++;
		data->player.state = collec->stone;
		data->map.map[dest_pos.y][dest_pos.x] = '0';
		overlay_img(data->assets.evolutions[data->player.direction / 2],
			data->assets.textures[0], data, dest_pos);
		mlx_do_sync(data->mlx);
		usleep(27000);
	}
}
