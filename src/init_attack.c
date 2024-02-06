/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_attack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:47:23 by anporced          #+#    #+#             */
/*   Updated: 2024/02/06 16:03:30 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_attack(t_data *data)
{
	int		w;
	int		h;

	data->assets.attack.img = mlx_xpm_file_to_image
		(data->mlx, "./textures/utils/attack.xpm", &w, &h);
	data->assets.attack.path = "./textures/utils/attack.xpm";
}
