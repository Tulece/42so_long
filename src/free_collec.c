/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_collec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:21:12 by anporced          #+#    #+#             */
/*   Updated: 2024/02/06 20:28:58 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_collectibles(t_data *data)
{
	free(data->assets.collectibles);
}

void	destroy_collectibles(t_data *data)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		mlx_destroy_image(data->mlx, data->assets.collectibles[i].img);
		free(data->assets.collectibles[i].path);
		i++;
	}
	free_collectibles(data);
}

void	collec_clear(t_collectibles *collectible)
{
	t_collectibles	*current;
	t_collectibles	*next;

	current = collectible;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
