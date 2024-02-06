/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:27:27 by anporced          #+#    #+#             */
/*   Updated: 2024/01/18 17:43:26 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	malloc_textures(t_data *data)
{
	data->assets.textures = (t_img *)malloc(sizeof(t_img) * 2);
}

void	init_textures(t_data *data)
{
	int		i;
	char	*str;
	int		w;
	int		h;

	i = 0;
	malloc_textures(data);
	while (i < 2)
	{
		str = path_creator(GROUND, i);
		data->assets.textures[i].img = mlx_xpm_file_to_image
			(data->mlx, str, &w, &h);
		data->assets.textures[i].path = str;
		i++;
	}
}
