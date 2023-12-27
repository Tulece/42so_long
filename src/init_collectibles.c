/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_collectibles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:45:49 by anporced          #+#    #+#             */
/*   Updated: 2023/12/27 20:35:40 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	malloc_collectibles(t_data *data)
{
	data->assets.collectibles = (t_img *)malloc(sizeof(t_img) * 8);
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

t_collectibles	*find_by_pos(t_data *data, t_axes pos)
{
	t_collectibles	*collec;

	collec = data->collectibles;
	while (collec)
	{
		if (collec->c_pos.x == pos.x && collec->c_pos.y == pos.y)
			return (collec);
		collec = collec->next;
	}
	return (NULL);
}
