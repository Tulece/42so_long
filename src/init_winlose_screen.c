/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_winlose_screen.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:33:12 by anporced          #+#    #+#             */
/*   Updated: 2024/01/24 15:03:08 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	malloc_winlose_screen(t_data *data)
{
	data->assets.win = (t_img *)malloc(sizeof(t_img));
	data->assets.lose = (t_img *)malloc(sizeof(t_img));
}

void	init_winlose_screen(t_data *data)
{
	char	*win_path;
	char	*lose_path;
	int		w;
	int		h;

	malloc_winlose_screen(data);
	win_path = WIN;
	lose_path = LOSE;
	data->assets.win->img = mlx_xpm_file_to_image(data->mlx, win_path, &w, &h);
	data->assets.win->path = win_path;
	data->assets.lose->img = mlx_xpm_file_to_image(data->mlx, lose_path,
			&w, &h);
	data->assets.lose->path = lose_path;
}
