/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:44:02 by anporced          #+#    #+#             */
/*   Updated: 2023/12/04 13:27:07 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (ERROR);
}
int		ft_check_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == PLAYER)
				game->map.player++;
			else if (game->map.map[i][j] == COLLECTIBLE)
				game->map.collectible++;
			else if (game->map.map[i][j] == EXIT)
				game->map.exit++;
			j++;
		}
		i++;
	}
	if (game->map.player != 1 || game->map.collectible == 0 || game->map.exit == 0)
		return (ft_error("Invalid map"));
	return (SUCCESS);
}

int		ft_init_game(t_game *game, char *file)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_error("Failed to initialize mlx"));
	if (ft_init_map(game, file) == ERROR)
		return (ERROR);
	if (ft_check_map(game) == ERROR)
		return (ERROR);
	if (ft_init_player(game) == ERROR)
		return (ERROR);
	if (ft_init_window(game) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
int		ft_init_map(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_error("Failed to open map file"));
	game->map.width = 0;
	game->map.height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (game->map.width == 0)
			game->map.width = ft_strlen(line);
		else if (game->map.width != (int)ft_strlen(line))
			return (ft_error("Invalid map"));
		game->map.height++;
		free(line);
	}
	free(line);
	close(fd);
	game->map.map = malloc(sizeof(int *) * game->map.height);
	if (!game->map.map)
		return (ft_error("Failed to allocate memory"));
	i = 0;
	while (i < game->map.height)
	{
		game->map.map[i] = malloc(sizeof(int) * game->map.width);
		if (!game->map.map[i])
			return (ft_error("Failed to allocate memory"));
		i++;
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_error("Failed to open map file"));
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (line[j] == '1')
				game->map.map[i][j] = WALL;
			else if (line[j] == '0')
				game->map.map[i][j] = EMPTY;
			else if (line[j] == 'C')
				game->map.map[i][j] = COLLECTIBLE;
			else if (line[j] == 'E')
				game->map.map[i][j] = EXIT;
			else if (line[j] == 'P')
				game->map.map[i][j] = PLAYER;
			else
				return (ft_error("Invalid map"));
			j++;
		}
		free(line);
		i++;
	}
	free(line);
	close(fd);
	return (SUCCESS);
}
int		ft_init_window(t_game *game)
{
	game->width = game->map.width * TILE_SIZE;
	game->height = game->map.height * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
	if (!game->win)
		return (ft_error("Failed to create window"));
	return (SUCCESS);
}
int		ft_init_player(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == PLAYER)
			{
				game->player = malloc(sizeof(t_player));
				if (!game->player)
					return (ft_error("Failed to allocate memory"));
				game->player->x = j;
				game->player->y = i;
				game->player->dir = PLAYER_DOWN;
				game->player->moves = 0;
				return (SUCCESS);
			}
			j++;
		}
		i++;
	}
	return (ft_error("Failed to find player"));
}
int		ft_init_image(t_game *game)
{
	game->img = mlx_new_image(game->mlx, game->width, game->height);
	if (!game->img)
		return (ft_error("Failed to create image"));
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);
	if (!game->addr)
		return (ft_error("Failed to get image address"));
	return (SUCCESS);
}
int		ft_init_tile(t_game *game)
{
	game->tile = malloc(sizeof(t_tile));
	if (!game->tile)
		return (ft_error("Failed to allocate memory"));
	game->tile->empty = ft_draw_image(game, TILE_SIZE, TILE_SIZE, "./images/empty.xpm");
	if (!game->tile->empty)
		return (ft_error("Failed to load empty tile"));
	game->tile->wall = ft_draw_image(game, TILE_SIZE, TILE_SIZE, "./images/wall.xpm");
	if (!game->tile->wall)
		return (ft_error("Failed to load wall tile"));
	game->tile->collectible = ft_draw_image(game, TILE_SIZE, TILE_SIZE, "./images/collectible.xpm");
	if (!game->tile->collectible)
		return (ft_error("Failed to load collectible tile"));
	game->tile->exit = ft_draw_image(game, TILE_SIZE, TILE_SIZE, "./images/exit.xpm");
	if (!game->tile->exit)
		return (ft_error("Failed to load exit tile"));
	game->tile->player_up = ft_draw_image(game, TILE_SIZE, TILE_SIZE, "./images/player_up.xpm");
	if (!game->tile->player_up)
		return (ft_error("Failed to load player up tile"));
	game->tile->player_down = ft_draw_image(game, TILE_SIZE, TILE_SIZE, "./images/player_down.xpm");
	if (!game->tile->player_down)
		return (ft_error("Failed to load player down tile"));
	game->tile->player_left = ft_draw_image(game, TILE_SIZE, TILE_SIZE, "./images/player_left.xpm");
	if (!game->tile->player_left)
		return (ft_error("Failed to load player left tile"));
	game->tile->player_right = ft_draw_image(game, TILE_SIZE, TILE_SIZE, "./images/player_right.xpm");
	if (!game->tile->player_right)
		return (ft_error("Failed to load player right tile"));
	return (SUCCESS);
}

int		ft_draw_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == EMPTY)
				ft_draw_tile(game, j, i, TILE_EMPTY);
			else if (game->map.map[i][j] == WALL)
				ft_draw_tile(game, j, i, TILE_WALL);
			else if (game->map.map[i][j] == COLLECTIBLE)
				ft_draw_tile(game, j, i, TILE_COLLECTIBLE);
			else if (game->map.map[i][j] == EXIT)
				ft_draw_tile(game, j, i, TILE_EXIT);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
int		ft_draw_player(t_game *game)
{
	if (game->player->dir == PLAYER_UP)
		ft_draw_tile(game, game->player->x, game->player->y, TILE_PLAYER_UP);
	else if (game->player->dir == PLAYER_DOWN)
		ft_draw_tile(game, game->player->x, game->player->y, TILE_PLAYER_DOWN);
	else if (game->player->dir == PLAYER_LEFT)
		ft_draw_tile(game, game->player->x, game->player->y, TILE_PLAYER_LEFT);
	else if (game->player->dir == PLAYER_RIGHT)
		ft_draw_tile(game, game->player->x, game->player->y, TILE_PLAYER_RIGHT);
	return (SUCCESS);
}
int		ft_draw_image(t_game *game, int x, int y, char *path)
{
	t_data	*img;
	int		img_width;
	int		img_height;

	img = malloc(sizeof(t_data));
	if (!img)
		return (ft_error("Failed to allocate memory"));
	img->img = mlx_xpm_file_to_image(game->mlx, path, &img_width, &img_height);
	if (!img->img)
		return (ft_error("Failed to load image"));
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	if (!img->addr)
		return (ft_error("Failed to get image address"));
	mlx_put_image_to_window(game->mlx, game->win, img->img, x, y);
	return (SUCCESS);
}
int		ft_draw_tile(t_game *game, int x, int y, int tile)
{
	if (tile == TILE_EMPTY)
		ft_draw_image(game, x * TILE_SIZE, y * TILE_SIZE, "./images/empty.xpm");
	else if (tile == TILE_WALL)
		ft_draw_image(game, x * TILE_SIZE, y * TILE_SIZE, "./images/wall.xpm");
	else if (tile == TILE_COLLECTIBLE)
		ft_draw_image(game, x * TILE_SIZE, y * TILE_SIZE, "./images/collectible.xpm");
	else if (tile == TILE_EXIT)
		ft_draw_image(game, x * TILE_SIZE, y * TILE_SIZE, "./images/exit.xpm");
	else if (tile == TILE_PLAYER_UP)
		ft_draw_image(game, x * TILE_SIZE, y * TILE_SIZE, "./images/player_up.xpm");
	else if (tile == TILE_PLAYER_DOWN)
		ft_draw_image(game, x * TILE_SIZE, y * TILE_SIZE, "./images/player_down.xpm");
	else if (tile == TILE_PLAYER_LEFT)
		ft_draw_image(game, x * TILE_SIZE, y * TILE_SIZE, "./images/player_left.xpm");
	else if (tile == TILE_PLAYER_RIGHT)
		ft_draw_image(game, x * TILE_SIZE, y * TILE_SIZE, "./images/player_right.xpm");
	return (SUCCESS);
}

int		ft_move_player(t_game *game, int x, int y)
{
	if (game->map.map[game->player->y + y][game->player->x + x] == WALL)
		return (ERROR);
	if (game->map.map[game->player->y + y][game->player->x + x] == COLLECTIBLE)
	{
		game->map.map[game->player->y + y][game->player->x + x] = EMPTY;
		game->collectibles--;
	}
	if (game->map.map[game->player->y + y][game->player->x + x] == EXIT)
	{
		if (game->collectibles == 0)
			return (ft_close_window(game));
		else
			return (ERROR);
	}
	game->map.map[game->player->y][game->player->x] = EMPTY;
	game->player->x += x;
	game->player->y += y;
	game->map.map[game->player->y][game->player->x] = PLAYER;
	game->player->moves++;
	return (SUCCESS);
}
int		ft_move_up(t_game *game)
{
	game->player->dir = PLAYER_UP;
	return (ft_move_player(game, 0, -1));
}
int		ft_move_down(t_game *game)
{
	game->player->dir = PLAYER_DOWN;
	return (ft_move_player(game, 0, 1));
}
int		ft_move_left(t_game *game)
{
	game->player->dir = PLAYER_LEFT;
	return (ft_move_player(game, -1, 0));
}
int		ft_move_right(t_game *game)
{
	game->player->dir = PLAYER_RIGHT;
	return (ft_move_player(game, 1, 0));
}

int		ft_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_image(game->mlx, game->tile->empty->img);
	mlx_destroy_image(game->mlx, game->tile->wall->img);
	mlx_destroy_image(game->mlx, game->tile->collectible->img);
	mlx_destroy_image(game->mlx, game->tile->exit->img);
	mlx_destroy_image(game->mlx, game->tile->player_up->img);
	mlx_destroy_image(game->mlx, game->tile->player_down->img);
	mlx_destroy_image(game->mlx, game->tile->player_left->img);
	mlx_destroy_image(game->mlx, game->tile->player_right->img);
	free(game->tile->empty);
	free(game->tile->wall);
	free(game->tile->collectible);
	free(game->tile->exit);
	free(game->tile->player_up);
	free(game->tile->player_down);
	free(game->tile->player_left);
	free(game->tile->player_right);
	free(game->tile);
	free(game->map.map);
	free(game->map_info);
	free(game->player);
	free(game);
	exit(0);
	return (SUCCESS);
}
int		ft_close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_image(game->mlx, game->tile->empty->img);
	mlx_destroy_image(game->mlx, game->tile->wall->img);
	mlx_destroy_image(game->mlx, game->tile->collectible->img);
	mlx_destroy_image(game->mlx, game->tile->exit->img);
	mlx_destroy_image(game->mlx, game->tile->player_up->img);
	mlx_destroy_image(game->mlx, game->tile->player_down->img);
	mlx_destroy_image(game->mlx, game->tile->player_left->img);
	mlx_destroy_image(game->mlx, game->tile->player_right->img);
	free(game->tile->empty);
	free(game->tile->wall);
	free(game->tile->collectible);
	free(game->tile->exit);
	free(game->tile->player_up);
	free(game->tile->player_down);
	free(game->tile->player_left);
	free(game->tile->player_right);
	free(game->tile);
	free(game->map.map);
	free(game->map_info);
	free(game->player);
	free(game);
	exit(0);
	return (SUCCESS);
}
int		ft_close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_image(game->mlx, game->tile->empty->img);
	mlx_destroy_image(game->mlx, game->tile->wall->img);
	mlx_destroy_image(game->mlx, game->tile->collectible->img);
	mlx_destroy_image(game->mlx, game->tile->exit->img);
	mlx_destroy_image(game->mlx, game->tile->player_up->img);
	mlx_destroy_image(game->mlx, game->tile->player_down->img);
	mlx_destroy_image(game->mlx, game->tile->player_left->img);
	mlx_destroy_image(game->mlx, game->tile->player_right->img);
	free(game->tile->empty);
	free(game->tile->wall);
	free(game->tile->collectible);
	free(game->tile->exit);
	free(game->tile->player_up);
	free(game->tile->player_down);
	free(game->tile->player_left);
	free(game->tile->player_right);
	free(game->tile);
	free(game->map.map);
	free(game->map_info);
	free(game->player);
	free(game);
	exit(0);
	return (SUCCESS);
}

int		ft_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == PLAYER_UP)
		ft_move_up(game);
	else if (keycode == KEY_S || keycode == PLAYER_DOWN)
		ft_move_down(game);
	else if (keycode == KEY_A || keycode == PLAYER_LEFT)
		ft_move_left(game);
	else if (keycode == KEY_D || keycode == PLAYER_RIGHT)
		ft_move_right(game);
	else if (keycode == KEY_ESC)
		ft_close_window(game);
	return (SUCCESS);
}
int		ft_key_release(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	return (SUCCESS);
}
int		ft_key_hook(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, ft_key_press, game);
	mlx_hook(game->win, 3, 1L << 1, ft_key_release, game);
	mlx_hook(game->win, 17, 1L << 17, ft_close, game);
	return (SUCCESS);
}

int		ft_exit_game(t_game *game)
{
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->player->moves, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("Press ESC to exit\n", 1);
	ft_key_hook(game);
	mlx_loop(game->mlx);
	return (SUCCESS);
}
