/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:15:20 by anporced          #+#    #+#             */
/*   Updated: 2023/12/14 22:59:51 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_img(t_data *data, void *img, t_axes i)
{
	mlx_put_image_to_window(data->mlx, data->win, img, i.x * TILE_SIZE, i.y * TILE_SIZE);
}

void	merge_img(t_img bg, t_img fg, t_data *data, t_axes i)
{
	t_axes	j;

	j.y = 0;
	while (j.y < bg.h)
	{
		j.x = 0;
		while (j.x < bg.w)
		{
			if (fg.addr[(j.y * fg.size_line) + (j.x * (fg.bpp / 8))] != 0)
			{
				bg.addr[(j.y * bg.size_line) + (j.x * (bg.bpp / 8))]
					= fg.addr[(j.y * fg.size_line) + (j.x * (fg.bpp / 8))];
				bg.addr[(j.y * bg.size_line) + (j.x * (bg.bpp / 8) + 1)]
					= fg.addr[(j.y * fg.size_line) + (j.x * (fg.bpp / 8) + 1)];
				bg.addr[(j.y * bg.size_line) + (j.x * (bg.bpp / 8) + 2)]
					= fg.addr[(j.y * fg.size_line) + (j.x * (fg.bpp / 8) + 2)];

			}
			j.x++;
		}
		j.y++;
	}
	print_img(data, bg.img, i);
	//print_img(data, data->assets.textures[i.x][i.y].img, i);
	mlx_destroy_image(data->mlx, bg.img);
}

void	overlay_img(t_img fg, t_img bg, t_data *data, t_axes i)
{
	t_img	back;

	back.img = mlx_xpm_file_to_image(data->mlx, bg.path, &back.w, &back.h);
	fg.addr = mlx_get_data_addr(fg.img, &fg.bpp, &fg.size_line, &fg.endian);
	back.addr = mlx_get_data_addr(back.img, &back.bpp, &back.size_line,
			&back.endian);
	merge_img(back, fg, data, i);
}

void	display_map(t_data *data)
{
	t_axes	i;
	int		k;
	int		l;
	l = 0;
	k = 0;
	i.y = 0;
	while (i.y < data->map_dim.y)
	{
		i.x = 0;
		while (i.x < data->map_dim.x)
		{
			if (k == 7)
				k = 0;
			if (l == 7)
				l = 0;
			if (data->map[i.y][i.x] == '1')
				print_img(data, data->assets.textures[1][0].img, i);
			else if (data->map[i.y][i.x] == '0')
				print_img(data, data->assets.textures[0][1].img, i);
			else if (data->map[i.y][i.x] == 'P')
				//print_img(data, data->assets.player[0][0].img , i);
				overlay_img(data->assets.player[k][l], data->assets.textures[0][1], data, i);
			// else if (data->map[i.y][i.x] == 'E')
			// 	print_img(data, data->text.portal[0], i);
			// else if (data->map[i.y][i.x] == 'C')
			// 	overlay_img(data->text.diamond, data->assets.textures[i.x][i.y].img, data, i);
			else if (data->map[i.y][i.x] == 'Z')
				overlay_img(data->assets.enemies[k][l], data->assets.textures[0][1], data, i);
			i.x++;
			k++;
		}
		i.y++;
		l++;
	}
}
