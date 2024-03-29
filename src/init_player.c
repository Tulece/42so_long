/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 01:48:31 by anporced          #+#    #+#             */
/*   Updated: 2024/02/06 12:07:07 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	malloc_evolis(t_data *data)
{
	data->assets.player = (t_img **)malloc(sizeof(t_img *) * 8);
	data->assets.player[0] = (t_img *)malloc(sizeof(t_img) * 8);
	data->assets.player[1] = (t_img *)malloc(sizeof(t_img) * 8);
	data->assets.player[2] = (t_img *)malloc(sizeof(t_img) * 8);
	data->assets.player[3] = (t_img *)malloc(sizeof(t_img) * 8);
	data->assets.player[4] = (t_img *)malloc(sizeof(t_img) * 8);
	data->assets.player[5] = (t_img *)malloc(sizeof(t_img) * 8);
	data->assets.player[6] = (t_img *)malloc(sizeof(t_img) * 8);
	data->assets.player[7] = (t_img *)malloc(sizeof(t_img) * 8);
}

char	**init_evolis_path(void)
{
	char	**evopaths;

	evopaths = malloc(sizeof(char *) * 9);
	evopaths[0] = ft_strdup(PATH_EVOLI);
	evopaths[1] = ft_strdup(PATH_PYROLI);
	evopaths[2] = ft_strdup(PATH_AQUALI);
	evopaths[3] = ft_strdup(PATH_VOLTALI);
	evopaths[4] = ft_strdup(PATH_NOCTALI);
	evopaths[5] = ft_strdup(PATH_MENTALI);
	evopaths[6] = ft_strdup(PATH_GIVRALI);
	evopaths[7] = ft_strdup(PATH_PHYLLALI);
	return (evopaths);
}

void	init_evolis(t_data *data)
{
	int		i;
	int		j;
	char	*str;
	char	*evolition;
	char	**evopaths;

	i = 0;
	malloc_evolis(data);
	evopaths = init_evolis_path();
	while (i < 8)
	{
		j = 0;
		evolition = evopaths[i];
		while (j < 8)
		{
			str = path_creator(evolition, j);
			data->assets.player[i][j].img = mlx_xpm_file_to_image(data->mlx,
					str, &(int){0}, &(int){0});
			data->assets.player[i][j].path = str;
			j++;
		}
		i++;
	}
	free_evolis_path(evopaths);
}
