/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <anporced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 01:48:31 by anporced          #+#    #+#             */
/*   Updated: 2023/12/11 22:16:39 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_textures(t_data *data)
{
	int		j;
	char 	*str;
	int		w;
	int		h;
	
	j = 0;
	data->assets.evoli = malloc(sizeof(t_img) * 8);
	while (j < 8)
	{
		str = path_creator(evoli_, j);
		printf("%s\n", str);
		data->assets.evoli[j].img = mlx_xpm_file_to_image(data->mlx, "rien lol", &w, &h);
		printf("%s\n", str);
		printf("&w=%d\n&h=%d\n", w, h);
		free(str);
		j++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->assets.evoli[0].img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->assets.evoli[1].img, 0, 64);
	mlx_put_image_to_window(data->mlx, data->win, data->assets.evoli[2].img, 0, 128);
	mlx_put_image_to_window(data->mlx, data->win, data->assets.evoli[3].img, 0, 192);
	mlx_put_image_to_window(data->mlx, data->win, data->assets.evoli[4].img, 0, 256);
	mlx_put_image_to_window(data->mlx, data->win, data->assets.evoli[5].img, 0, 320);
	mlx_put_image_to_window(data->mlx, data->win, data->assets.evoli[6].img, 0, 384);
	mlx_put_image_to_window(data->mlx, data->win, data->assets.evoli[7].img, 0, 448);
}

char	*path_creator(char *pokemon, int i)
{
	char 	*number;
	char	*str;
	char	*path;

	number = ft_itoa(i);
	str = ft_strjoin(pokemon, number);
	free(number);
	path = ft_strjoin(str, ".xpm");
	free(str);
	return (path);
}

int main(void)
{
    t_data 	data;
    int 	i;
	t_axes	position;

    i = 0;
	data.mlx = mlx_init();
	mlx_new_window(data.mlx, 1024, 1024, "so_long");
	mlx_put_image_to_window(data.mlx, data.win, "../textures/evolition/evoli0.xpm", 64, 64);
	// init_textures(&data);
    mlx_loop(data.mlx);

    return 0;
}
