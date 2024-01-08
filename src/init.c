/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:57:03 by anporced          #+#    #+#             */
/*   Updated: 2024/01/04 13:53:22 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	data_init(t_data *data)
{
	data->player.nb_p = 0;
	data->map.nb_z = 0;
	data->map.nb_c = 0;
	data->portal.nb_e = 0;
	data->portal.e_pos.y = 0;
	data->portal.e_pos.x = 0;
	data->player.step_count = 0;
	data->player.p_pos.x = 0;
	data->player.p_pos.y = 0;
	data->enemies->z_pos.y = 0;
	data->enemies->z_pos.x = 0;
	data->clock = 0;
	data->frame = 0;
	data->player.direction = 0;
	data->player.dest_pos.x = 0;
	data->player.dest_pos.y = 0;
	data->enemies->direction = 0;
	data->enemies->dest_pos.x = 0;
	data->enemies->dest_pos.y = 0;
	data->player.state = 0;
	data->enemies->state = 0;
	data->collectibles = NULL;
	data->enemies = NULL;
	data->player.got_c = 0;
	data->portal.anim_direction = 0;
}

char	*path_creator(char *pokemon, int i)
{
	char	*number;
	char	*str;
	char	*path;

	number = ft_itoa(i);
	str = ft_strjoin(pokemon, number);
	free(number);
	path = ft_strjoin(str, ".xpm");
	free(str);
	return (path);
}

void	full_init(t_data *data)
{
	data->portal.state = 0;
	init_evolis(data);
	init_enemies(data);
	init_textures(data);
	init_collectibles(data);
	init_portal(data);
	exit_finder(data);
	player_finder(data);
}
