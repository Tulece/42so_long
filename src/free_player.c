/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:39:42 by anporced          #+#    #+#             */
/*   Updated: 2024/02/06 20:32:45 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_evolis(t_data *data)
{
	free(data->assets.player[0]);
	free(data->assets.player[1]);
	free(data->assets.player[2]);
	free(data->assets.player[3]);
	free(data->assets.player[4]);
	free(data->assets.player[5]);
	free(data->assets.player[6]);
	free(data->assets.player[7]);
	free(data->assets.player);
}

void	free_evolis_path(char **evopaths)
{
	free(evopaths[0]);
	free(evopaths[1]);
	free(evopaths[2]);
	free(evopaths[3]);
	free(evopaths[4]);
	free(evopaths[5]);
	free(evopaths[6]);
	free(evopaths[7]);
	free(evopaths);
}

void	destroy_evolis(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			mlx_destroy_image(data->mlx, data->assets.player[i][j].img);
			free(data->assets.player[i][j].path);
			j++;
		}
		i++;
	}
	free_evolis(data);
}
