/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:30:29 by anporced          #+#    #+#             */
/*   Updated: 2023/12/18 21:41:01 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	nb_char(t_data *data, char c)
{
	t_axes	i;
	int		count;

	i.y = 0;
	count = 0;
	while (i.y < data->map_dim.y)
	{
		i.x = 0;
		while (i.x < data->map_dim.x)
		{
			if (data->map[i.y][i.x] == c)
				count++;
			i.x++;
		}
		i.y++;
	}
	return (count);
}

void	destroy(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_image(data->mlx, data->assets.textures[0].img);
	mlx_destroy_image(data->mlx, data->assets.textures[1].img);

	while (i < 8)
	{
		mlx_destroy_image(data->mlx, data->assets.collectibles[i].img);
		mlx_destroy_image(data->mlx, data->assets.portal[i].img);
		mlx_destroy_image(data->mlx, data->assets.player[0][i].img);
		mlx_destroy_image(data->mlx, data->assets.player[1][i].img);
		mlx_destroy_image(data->mlx, data->assets.player[2][i].img);
		mlx_destroy_image(data->mlx, data->assets.player[3][i].img);
		mlx_destroy_image(data->mlx, data->assets.player[4][i].img);
		mlx_destroy_image(data->mlx, data->assets.player[5][i].img);
		mlx_destroy_image(data->mlx, data->assets.player[6][i].img);
		mlx_destroy_image(data->mlx, data->assets.player[7][i].img);
		i++;
	}
	free(data->assets.player);
	free(data->assets.enemies);
	free(data->assets.collectibles);
	free(data->assets.textures);
	free(data->assets.portal);
}

void	end(t_data *data)
{
	int		i;

	i = 0;
	if (data->map != NULL)
	{
		while (data->map[i] != NULL)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	free(data->c_pos);
	free(data->z_pos);
	destroy(data);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}
