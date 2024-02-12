/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:53:00 by anporced          #+#    #+#             */
/*   Updated: 2024/02/12 13:14:06 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	quit_early(t_data *data)
{
	if (data->map.map_checker)
		free_map(data);
	if (data->map.map)
		free_true_map(data);
	enemies_clear(data->enemies);
	collec_clear(data->collectibles);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	cross_quit(t_data *data)
{
	destroy_evolis(data);
	destroy_attack(data);
	destroy_collectibles(data);
	destroy_evolutions(data);
	destroy_textures(data);
	destroy_enemies(data);
	destroy_portal(data);
	destroy_winlose_screen(data);
	enemies_clear(data->enemies);
	collec_clear(data->collectibles);
	free_map(data);
	free_true_map(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

void	quit(t_data *data)
{
	destroy_evolis(data);
	destroy_attack(data);
	destroy_collectibles(data);
	destroy_evolutions(data);
	destroy_textures(data);
	destroy_enemies(data);
	destroy_portal(data);
	destroy_winlose_screen(data);
	enemies_clear(data->enemies);
	collec_clear(data->collectibles);
	free_map(data);
	free_true_map(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

void	success_game(t_data *data)
{
	if (data->player.p_pos.y == data->portal.e_pos.y
		&& data->player.p_pos.x == data->portal.e_pos.x
		&& data->player.got_c == data->map.nb_c)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->assets.win->img,
			data->map.map_dim.x * TILE_SIZE / 2 - 720 / 2,
			data->map.map_dim.y * TILE_SIZE / 2 - 360 / 2);
		mlx_do_sync(data->mlx);
		usleep(5000000);
		quit(data);
	}
}

void	lose_game(t_data *data)
{
	if (z_find_by_pos(data, data->player.p_pos) && data->player.state == 0)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->assets.lose->img,
			data->map.map_dim.x * TILE_SIZE / 2 - 728 / 2,
			data->map.map_dim.y * TILE_SIZE / 2 - 504 / 2);
		mlx_do_sync(data->mlx);
		usleep(5000000);
		quit(data);
	}
}
