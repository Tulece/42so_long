/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:44:54 by anporced          #+#    #+#             */
/*   Updated: 2023/12/22 12:29:52 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_args(int argc, char **argv)
{
	if (argc != 2)
		return (printf("non"));
	return (0);
}

static int	nb_char(t_data *data, char c)
{
	t_axes	i;
	int		count;

	i.y = 0;
	count = 0;
	while (i.y < data->map.map_dim.y)
	{
		i.x = 0;
		while (i.x < data->map.map_dim.x)
		{
			if (data->map.map[i.y][i.x] == c)
				count++;
			i.x++;
		}
		i.y++;
	}
	return (count);
}

int main(int argc, char **argv)
{
	t_data	data;
	t_axes	i;

	if (check_args(argc, argv)!= 0)
		return (0);
	i.x = 0;
	data.map.map_path = argv[1];
	data.mlx = mlx_init();
	if (!data.mlx)
		return (0);
	data.map.map = str_to_tab(file_to_str(&data));
	data.map.map_dim = map_size(&data);
	data.win = mlx_new_window(data.mlx, data.map.map_dim.x * TILE_SIZE, data.map.map_dim.y * TILE_SIZE , "so_long");
	if (!data.win)
		return (0);
	data_init(&data);
	init_evolis(&data);
	init_enemies(&data);
	init_textures(&data);
	init_collectibles(&data);
	init_portal(&data);
	display_map(&data);
	mlx_key_hook(data.win, hook_switch, &data);
	player_finder(&data);
	mlx_loop_hook(data.mlx, &anime, &data);
	mlx_loop(data.mlx);
}
