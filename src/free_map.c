/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:34:20 by anporced          #+#    #+#             */
/*   Updated: 2024/02/07 13:10:19 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_data *data)
{
	int	i;

	if (data->map.map_checker == NULL)
		return ;
	i = -1;
	while (++i < data->map.map_dim.y)
		free(data->map.map_checker[i]);
	free(data->map.map_checker);
}

void    free_true_map(t_data *data)
{
	int	i;

	i = -1;
 	while (++i < data->map.map_dim.y)
		free(data->map.map[i]);
	free(data->map.map);
}

