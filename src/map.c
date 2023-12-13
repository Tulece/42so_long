/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:27:27 by anporced          #+#    #+#             */
/*   Updated: 2023/12/13 18:49:22 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	malloc_wallsngrounds(t_data *data)
{
	data->assets.wallsngrounds = (t_img **)malloc(sizeof(t_img *) * 2);
	data->assets.wallsngrounds[0] = (t_img *)malloc(sizeof(t_img) * 2);
	data->assets.wallsngrounds[1] = (t_img *)malloc(sizeof(t_img) * 2);
}

char	**init_wallsngrounds_path(t_data *data)
{
	char	**wallsngrounds;

	wallsngrounds = malloc(sizeof( char *) * 3);
	wallsngrounds[0] = ft_strdup(grass_);
	wallsngrounds[1] = ft_strdup(tree_);
	return (wallsngrounds);
}

void	init_wallsngrounds(t_data *data)
{
	int		i;
	int		j;
	char 	*str;
	char	*texture;
	int		w;
	int		h;
	char 	**wallsngrounds_paths;

	i = 0;
	wallsngrounds_paths = init_wallsngrounds_path(data);
	while (i < 2)
	{
		j = 0;
		texture = wallsngrounds_paths[i];
		while (j < 2)
		{
			str = path_creator(texture, j);
			printf("%s\n", str);
			data->assets.wallsngrounds[i][j].img = mlx_xpm_file_to_image(data->mlx, str, &w, &h);
			free(str);
			j++;
			printf("a\n");
		}
		i++;
	}
}
