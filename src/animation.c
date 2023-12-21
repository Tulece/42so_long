/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:56:35 by anporced          #+#    #+#             */
/*   Updated: 2023/12/21 14:58:07 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	anime(t_data *data)
{
	if (data->clock != 15)
		data->clock++;
	else
	{
		data->clock = 0;
		if (data->frame == 1)
			data->frame = 0;
		else
			data->frame = 1;
	}
	player_finder(data);
	overlay_img(data->assets.player[data->player.state][data->direction + data->frame], data->assets.textures[0], data, data->p_pos);
}
