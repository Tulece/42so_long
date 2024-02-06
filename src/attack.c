/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:14:21 by anporced          #+#    #+#             */
/*   Updated: 2024/01/26 17:01:48 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	merge_attack(t_img bg, t_data *data, int color, t_axes i)
{
	t_axes	j;
	t_img	fg;

	j.y = -1;
	fg = data->assets.attack;
	fg.addr = mlx_get_data_addr(fg.img, &fg.bpp, &fg.size_line, &fg.endian);
	while (++j.y < bg.h)
	{
		j.x = -1;
		while (++j.x < bg.w)
		{
			if (fg.addr[(j.y * fg.size_line) + (j.x * (fg.bpp / 8))]
				== (int)0xFFFFFFFF)
			{
				bg.addr[(j.y * bg.size_line) + (j.x * (bg.bpp / 8))]
					= color & 0xFF;
				bg.addr[(j.y * bg.size_line) + (j.x * (bg.bpp / 8) + 1)]
					= color >> 8 & 0xFF;
				bg.addr[(j.y * bg.size_line) + (j.x * (bg.bpp / 8) + 2)]
					= color >> 16 & 0xFF;
			}
		}
	}
	print_img(data, bg.img, i);
	mlx_destroy_image(data->mlx, bg.img);
}

void	overlay_attack(t_data *data, t_axes i, unsigned int color)
{
	t_img	back;

	back.img = mlx_xpm_file_to_image(data->mlx,
			data->assets.textures[0].path, &back.w, &back.h);
	back.addr = mlx_get_data_addr(back.img, &back.bpp, &back.size_line,
			&back.endian);
	merge_attack(back, data, color, i);
}

void	attack(t_data *data)
{
	t_axes		attack_pos;
	t_enemies	*enemy_hit;

	attack_pos = find_dir(data->player.p_pos, data->player.direction);
	if (data->map.map[attack_pos.y][attack_pos.x] != '0')
		return ;
	display_attack(data);
	mlx_do_sync(data->mlx);
	usleep(50000);
	enemy_hit = z_find_by_pos(data, attack_pos);
	if (enemy_hit != NULL)
	{
		print_img(data, data->assets.textures[0].img, attack_pos);
		delete_enemy_by_pos(data, attack_pos);
	}
	print_img(data, data->assets.textures[0].img, attack_pos);
}
