/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:29:38 by anporced          #+#    #+#             */
/*   Updated: 2024/02/06 20:32:33 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_enemies(t_data *data)
{
	free(data->assets.enemies[0]);
	free(data->assets.enemies[1]);
	free(data->assets.enemies[2]);
	free(data->assets.enemies[3]);
	free(data->assets.enemies[4]);
	free(data->assets.enemies[5]);
	free(data->assets.enemies[6]);
	free(data->assets.enemies);
}

void	free_enemies_path(char **enemies_path)
{
	free(enemies_path[0]);
	free(enemies_path[1]);
	free(enemies_path[2]);
	free(enemies_path[3]);
	free(enemies_path[4]);
	free(enemies_path[5]);
	free(enemies_path[6]);
	free(enemies_path);
}

void	destroy_enemies(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < 7)
	{
		j = 0;
		while (j < 8)
		{
			mlx_destroy_image(data->mlx, data->assets.enemies[i][j].img);
			free(data->assets.enemies[i][j].path);
			j++;
		}
		i++;
	}
	free_enemies(data);
}

void	enemies_clear(t_enemies *enemies)
{
	t_enemies	*current;
	t_enemies	*next;

	current = enemies;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
