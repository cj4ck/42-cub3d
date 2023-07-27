/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:02:34 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/27 21:11:09 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	pc_init_atributes(t_env *env)
{
	env->window_size.y = WINDOW_H;
	env->window_size.x = WINDOW_W;
	env->window_half_size.y = WINDOW_H / 2;
	env->window_half_size.x = WINDOW_W / 2;
	env->half_fov = FOV / 2;
	env->raycast_increment = (double)FOV / (double)WINDOW_W;
	env->raycast_precision = RAY_PRECISION;
	env->player.pos.x = -1;
	env->player.pos.y = -1;
	env->map.bit_map = 0;
	env->map.floor = 0;
	env->map.ceiling = 0;
}

void	pc_init_window(t_env *env)
{
	env->mlx = mlx_init();
	if (!env->mlx)
		return (pc_error("MLX init failed\n", env));
	env->window = mlx_new_window(env->mlx, env->window_size.x,
			env->window_size.y, "PentaCode Cub3D");
	if (!env->window)
		return (pc_error("WINDOW init failed\n", env));
	env->img = mlx_new_image(env->mlx, WINDOW_W, WINDOW_H);
	if (!env->img)
		return (pc_error("IMG init failed\n", env));
	env->img_addr = mlx_get_data_addr(env->img, &env->bits_per_pixel,
			&env->line_length, &env->endian);
	mlx_hook(env->window, 2, 1, key_press, env);
	mlx_hook(env->window, 17, 1, pc_close_window, env);
}
