/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:47:53 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/27 21:27:18 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	pc_init_textures(t_env *env)
{
	env->sky.img = 0;
	env->floor.img = 0;
	env->map.north.img = 0;
	env->map.south.img = 0;
	env->map.west.img = 0;
	env->map.east.img = 0;
	pc_init_one_texture(env, &env->sky, "textures/sky.xpm");
	pc_init_one_texture(env, &env->floor, "textures/sand_floor.xpm");
	pc_init_one_texture(env, &env->map.north, "textures/N.xpm");
	pc_init_one_texture(env, &env->map.south, "textures/S.xpm");
	pc_init_one_texture(env, &env->map.west, "textures/W.xpm");
	pc_init_one_texture(env, &env->map.east, "textures/E.xpm");
}

void	pc_init_one_texture(t_env *env, t_texture *texture, char *file_path)
{
	if (texture->img)
		mlx_destroy_image(env->mlx, texture->img);
	texture->img = mlx_xpm_file_to_image(env->mlx, file_path, &texture->width,
			&texture->height);
	if (!texture->img)
		return (pc_error("XMP to img failed", env));
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_length, &texture->endian);
}
