/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:16:20 by anporced          #+#    #+#             */
/*   Updated: 2023/12/11 15:06:10 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// int	main(void)
// {
// 	t_data data;

// 	data.mlx = mlx_init();

// 	data.win = mlx_new_window(data.mlx, 640, 640, "My Window");
// 	init_textures(&data);

// 	int i = 0;
// 	int j = 0;
// 	while (i < 10)
// 	{
// 		j = 0;
// 		while (j < 10)
// 		{
// 			mlx_put_image_to_window(data.mlx, data.win, data.assets->grass->img, i * 64, j * 64);
// 			j++;
// 		}
// 		i++;
// 	}
// 	mlx_put_image_to_window(data.mlx, data.win, data.assets->evoli->img, 250, 250);
// 	mlx_put_image_to_window(data.mlx, data.win, data.assets->groudon->img, 200, 200);

// 	mlx_key_hook(data.win, hook_switch, &data);

// 	mlx_loop(data.mlx);

// 	return (0);
// }
