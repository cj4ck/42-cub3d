/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:49:56 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/28 19:11:14 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_texture
{
	void	*img;
	int		height;
	int		width;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_map
{
	char			**bit_map;
	t_texture		north;
	t_texture		south;
	t_texture		west;
	t_texture		east;
	unsigned int	ceiling;
	unsigned int	floor;
}	t_map;

typedef struct s_player
{
	t_vec2	pos;
	int		rotation;
}	t_player;

typedef struct s_render
{
	t_vec2	point;
	double	texture_pos;
}	t_render;

typedef struct s_env
{
	void			*mlx;
	void			*window;
	void			*img;
	char			*img_addr;
	t_texture		sky;
	t_texture		floor;

	t_vec2			window_size;
	t_vec2			window_half_size;
	double			raycast_increment;
	double			raycast_precision;
	double			half_fov;

	int				bits_per_pixel;
	int				line_length;
	int				endian;

	t_map			map;
	t_player		player;
	t_render		r;
}	t_env;

#endif
