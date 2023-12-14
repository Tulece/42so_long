/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <anporced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:27:27 by anporced          #+#    #+#             */
/*   Updated: 2023/12/14 14:26:43 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	malloc_textures(t_data *data)
{
	data->assets.textures = (t_img **)malloc(sizeof(t_img *) * 2);
	data->assets.textures[0] = (t_img *)malloc(sizeof(t_img) * 2);
	data->assets.textures[1] = (t_img *)malloc(sizeof(t_img) * 2);
}

char	**init_textures_path(t_data *data)
{
	char	**textures;

	textures = malloc(sizeof( char *) * 3);
	textures[0] = ft_strdup(grass_);
	textures[1] = ft_strdup(tree_);
	return (textures);
}

void	init_textures(t_data *data)
{
	int		i;
	int		j;
	char 	*str;
	char	*texture;
	int		w;
	int		h;
	char 	**textures_paths;

	i = 0;
	textures_paths = init_textures_path(data);
	while (i < 2)
	{
		j = 0;
		texture = textures_paths[i];
		while (j < 2)
		{
			str = path_creator(texture, j);
			data->assets.textures[i][j].img = mlx_xpm_file_to_image(data->mlx, str, &w, &h);
			data->assets.textures[i][j].path = str;
			j++;
		}
		i++;
	}
}
