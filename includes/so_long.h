/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:55:40 by anporced          #+#    #+#             */
/*   Updated: 2024/01/08 13:06:03 by anporced         ###   ########.fr       */
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
# include <limits.h>

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
# define ATTACK ' '

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
	t_axes	e_pos;
	int		nb_e;
	int		state;
	int		anim_direction;
}			t_portal;

typedef struct	s_collectibles {
	t_axes					c_pos;
	int						stone;
	struct s_collectibles	*next;
}							t_collectibles;

typedef struct	s_player {
	t_axes				p_pos;
	t_axes				dest_pos;
	int					state;
	int					nb_p;
	int					got_c;
	unsigned int		step_count;
	int					direction;
}						t_player;

typedef struct	s_enemies {
	t_axes				z_pos;
	t_axes				dest_pos;
	int					state;
	unsigned int		moves;
	struct s_enemies	*next;
	int					direction;
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
	t_img	attack;
}			t_assets;

typedef struct s_map {
	char		**map;
	t_axes		map_dim;
	char		*map_path;
	int			nb_c;
	int			nb_z;
}				t_map;

typedef struct s_data {
	void			*mlx;
	void			*win;
	int				img_width;
	int				img_height;
	t_axes			axes;
	t_map			map;
	t_assets		assets;
	t_player		player;
	t_enemies		*enemies;
	t_collectibles	*collectibles;
	t_portal		portal;
	int				frame;
	int				clock;
	int				z_clock;
	int				color;
}				t_data;

void	data_init(t_data *data);
void	ft_error(char *str, t_data *data);
char	**str_to_tab(char *str);
char	*file_to_str(t_data *data);
t_axes	map_size(t_data *data);
int		is_walkable(char c);
void	check_map(t_data *data);

void	display01(t_data *data, t_axes i);
void	display_pe(t_data *data, t_axes i);
void	display_zc(t_data *data, t_axes i);
void	display_map(t_data *data);
void	merge_img(t_img bg, t_img fg, t_data *data, t_axes i);
void	overlay_img(t_img fg, t_img bg, t_data *data, t_axes i);

// void	merge_attack(t_img bg, t_img fg, t_data *data, t_axes i, int color);
// void	overlay_attack(t_img fg, t_img bg, t_data *data, t_axes i);

void	full_init(t_data *data);

int		hook_switch(int keycode, t_data *data);
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

void	player_finder(t_data *data);
void	enemies_finder(t_data *data);
void	collec_finder(t_data *data);
void	exit_finder(t_data *data);
void	evolve(t_data *data, t_axes dest_pos);

int	hook_switch(int keycode, t_data *data);

void	moves(t_data *data, t_axes dest_pos);
int		move_up(t_data *data);
int		move_down(t_data *data);
int		move_left(t_data *data);
int		move_right(t_data *data);

void	initialize_random(void);
int		generate_random_number(void);
void	z_move(t_data *data, int random_num, t_enemies *enemies);
int		z_is_walkable(char c, t_data *data);

int		enemies_switch(t_data *data);
void	enemies_clock(t_data *data);
int		z_move_up(t_data *data, t_enemies *enemies);
int		z_move_down(t_data *data, t_enemies *enemies);
int		z_move_left(t_data *data, t_enemies *enemies);
int		z_move_right(t_data *data, t_enemies *enemies);

void	render(t_data *data, t_axes src_pos, t_axes dest_pos);
void	enemies_moves(t_data *data, t_axes dest_pos, t_enemies *enemies);
void	anime(t_data *data);
void	anime_player(t_data *data);
void	quit(t_data *data);

t_collectibles	*new_collectible(t_axes pos);
int				collec_lst_size(t_collectibles *lst);
t_collectibles	*collec_last(t_collectibles *lst);
void			add_collec(t_collectibles **lst, t_collectibles *new_lst);
void			lst_collec(t_data *data, t_axes pos);
t_enemies		*new_enemies(t_axes pos);
int				enemies_lst_size(t_enemies *lst);
t_enemies		*enemies_last(t_enemies *lst);
void			add_enemies(t_enemies **lst, t_enemies *new_lst);
void			lst_enemies(t_data *data, t_axes pos);
t_collectibles	*find_by_pos(t_data *data, t_axes pos);


#ifdef __linux__
# include <X11/keysym.h>
# include <X11/X.h>
#elif __APPLE__
# include <ApplicationServices/ApplicationServices.h>
#endif

#endif
