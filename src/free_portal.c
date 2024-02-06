/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_portal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:33:09 by anporced          #+#    #+#             */
/*   Updated: 2024/02/06 21:14:59 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_portal(t_data *data)
{
	free(data->assets.portal);
}

void	destroy_portal(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		mlx_destroy_image(data->mlx, data->assets.portal[i].img);
		free(data->assets.portal[i].path);
		i++;
	}
	free_portal(data);
}
