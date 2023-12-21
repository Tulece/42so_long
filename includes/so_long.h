/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:55:40 by anporced          #+#    #+#             */
/*   Updated: 2023/12/21 13:02:28 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "textures.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>
# include <time.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# define TILE_SIZE 64

# define WALL '1'
# define EMPTY '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'

# define INDEX_LEFT 4
# define INDEX_RIGHT 6
# define INDEX_UP 2
# define INDEX_DOWN 0

typedef struct	s_axes
{
	int			x;
	int			y;
}				t_axes;

typedef struct	s_portal {
	t_axes	axes;
	int		state;
}			t_portal;

typedef struct	s_collectibles {
	t_axes	axes;
	int		type;
}			t_collectibles;

typedef struct	s_player {
	t_axes				axes;
	int					state;
	unsigned int		moves;

}						t_player;

typedef struct	s_enemies {
	t_axes				axes;
	int					state;
	unsigned int		moves;

}						t_enemies;

typedef struct	s_textures {
	t_axes	axes;
	int		state;

}			t_textures;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		h;
	int		w;
	char	*path;
	int		bpp;
	int		size_line;
	int		endian;
}			t_img;

typedef struct s_assets {
	t_img	**player;
	t_img	**enemies;
	t_img	*textures;
	t_img	*collectibles;
	t_img	*portal;
}			t_assets;

typedef struct s_data {
	void		*mlx;
	void		*win;
	char		**map;
	char		*map_path;
	t_axes		map_dim;
	int			img_width;
	int			img_height;
	t_axes		p_pos;
	t_img		img;
	t_axes		axes;
	t_assets	assets;
	t_player	player;
	t_enemies	*enemies;
	int			frame;
	int			direction;
	int			clock;
	t_axes		src_pos;
}			t_data;

void	data_init(t_data *data);
void	ft_error(char *str, t_data *data);
char	**str_to_tab(char *str);
char	*file_to_str(t_data *data);
t_axes	map_size(t_data *data);

void	display_map(t_data *data);
void	merge_img(t_img bg, t_img fg, t_data *data, t_axes i);
void	overlay_img(t_img fg, t_img bg, t_data *data, t_axes i);

int		hook_switch(int keycode, t_data *data);
// void	quit(t_data *data);
int		key_press(int keycode, t_data *data);
void	malloc_evolis(t_data *data);
char	**init_evolis_path(t_data *data);
void	init_evolis(t_data *data);
void	print_img(t_data *data, void *img, t_axes i);
char	*path_creator(char *pokemon, int i);

void	malloc_enemies(t_data *data);
char	**init_enemies_path(t_data *data);
void	init_enemies(t_data *data);

void	malloc_textures(t_data *data);
char	*init_textures_path(t_data *data);
void	init_textures(t_data *data);

void	malloc_collectibles(t_data *data);
char	*init_collectibles_path(t_data *data);
void	init_collectibles(t_data *data);

void	malloc_portal(t_data *data);
char	*init_portal_path(t_data *data);
void	init_portal(t_data *data);

int	hook_switch(int keycode, t_data *data);
void	player_finder(t_data *data);
void	moves(t_data *data, t_axes dest_pos);
int		move_up(t_data *data);
int		move_down(t_data *data);
int		move_left(t_data *data);
int		move_right(t_data *data);
void	render(t_data *data, t_axes src_pos, t_axes dest_pos);
void	anime(t_data *data);
void	quit(t_data *data);

#ifdef __linux__
# include <X11/keysym.h>
# include <X11/X.h>
#elif __APPLE__
# include <ApplicationServices/ApplicationServices.h>
#endif

#endif
