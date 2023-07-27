/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_drawings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:54:18 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/28 19:26:15 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_texture	pc_get_correct_side(t_env *env, t_vec2 ray)
{
	if (round(ray.y * 256) == floor(ray.y) * 256 && floor(ray.y) != 0
		&& env->map.bit_map[(int)floor(ray.y) - 1][(int)floor(ray.x)] != '1')
		return (env->map.north);
	if (round((ray.x) * 256) == floor(ray.x) * 256)
		return (env->map.west);
	if (round((ray.y) * 256) == (floor(ray.y) + 1) * 256
		&& env->map.bit_map[(int)floor(ray.y)] != 0
		&& env->map.bit_map[(int)floor(ray.y) + 1][(int)floor(ray.x)] != '1')
		return (env->map.south);
	else
		return (env->map.east);
}

t_texture	*pc_choose_side(t_env *env, char *option)
{
	if (!ft_strncmp(option, "NO ", 3))
		return (&env->map.north);
	if (!ft_strncmp(option, "SO ", 3))
		return (&env->map.south);
	if (!ft_strncmp(option, "WE ", 3))
		return (&env->map.west);
	if (!ft_strncmp(option, "EA ", 3))
		return (&env->map.east);
	return (0);
}
