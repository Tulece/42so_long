/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:18:17 by anporced          #+#    #+#             */
/*   Updated: 2023/12/22 11:48:46 by anporced         ###   ########.fr       */
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
	enemies_paths[0] = ft_strdup(PATH_REGICE);
	enemies_paths[1] = ft_strdup(PATH_HOOH);
	enemies_paths[2] = ft_strdup(PATH_GROUDON);
	enemies_paths[3] = ft_strdup(PATH_KYOGRE);
	enemies_paths[4] = ft_strdup(PATH_ECTOPLASMA);
	enemies_paths[5] = ft_strdup(PATH_RAYQUAZA);
	enemies_paths[6] = ft_strdup(PATH_GIRATINA);
	return (enemies_paths);
}

void	init_enemies(t_data *data)
{
	int		i;
	int		j;
	char 	*str;
	char	*pokemon;
	char 	**enemies_paths;

	i = 0;
	malloc_enemies(data);
	enemies_paths = init_enemies_path(data);
	while (i < 7)
	{
		j = 0;
		pokemon = enemies_paths[i];
		while (j < 8)
		{
			str = path_creator(pokemon, j);
			data->assets.enemies[i][j].img = mlx_xpm_file_to_image(data->mlx,
					str, &(int){0}, &(int){0});
			data->assets.enemies[i][j].path = str;
			j++;
		}
		i++;
	}
}
