/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:08:14 by anporced          #+#    #+#             */
/*   Updated: 2024/01/18 17:45:03 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	malloc_evolutions(t_data *data)
{
	data->assets.evolutions = (t_img *)malloc(sizeof(t_img) * 4);
}

void	init_evolutions(t_data *data)
{
	int		i;
	char	*str;
	int		w;
	int		h;

	i = 0;
	malloc_evolutions(data);
	while (i < 4)
	{
		str = path_creator(EVOLUTIONS, i);
		data->assets.evolutions[i].img = mlx_xpm_file_to_image
			(data->mlx, str, &w, &h);
		data->assets.evolutions[i].path = str;
		i++;
	}
}
