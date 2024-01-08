/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:14:21 by anporced          #+#    #+#             */
/*   Updated: 2024/01/08 13:05:55 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	merge_attack(t_img bg, t_img fg, t_data *data, t_axes i, int color)
// {
// 	t_axes	j;

// 	j.y = 0;
// 	while (j.y < bg.h)
// 	{
// 		j.x = 0;
// 		while (j.x < bg.w)
// 		{
// 			if (fg.addr
// 			[(j.y * fg.size_line) + (j.x * (fg.bpp / 8))] == 0xFFFFFF)
// 			{
// 				bg.addr[(j.y * bg.size_line) + (j.x * (bg.bpp / 8))]
// 					= color >> 16 & 0xFF;
// 				bg.addr[(j.y * bg.size_line) + (j.x * (bg.bpp / 8) + 1)]
// 					= color >> 8 & 0xFF;
// 				bg.addr[(j.y * bg.size_line) + (j.x * (bg.bpp / 8) + 2)]
// 					= color >> 0xFF;
// 			}
// 			j.x++;
// 		}
// 		j.y++;
// 	}
// 	print_img(data, bg.img, i);
// 	mlx_destroy_image(data->mlx, bg.img);
// }

// void	overlay_attack(t_img fg, t_img bg, t_data *data, t_axes i)
// {
// 	t_img	back;

// 	back.img = mlx_xpm_file_to_image(data->mlx, bg.path, &back.w, &back.h);
// 	fg.addr = mlx_get_data_addr(fg.img, &fg.bpp, &fg.size_line, &fg.endian);
// 	back.addr = mlx_get_data_addr(back.img, &back.bpp, &back.size_line,
// 			&back.endian);
// 	merge_img(back, fg, data, i);
// }
