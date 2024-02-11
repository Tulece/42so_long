/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:44:54 by anporced          #+#    #+#             */
/*   Updated: 2024/02/11 18:03:34 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_args(int ac, char **av)
{
	int	len;

	len = ft_strlen(av[1]);
	if (ac != 2)
		return (ft_printf("Add a map from /map folder to play.\n"));
	if (av[1][len - 3] != '.' && av[1][len - 2] != 'b'
		&& av[1][len - 1] != 'e' && av[1][len] != 'r')
		return (ft_printf("The map has to be a .ber file and must exist to \
play.\n"));
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (check_args(ac, av) != 0)
		return (0);
	data.map.map_path = av[1];
	data.mlx = mlx_init();
	if (!data.mlx)
		return (0);
	data_init(&data);
	check_map(&data);
	full_init(&data);
	data.win = mlx_new_window(data.mlx, data.map.map_dim.x * TILE_SIZE, \
		data.map.map_dim.y * TILE_SIZE, "so_long");
	if (!data.win)
		return (0);
	display_map(&data);
	mlx_key_hook(data.win, hook_switch, &data);
	mlx_loop_hook(data.mlx, &anime, &data);
	mlx_loop(data.mlx);
}
