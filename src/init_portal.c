/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_portal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:57:05 by anporced          #+#    #+#             */
/*   Updated: 2023/12/22 11:53:00 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	malloc_portal(t_data *data)
{
	data->assets.portal = (t_img *)malloc(sizeof(t_img) * 6);
}

char	*init_portal_path(t_data *data)
{
	char	*portal_paths;

	portal_paths = ft_strdup(portal_);
	return (portal_paths);
}

void	init_portal(t_data *data)
{
	int		i;
	char 	*str;
	int		w;
	int		h;

	i = 0;
	malloc_portal(data);
	while (i < 6)
	{
		str = path_creator(portal_, i);
		data->assets.portal[i].img = mlx_xpm_file_to_image(data->mlx, str, &w, &h);
		data->assets.portal[i].path = str;
		i++;
	}
}
