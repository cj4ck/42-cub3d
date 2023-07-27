/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:24:18 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/28 19:40:45 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include "keys.h"
# include "structs.h"

# define WINDOW_W 1200
# define WINDOW_H 900
# define FOV 60
# define RAY_PRECISION 512
# define MOVMENT_SPEED 0.2
# define ROTATION_SPEED 10

/*
└── src/
    └── _main.c
    └── miscellaneous/
        └── exit.c */
void			pc_error(char *str, t_env *env);
void			pc_free_stuff(t_env *env);
/*      └── helpers.c */
void			pc_print_map(t_env *env);
double			pc_degree_to_radians(double degree);
/*		└── window_menager.c */
int				key_press(int key, t_env *env);
int				pc_close_window(t_env *env, int failure);
/*      └── player_control.c */
int				player_control(int key, t_env *env);
/*  └── initialization/
        └── initialization.c */
void			pc_init_atributes(t_env *env);
void			pc_init_window(t_env *env);
/*		└── textures_init.c */
void			pc_init_textures(t_env *env);
void			pc_init_one_texture(t_env *env, t_texture *texture,
					char *file_path);
/*  └── parsing/
        └── input_validation.c */
void			pc_input_checker(int ac, char **av);
/*		└── map_validtion.c */
int				pc_check_map(char **map, t_vec2 p_pos, t_vec2 size, t_env *env);
unsigned int	pc_decode_color(t_env *env, char *option);
/*		└── read_map_file.c */
void			pc_read_map_file(t_env *env, char *path);
int				pc_line_map_vailidation(char *str);
/*		└── read_map.c */
void			pc_map_validation(t_env *env, t_list **file_lines, int offset);
/*  └── rendering/
        └── drawers.c */
int				pc_frame_update(t_env *env);
void			pc_render_frame(t_env *env);
double			get_distance_to_wall(t_env *env, t_vec2 *ray, double rayCos,
					double raySin);
/*		└── fps_counter.c */
void			pc_fps_counter(t_env *env);
/*   	└── pixels_drawings.c */
void			pc_put_px(t_env *med, int color, t_vec2 point);
unsigned int	pc_get_px(t_texture texture, t_vec2 point);
/*   	└── ray_casting.c */
void			pc_ray_casting(t_env *env);
/*   	└── texture_drawings.c */
t_texture		pc_get_correct_side(t_env *env, t_vec2 ray);
t_texture		*pc_choose_side(t_env *env, char *option);

#endif
