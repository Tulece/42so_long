/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:55:40 by anporced          #+#    #+#             */
/*   Updated: 2023/12/11 15:50:26 by anporced         ###   ########.fr       */
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

typedef struct	s_axes
{
	int			x;
	int			y;
}				t_axes;

typedef struct	s_player {
	t_axes				axes;
	int					stone;
	unsigned int		moves;

}			t_player;

typedef struct s_image {
	void	*img;
	char	*addr;
	char	*path;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_image;

// typedef struct s_assets {
// 	void	*evoli;
// 	void	*pyroli;
// 	void	*voltali;
// 	void	*aquali;
// 	void	*noctali;
// 	void	*mentali;
// 	void	*phyllali;
// 	void	*givrali;
// 	void	*regice;
// 	void	*hooh;
// 	void	*groudon;
// 	void	*giratina;
// 	void	*mew;
// 	void	*kyogre;
// 	void	*rayquaza;
// 	void	*grass;
// }			t_assets;

typedef struct s_data {
	void	*mlx;
	void	*win;
	int		img_width;
	int		img_height;
	t_image	img;
	t_axes	axes;
	t_image	***assets;
}			t_data;

int		hook_switch(int keycode, t_data *data);
void	quit(t_data *data);
int		key_press(int keycode, t_data *data);

void	init_textures(t_data *data);

#ifdef __linux__
# include <X11/keysym.h>
# include <X11/X.h>
#elif __APPLE__
# include <ApplicationServices/ApplicationServices.h>
#endif

#endif
