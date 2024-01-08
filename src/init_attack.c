/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_attack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:47:23 by anporced          #+#    #+#             */
/*   Updated: 2024/01/08 18:33:14 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	malloc_attack(t_data *data)
{
	data->assets.attack.img = (t_img *)malloc(sizeof(t_img));
}

void	init_attack(t_data *data)
{
	int		i;
	char	*str;
	int		w;
	int		h;

	i = 0;
	malloc_attack(data);
	str = "./textures/attack.xpm";
	data->assets.attack.img = mlx_xpm_file_to_image(data->mlx, str, &w, &h);
	data->assets.attack.path = str;
}
