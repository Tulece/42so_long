/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_winlose.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:39:07 by anporced          #+#    #+#             */
/*   Updated: 2024/02/06 20:46:54 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_winlose_screen(t_data *data)
{
	free(data->assets.win);
	free(data->assets.lose);
}

void	destroy_winlose_screen(t_data *data)
{
	mlx_destroy_image(data->mlx, data->assets.win->img);
	free(data->assets.win->path);
	mlx_destroy_image(data->mlx, data->assets.lose->img);
	free(data->assets.lose->path);
	free_winlose_screen(data);
}
