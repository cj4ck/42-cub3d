/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:03:31 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/28 19:33:25 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "cub.h"

void	pc_fps_counter(t_env *env)
{
	clock_t				start;
	clock_t				end;
	static unsigned int	frames = 0;
	static clock_t		delta = 0;
	static char			*result = 0;

	start = clock();
	pc_render_frame(env);
	end = clock();
	frames++;
	delta += end - start;
	if ((delta / (double)CLOCKS_PER_SEC) > 1)
	{
		if (result)
			free(result);
		result = ft_itoa(frames);
		frames = 0;
		delta = 0;
	}
	mlx_string_put(env->mlx, env->window, 10, 20, 0xFFFFFF, "FPS:");
	if (result)
		mlx_string_put(env->mlx, env->window, 40, 20, 0xFFFFFF, result);
}
