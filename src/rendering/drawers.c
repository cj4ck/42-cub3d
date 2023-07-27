/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:02:35 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/28 20:07:54 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	pc_frame_update(t_env *env)
{
	pc_render_frame(env);
	return (0);
}

void	pc_render_frame(t_env *env)
{
	pc_ray_casting(env);
	mlx_put_image_to_window(env->mlx, env->window, env->img, 0, 0);
}

double	get_distance_to_wall(t_env *env, t_vec2 *ray, double rayCos,
	double raySin)
{
	int		is_wall;
	char	tmp;

	is_wall = 0;
	while (!is_wall)
	{
		ray->x += rayCos;
		ray->y += raySin;
		tmp = env->map.bit_map[(int)floor(ray->y)][(int)floor(ray->x)];
		is_wall = (tmp == '1' || tmp == '\0');
	}
	return (sqrt(pow(env->player.pos.x - ray->x, 2)
			+ pow(env->player.pos.y - ray->y, 2)));
}
