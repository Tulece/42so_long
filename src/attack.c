/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:14:21 by anporced          #+#    #+#             */
/*   Updated: 2024/01/08 21:43:21 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	merge_attack(t_img bg, t_img fg, t_data *data, int color, t_axes i)
{
	t_axes	j;

	j.y = 0;
	while (j.y < bg.h)
	{
		j.x = 0;
		while (j.x < bg.w)
		{
			if (fg.addr
			[(j.y * fg.size_line) + (j.x * (fg.bpp / 8))] == 0xFFFFFF)
			{
				bg.addr[(j.y * bg.size_line) + (j.x * (bg.bpp / 8))]
					= color >> 16 & 0xFF;
				bg.addr[(j.y * bg.size_line) + (j.x * (bg.bpp / 8) + 1)]
					= color >> 8 & 0xFF;
				bg.addr[(j.y * bg.size_line) + (j.x * (bg.bpp / 8) + 2)]
					= color >> 0xFF;
			}
			j.x++;
		}
		j.y++;
	}
	print_img(data, bg.img, i);
	mlx_destroy_image(data->mlx, bg.img);
}

void	overlay_attack(t_img fg, t_data *data, t_axes i, int color)
{
	t_img	back;

	back.img = mlx_xpm_file_to_image(data->mlx, data->assets.textures[0].path, &back.w, &back.h);
	fg.addr = mlx_get_data_addr(fg.img, &fg.bpp, &fg.size_line, &fg.endian);
	back.addr = mlx_get_data_addr(back.img, &back.bpp, &back.size_line,
			&back.endian);
	merge_attack(back, fg, data, color, i);
}

t_axes	find_dir(t_data *data, t_axes pos, int dir)
{
	if (dir == 0)
		pos.y++;
	else if (dir == 2)
		pos.y--;
	else if (dir == 4)
		pos.x--;
	else if (dir == 6)
		pos.x++;
	return (pos);
}

int	get_color(int state)
{
	int	color;

	color = 0;
	if (state == 1)
		color = RED;
	else if (state == 2)
		color = BLUE;
	else if (state == 3)
		color = YELLOW;
	else if (state == 4)
		color = BLACK;
	else if (state == 5)
		color = PURPLE;
	else if (state == 6)
		color = ICE_BLUE;
	else if (state == 7)
		color = GREEN;
	return (color);
}

void	attack(t_data *data)
{
	// overlay_img(data->assets.attack, data->assets.textures[0], data, find_dir(data, data->player.p_pos, data->player.direction));
	overlay_attack(data->assets.attack, data, find_dir(data, data->player.p_pos, data->player.direction), get_color(data->player.state));
}
