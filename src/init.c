/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 01:48:31 by anporced          #+#    #+#             */
/*   Updated: 2023/12/11 16:13:02 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_textures(t_data *data)
{
	int		i;
	char	path[32];

	i = 0;
	data->assets = (t_image ***)malloc(sizeof(t_image **) * (8 + 1));
	data->assets[0] = (t_image **)malloc(sizeof (t_image *) * (8 + 1));
	data->assets[1] = (t_image **)malloc(sizeof (t_image *) * (8 + 1));
	data->assets[2] = (t_image **)malloc(sizeof (t_image *) * (8 + 1));
	data->assets[3] = (t_image **)malloc(sizeof (t_image *) * (8 + 1));
	data->assets[4] = (t_image **)malloc(sizeof (t_image *) * (8 + 1));
	data->assets[5] = (t_image **)malloc(sizeof (t_image *) * (8 + 1));
	data->assets[6] = (t_image **)malloc(sizeof (t_image *) * (8 + 1));
	data->assets[7] = (t_image **)malloc(sizeof (t_image *) * (8 + 1));
	while (i < 8)
	{
		data->assets[0][i] = (t_image *)malloc(sizeof (t_image));
		sprintf(path, "../textures/evolition/evoli%d.xpm", i);
		printf("%p\n", data->assets[0][i]);
		data->assets[0][i]->img = mlx_xpm_file_to_image(data->mlx, path, &(int){0}, &(int){0});
		printf("%s\n", path);
		i++;
	}
	// data->assets[0][0]->img = mlx_xpm_file_to_image(data->mlx, evoliFace1, &data->img_width, &data->img_height);
	// data->assets->groudon->img = mlx_xpm_file_to_image(data->mlx, groudonFace1, &data->img_width, &data->img_height);
	// data->assets->grass->img = mlx_xpm_file_to_image(data->mlx, grass1, &data->img_width, &data->img_height);
}

int	main(void)
{
	t_data	data;

	init_textures(&data);
}
