/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stepcount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:40:22 by anporced          #+#    #+#             */
/*   Updated: 2024/02/06 21:14:08 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_step_count(t_data *data)
{
	char	*str;
	char	*count_str;

	count_str = ft_itoa(data->player.step_count);
	str = ft_strjoin("step_count = ", count_str);
	free(count_str);
	mlx_put_image_to_window
		(data->mlx, data->win, data->assets.textures[1].img, 64, 0);
	mlx_string_put(data->mlx, data->win, 15, 15, 2147483647, str);
	free(str);
}
