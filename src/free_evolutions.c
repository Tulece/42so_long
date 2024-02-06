/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_evolutions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:35:43 by anporced          #+#    #+#             */
/*   Updated: 2024/02/06 20:38:12 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_evolutions(t_data *data)
{
	free(data->assets.evolutions);
}

void	destroy_evolutions(t_data *data)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(data->mlx, data->assets.evolutions[i].img);
		free(data->assets.evolutions[i].path);
		i++;
	}
	free_evolutions(data);
}
