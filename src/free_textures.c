/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:38:51 by anporced          #+#    #+#             */
/*   Updated: 2024/02/06 20:49:27 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_textures(t_data *data)
{
	free(data->assets.textures);
}

void	destroy_textures(t_data *data)
{
	int		i;

	i = 0;
	while (i < 2)
	{
		mlx_destroy_image(data->mlx, data->assets.textures[i].img);
		free(data->assets.textures[i].path);
		i++;
	}
	free_textures(data);
}
