/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:55:40 by anporced          #+#    #+#             */
/*   Updated: 2024/02/12 12:24:52 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __linux__
#  include <X11/keysym.h>
#  include <X11/X.h>
# elif __APPLE__
#  include <ApplicationServices/ApplicationServices.h>
# endif

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

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define BLUE 0xFF397DE3
# define RED 0xFFD63504
# define YELLOW 0xFFFF945
# define BLACK 0xFF010101
# define PURPLE 0xFF800180
# define ICE_BLUE 0xFFAFDCEC
# define GREEN 0xFF018001

# define TILE_SIZE 64

# define ATTACK ' '

# define INDEX_LEFT 4
# define INDEX_RIGHT 6
# define INDEX_UP 2
# define INDEX_DOWN 0

typedef struct s_axes
{
	int			x;
	int			y;
}				t_axes;

typedef struct s_portal
{
	t_axes	e_pos;
	int		state;
	int		anim_direction;
}			t_portal;

typedef struct s_collectibles
{
	t_axes					c_pos;
	int						stone;
	struct s_collectibles	*next;
}							t_collectibles;

typedef struct s_player
{
	t_axes				p_pos;
	t_axes				dest_pos;
	int					state;
	int					got_c;
	int					step_count;
	int					direction;
}						t_player;

typedef struct s_enemies
{
	t_axes				z_pos;
	t_axes				dest_pos;
	int					state;
	unsigned int		moves;
	struct s_enemies	*next;
	int					direction;
	int					is_hit;
}						t_enemies;

typedef struct s_textures
{
	t_axes	axes;
	int		state;
}			t_textures;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		h;
	int		w;
	char	*path;
	int		bpp;
	int		size_line;
	int		endian;
}			t_img;

typedef struct s_assets
{
	t_img	**player;
	t_img	**enemies;
	t_img	*textures;
	t_img	*collectibles;
	t_img	*portal;
	t_img	attack;
	t_img	*evolutions;
	t_img	*win;
	t_img	*lose;
	void	*stepcount;
}			t_assets;

typedef struct s_map
{
	char		**map;
	char		**map_checker;
	int			accessible_p;
	int			accessible_c;
	int			accessible_e;
	t_axes		map_dim;
	char		*map_path;
	int			nb_c;
	int			nb_z;
	int			nb_e;
	int			nb_p;
}				t_map;

typedef struct s_data
{
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
	int				player_glow;
}				t_data;

void			data_init(t_data *data);
void			data_init2(t_data *data);
void			init_map(t_data *data);
int				get_file_size(t_data *data);
char			**str_to_tab(char *str);
char			*file_to_str(t_data *data);
t_axes			map_size(t_data *data);
int				is_walkable(t_axes pos, t_data *data);
int				is_entity(char c, t_data *data);
char			**malloc_map_check(t_data *data);
void			print_map(t_map map_infos, char **map);
void			dfs(t_axes pos, char **visited, t_data *data);
void			check_map(t_data *data);

void			display01(t_data *data, t_axes i);
void			display_pe(t_data *data);
void			display_zc(t_data *data);
void			display_map(t_data *data);
void			merge_img(t_img bg, t_img fg, t_data *data, t_axes i);
void			overlay_img(t_img fg, t_img bg, t_data *data, t_axes i);

unsigned int	get_color(int state);
void			merge_attack(t_img bg, t_data *data, int color, t_axes i);
void			overlay_attack(t_data *data, t_axes i,
					unsigned int color);
void			display_attack(t_data *data);
t_axes			find_dir(t_axes pos, int dir);
void			attack(t_data *data);

void			full_init(t_data *data);

int				hook_switch(int keycode, t_data *data);

void			malloc_evolis(t_data *data);
char			**init_evolis_path(void);
void			init_evolis(t_data *data);

void			print_img(t_data *data, void *img, t_axes i);
char			*path_creator(char *pokemon, int i);

void			malloc_enemies(t_data *data);
char			**init_enemies_path(void);
void			init_enemies(t_data *data);

void			malloc_textures(t_data *data);
char			*init_textures_path(t_data *data);
void			init_textures(t_data *data);

void			malloc_winlose_screen(t_data *data);
void			init_winlose_screen(t_data *data);

void			malloc_collectibles(t_data *data);
void			init_collectibles(t_data *data);

void			malloc_portal(t_data *data);
char			*init_portal_path(void);
void			init_portal(t_data *data);

void			malloc_attack(t_data *data);
void			init_attack(t_data *data);

void			malloc_evolutions(t_data *data);
void			init_evolutions(t_data *data);

void			player_finder(t_data *data);
void			enemies_finder(t_data *data);
void			collec_finder(t_data *data);
void			exit_finder(t_data *data);
void			evolve(t_data *data, t_axes dest_pos);

int				hook_switch(int keycode, t_data *data);

void			moves(t_data *data, t_axes dest_pos);
void			move_up(t_data *data);
void			move_down(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);

void			turn(t_data *data, t_axes dest_pos, int dir);

void			initialize_random(void);
int				generate_random_number(void);
void			z_move(t_data *data, int random_num, t_enemies *enemies);
int				z_is_walkable(char c, t_data *data, t_axes dest_pos);

int				enemies_switch(t_data *data);
void			enemies_clock(t_data *data);
void			z_move_up(t_data *data, t_enemies *enemies);
void			z_move_down(t_data *data, t_enemies *enemies);
void			z_move_left(t_data *data, t_enemies *enemies);
void			z_move_right(t_data *data, t_enemies *enemies);

void			enemies_moves(t_data *data, t_axes dest_pos,
					t_enemies *enemies);
int				anime(t_data *data);
void			anime_player(t_data *data);

void			quit(t_data *data);
int				cross_quit(t_data *data);
void			quit_early(t_data *data);
void			success_game(t_data *data);
void			lose_game(t_data *data);

void			display_step_count(t_data *data);

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
void			delete_collec_by_pos(t_data *data, t_axes pos);
t_enemies		*z_find_by_pos(t_data *data, t_axes pos);
void			delete_enemy_by_pos(t_data *data, t_axes pos);

void			enemies_clear(t_enemies *enemies);
void			free_enemies(t_data *data);
void			free_enemies_path(char **enemies_path);
void			destroy_enemies(t_data *data);

void			destroy_attack(t_data *data);

void			free_evolis_path(char **evopaths);
void			free_evolis(t_data *data);
void			destroy_evolis(t_data *data);

void			free_collectibles(t_data *data);
void			destroy_collectibles(t_data *data);
void			collec_clear(t_collectibles *collectible);

void			free_evolutions(t_data *data);
void			destroy_evolutions(t_data *data);

void			free_textures(t_data *data);
void			destroy_textures(t_data *data);

void			free_portal(t_data *data);
void			destroy_portal(t_data *data);

void			free_winlose_screen(t_data *data);
void			destroy_winlose_screen(t_data *data);

void			free_map(t_data *data);
void			free_true_map(t_data *data);

#endif
