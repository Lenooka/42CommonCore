/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:07:27 by otolmach          #+#    #+#             */
/*   Updated: 2024/01/07 15:33:21 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <X11/X.h>
# include "LIBFTall/libft.h"
# include <X11/keysym.h>
# include <errno.h>
# include <unistd.h>
# define IMG_X 32
# define IMG_Y 32
# define PATH_E "./texture/exitmy.xpm"
# define PATH_C "./texture/collect.xpm"
# define PATH_B "./texture/background.xpm"
# define PATH_PU "./texture/up.xpm"
# define PATH_PD "./texture/down.xpm"
# define PATH_PL "./texture/left.xpm"
# define PATH_PR "./texture/right.xpm"
# define PATH_W "./texture/wall.xpm"

typedef struct s_img
{
	void	*player;
	void	*p_up;
	void	*p_left;
	void	*p_right;
	void	*p_down;
	void	*background;
	void	*walls;
	void	*c_obj;
	void	*e_obj;
}				t_img;

typedef struct s_map
{
	char	**map_str;
	char	**map_copy;
	int		x;
	int		y;
	int		cake;
	int		cake_copy;
}				t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	int		screen_x;
	int		screen_y;
	int		ppos_x;
	int		ppos_y;
	int		move_count;
	int		collect;
	t_map	*map;
	t_img	*img;
}				t_data;

int		main(int argc, char **argv);
int		close_esc(int keycode, t_data *data);
int		close_mouse(t_data *data);
void	convert_ber(t_data *data, char **argv);
int		ft_line_length(int fd);
int		ft_count_lines(int fd);
void	valid_path(t_data *data, int x, int y);
void	*ft_calloc(size_t nmemb, size_t size);
void	init_imgs(t_data *data, t_map *map);
void	win_size(t_data *data, char **argv);
void	put_background(t_data *data);
void	win_size(t_data *data, char **argv);
char	*ft_sostrjoin(char *s1, char const *s2);
int		hook_keyboard(int keycode, t_data *data);
int		ft_sostrlen(const char *s);
void	put_image(t_data *data, void *img, int x, int y);
int		put_map(t_data *data);
void	free_map_str(t_data *data);
void	map_copy(t_data *data);
void	img_free_destroy(t_data *data);
void	free_img_list(t_data *data);
void	check_path(t_data *data);
void	check_sur_walls(t_data *data, int y, int x, char c);
void	ft_exit(t_data *data, char *str);
void	ft_free_noerror(t_data *data, char *str);
void	previos_ppos(t_data *data);
void	ft_move(t_data *data, int y, int x);
void	start_game(t_data *data);
void	*init_img_check(t_data *data, char *path, void *img);
void	check_char(t_data *d);

#endif
