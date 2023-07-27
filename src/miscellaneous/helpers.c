/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:07:33 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/28 19:27:05 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	pc_print_player(t_env *env)
{
	if (env->player.rotation == 270)
		ft_printf("🔝");
	if (env->player.rotation == 0)
		ft_printf("🔜");
	if (env->player.rotation == 90)
		ft_printf("🔚");
	if (env->player.rotation == 180)
		ft_printf("🔙");
}

void	pc_print_map(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (env->map.bit_map[i])
	{
		j = 0;
		while (env->map.bit_map[i][j])
		{
			if (floor(env->player.pos.y) == i && floor(env->player.pos.x) == j)
				pc_print_player(env);
			else if (env->map.bit_map[i][j] == '0')
				ft_printf("⬛");
			else if (env->map.bit_map[i][j] == '1')
				ft_printf("🟦");
			else if (env->map.bit_map[i][j] == 'F')
				ft_printf("🟩");
			j++;
		}
		i++;
		ft_printf("\n");
	}
}

double	pc_degree_to_radians(double degree)
{
	return ((degree * M_PI) / 180);
}
