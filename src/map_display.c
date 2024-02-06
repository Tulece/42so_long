/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:21:20 by anporced          #+#    #+#             */
/*   Updated: 2024/01/09 20:29:44 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display01(t_data *data, t_axes i)
{
	if (data->map.map[i.y][i.x] == '1')
		print_img(data, data->assets.textures[1].img, i);
	else if (data->map.map[i.y][i.x] == '0')
		print_img(data, data->assets.textures[0].img, i);
}

void	display_pe(t_data *data)
{
	overlay_img(data->assets.player
	[data->player.state][data->player.direction],
		data->assets.textures[0], data, data->player.p_pos);
	overlay_img(data->assets.portal[0], data->assets.textures[0],
		data, data->portal.e_pos);
}

void	display_zc(t_data *data)
{
	t_collectibles	*actual_collec;
	t_enemies		*actual_enemie;

	actual_collec = data->collectibles;
	actual_enemie = data->enemies;
	while (actual_collec)
	{
		overlay_img(data->assets.collectibles[actual_collec->stone],
			data->assets.textures[0], data, actual_collec->c_pos);
		actual_collec = actual_collec->next;
	}
	while (actual_enemie)
	{
		overlay_img(data->assets.enemies[actual_enemie->state][0],
			data->assets.textures[0], data, actual_enemie->z_pos);
		actual_enemie = actual_enemie->next;
	}
}

void	display_map(t_data *data)
{
	t_axes	i;

	i.y = 0;
	while (i.y < data->map.map_dim.y)
	{
		i.x = 0;
		while (i.x < data->map.map_dim.x)
		{
			display01(data, i);
			i.x++;
		}
		i.y++;
	}
	display_pe(data);
	display_zc(data);
}
