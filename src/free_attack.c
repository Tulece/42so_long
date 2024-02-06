/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_attack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:36:24 by anporced          #+#    #+#             */
/*   Updated: 2024/02/06 20:32:15 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_attack(t_data *data)
{
	mlx_destroy_image(data->mlx, data->assets.attack.img);
}
