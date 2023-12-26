/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_collectibles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:45:49 by anporced          #+#    #+#             */
/*   Updated: 2023/12/22 11:51:00 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	malloc_collectibles(t_data *data)
{
	data->assets.collectibles = (t_img *)malloc(sizeof(t_img) * 7);
}

char	*init_collectibles_path(t_data *data)
{
	char	*collectibles_paths;

	collectibles_paths = ft_strdup(collectible_);
	return (collectibles_paths);
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
		str = path_creator(collectible_, i);
		data->assets.collectibles[i].img = mlx_xpm_file_to_image(data->mlx,
				str, &w, &h);
		data->assets.collectibles[i].path = str;
		i++;
	}
}
