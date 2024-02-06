/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:36:31 by anporced          #+#    #+#             */
/*   Updated: 2024/02/06 11:46:25 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_file_size(t_data *data)
{
	int		fd;
	int		size;
	char	c;

	fd = open(data->map.map_path, O_RDONLY);
	if (fd == -1)
		ft_printf("An error occured while opening the map.\n");
	size = 0;
	while (read(fd, &c, 1) > 0)
		size++;
	close(fd);
	return (size);
}

char	*file_to_str(t_data *data)
{
	int		fd;
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (get_file_size(data) + 1));
	if (!str)
		ft_printf("An error occured with malloc.\n");
	fd = open(data->map.map_path, O_RDONLY);
	if (fd == -1)
		ft_printf("An rror occured while opening the map.\n");
	i = 0;
	while (read(fd, &str[i], 1) > 0)
		i++;
	str[i] = '\0';
	close(fd);
	return (str);
}

char	**str_to_tab(char *str)
{
	char	**map;

	map = ft_split(str, '\n');
	free(str);
	return (map);
}

t_axes	map_size(t_data *data)
{
	t_axes	size;

	size.y = 0;
	while (data->map.map[size.y])
		size.y++;
	size.x = 0;
	while (data->map.map[0][size.x])
		size.x++;
	return (size);
}

void	init_map(t_data *data)
{
	int		i;
	size_t	len;

	i = 0;
	data->map.map = str_to_tab(file_to_str(data));
	data->map.map_dim = map_size(data);
	len = ft_strlen(data->map.map[i]);
	while (data->map.map[i])
	{
		if (ft_strlen(data->map.map[i]) != len)
		{
			ft_printf("The map is invalid, it must be a rectangle.\n");
			quit_early(data);
		}
		i++;
	}
}
