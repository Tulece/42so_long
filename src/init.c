/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:57:03 by anporced          #+#    #+#             */
/*   Updated: 2023/12/18 23:01:13 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	data_init(t_data *data)
{
	data->win = NULL;
	data->map = NULL;
	data->map_dim.x = 0;
	data->map_dim.y = 0;
	data->nb_collec = 0;
	data->count = 0;
	data->p_pos.x = 0;
	data->p_pos.y = 0;
	data->c_pos = NULL;
	data->z_pos = NULL;
	data->clock = 0;
}

void	data_init2(t_data *data)
{
	data->nb_collec = nb_char(data, 'C');
	data->nb_enemies = nb_char(data, 'Z');
	data->assets.portal = malloc(sizeof(t_img) * 6);
	data->c_pos = malloc(sizeof(t_axes) * data->nb_collec);
	data->z_pos = malloc(sizeof(t_axes) * data->nb_enemies);
}
