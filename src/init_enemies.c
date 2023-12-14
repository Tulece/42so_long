/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:18:17 by anporced          #+#    #+#             */
/*   Updated: 2023/12/14 22:31:24 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	malloc_enemies(t_data *data)
{
	data->assets.enemies = (t_img **)malloc(sizeof(t_img *) * 7);
	data->assets.enemies[0] = (t_img *)malloc(sizeof(t_img) * 8);
	data->assets.enemies[1] = (t_img *)malloc(sizeof(t_img) * 8);
	data->assets.enemies[2] = (t_img *)malloc(sizeof(t_img) * 8);
	data->assets.enemies[3] = (t_img *)malloc(sizeof(t_img) * 8);
	data->assets.enemies[4] = (t_img *)malloc(sizeof(t_img) * 8);
	data->assets.enemies[5] = (t_img *)malloc(sizeof(t_img) * 8);
	data->assets.enemies[6] = (t_img *)malloc(sizeof(t_img) * 8);
}

char	**init_enemies_path(t_data *data)
{
	char	**enemies_paths;

	enemies_paths = malloc(sizeof( char *) * 8);
	enemies_paths[0] = ft_strdup(regice_);
	enemies_paths[1] = ft_strdup(hooh_);
	enemies_paths[2] = ft_strdup(groudon_);
	enemies_paths[3] = ft_strdup(giratina_);
	enemies_paths[4] = ft_strdup(kyogre_);
	enemies_paths[5] = ft_strdup(rayquaza_);
	enemies_paths[6] = ft_strdup(ectoplasma_);
	return (enemies_paths);
}

void	init_enemies(t_data *data)
{
	int		i;
	int		j;
	char 	*str;
	char	*pokemon;
	int		w;
	int		h;
	char 	**enemies_paths;

	i = 0;
	enemies_paths = init_enemies_path(data);
	while (i < 7)
	{
		j = 0;
		pokemon = enemies_paths[i];
		while (j < 8)
		{
			str = path_creator(pokemon, j);
			data->assets.enemies[i][j].img = mlx_xpm_file_to_image(data->mlx, str, &w, &h);
			data->assets.enemies[i][j].path = str;
			j++;
		}
		i++;
	}
}
