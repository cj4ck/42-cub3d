/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:32:37 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/27 17:04:36 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	pc_clear_2d_table(char **tab);

void	pc_error(char *str, t_env *env)
{
	ft_printf("%s %s\n%s", ERROR, str, NC);
	pc_free_stuff(env);
	pc_close_window(env, 1);
}

void	pc_free_stuff(t_env *env)
{
	if (env->map.bit_map)
		pc_clear_2d_table(env->map.bit_map);
	if (env->sky.img)
		mlx_destroy_image(env->mlx, env->sky.img);
	if (env->floor.img)
		mlx_destroy_image(env->mlx, env->floor.img);
	if (env->map.north.img)
		mlx_destroy_image(env->mlx, env->map.north.img);
	if (env->map.south.img)
		mlx_destroy_image(env->mlx, env->map.south.img);
	if (env->map.west.img)
		mlx_destroy_image(env->mlx, env->map.west.img);
	if (env->map.east.img)
		mlx_destroy_image(env->mlx, env->map.east.img);
}

static void	pc_clear_2d_table(char **tab)
{
	int	i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
			free(tab[i]);
		free(tab);
	}
}
