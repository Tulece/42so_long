/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_collectibles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:45:49 by anporced          #+#    #+#             */
/*   Updated: 2024/02/06 20:31:32 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	malloc_collectibles(t_data *data)
{
	data->assets.collectibles = (t_img *)malloc(sizeof(t_img) * 8);
}

void	init_collectibles(t_data *data)
{
	int		i;
	char	*str;
	int		w;
	int		h;

	i = 0;
	malloc_collectibles(data);
	while (i < 8)
	{
		str = path_creator(COLLECTIBLE, i);
		data->assets.collectibles[i].img = mlx_xpm_file_to_image(data->mlx,
				str, &w, &h);
		data->assets.collectibles[i].path = str;
		i++;
	}
}
