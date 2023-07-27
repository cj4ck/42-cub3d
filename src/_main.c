/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:19:56 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/28 15:23:00 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_env	env;

	pc_input_checker(ac, av);
	pc_init_atributes(&env);
	pc_init_window(&env);
	pc_init_textures(&env);
	pc_read_map_file(&env, av[1]);
	mlx_loop_hook(env.mlx, pc_frame_update, &env);
	mlx_loop(env.mlx);
	return (0);
}
