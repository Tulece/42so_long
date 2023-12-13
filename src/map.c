/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <anporced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:36:31 by anporced          #+#    #+#             */
/*   Updated: 2023/12/13 23:27:24 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	ft_error(char *str, t_data *data)
{
	printf("%s\n", str);
	end(data);
}

static int	get_file_size(t_data *data)
{
	int		fd;
	int		size;
	char	c;

	fd = open(data->map_path, O_RDONLY);
	if (fd == -1)
		ft_error("Error open file", data);
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
		ft_error("Error malloc", data);
	fd = open(data->map_path, O_RDONLY);
	if (fd == -1)
		ft_error("Error open file", data);
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
	while (data->map[size.y])
		size.y++;
	size.x = 0;
	while (data->map[0][size.x])
		size.x++;
	return (size);
}
