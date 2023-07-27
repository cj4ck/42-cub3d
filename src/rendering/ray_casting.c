/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:26:01 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/28 19:35:45 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	pc_calculate_wall_height(t_env *env, t_vec2 *ray, double ray_angle);
static void	pc_draw_column(t_env *env, int wall_height, t_texture texture);
static void	pc_draw_floor_texture(t_env *env, t_vec2 point);
static void	pc_draw_wall(t_env *env, t_texture texture, int wall_height,
				double *i);

void	pc_ray_casting(t_env *env)
{
	t_vec2		ray;
	double		ray_angle;
	int			wall_height;
	t_texture	texture;

	ray_angle = env->player.rotation - env->half_fov;
	env->r.point.x = 0;
	while (env->r.point.x < env->window_size.x)
	{
		ray = env->player.pos;
		wall_height = pc_calculate_wall_height(env, &ray, ray_angle);
		texture = pc_get_correct_side(env, ray);
		env->r.texture_pos = floor((int)(texture.width * (ray.x + ray.y))
				% texture.width);
		pc_draw_column(env, wall_height, texture);
		env->r.point.x++;
		ray_angle += env->raycast_increment;
	}
}

static int	pc_calculate_wall_height(t_env *env, t_vec2 *ray, double ray_angle)
{
	double	distance;
	double	ray_cos;
	double	ray_sin;

	ray_cos = cos(pc_degree_to_radians(ray_angle)) / env->raycast_precision;
	ray_sin = sin(pc_degree_to_radians(ray_angle)) / env->raycast_precision;
	distance = get_distance_to_wall(env, ray, ray_cos, ray_sin);
	distance *= cos(pc_degree_to_radians(ray_angle - env->player.rotation));
	return ((int)floor(env->window_half_size.y / distance));
}

static void	pc_draw_column(t_env *env, int wall_height, t_texture texture)
{
	double	i;

	env->r.point.y = 0;
	i = 0;
	while (env->r.point.y < env->window_size.y)
	{
		if (env->r.point.y <= (int)floor(env->window_half_size.y - wall_height))
		{
			if (env->map.ceiling == 0)
				pc_put_px(env, pc_get_px(env->sky, env->r.point), env->r.point);
			else
				pc_put_px(env, env->map.ceiling, env->r.point);
		}
		else if (env->r.point.y <= (int)floor(env->window_half_size.y
				+ wall_height))
			pc_draw_wall(env, texture, wall_height, &i);
		else
		{
			if (env->map.floor == 0)
				pc_draw_floor_texture(env, env->r.point);
			else
				pc_put_px(env, env->map.floor, env->r.point);
		}
		env->r.point.y++;
	}
}

static void	pc_draw_floor_texture(t_env *env, t_vec2 point)
{
	t_vec2	p;

	p.x = point.x;
	p.y = point.y - env->window_half_size.y;
	pc_put_px(env, pc_get_px(env->floor, p), point);
}

static void	pc_draw_wall(t_env *env, t_texture texture, int wall_height,
		double *i)
{
	double			i_inc;
	unsigned int	color;

	i_inc = ((double)texture.height / (wall_height * 2));
	if (wall_height > env->window_half_size.y && *i == 0)
	{
		*i = (((double)(wall_height) - env->window_half_size.y) * i_inc);
	}
	color = pc_get_px(texture, (t_vec2){env->r.texture_pos, floor(*i)});
	pc_put_px(env, color, (t_vec2){env->r.point.x, env->r.point.y});
	(*i) += i_inc;
}
