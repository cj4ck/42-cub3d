/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validtion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:08:12 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/28 19:05:29 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	pc_fill(char **map, t_vec2 size, int row, int col)
{
	int	i;

	i = 0;
	if (row < 0 || col < 0 || row >= (int)size.y || col >= (int)size.x)
		return (0);
	if (map[row][col] == 'F' || map[row][col] != '0')
	{
		if (map[row][col] == '\0')
			return (0);
		return (1);
	}
	map[row][col] = 'F';
	i += pc_fill(map, size, row - 1, col);
	i += pc_fill(map, size, row + 1, col);
	i += pc_fill(map, size, row, col - 1);
	i += pc_fill(map, size, row, col + 1);
	if (i != 4)
		return (0);
	return (1);
}

static void	pc_fill_edges(char **map, int height, int wight)
{
	int	i;

	i = 0;
	while (i < wight - 1)
		map[0][i++] = '1';
	i = 0;
	while (i < height)
		map[i++][0] = '1';
	i = 0;
	while (i < height)
	{
		map[i][ft_strlen(map[i]) - 1] = '1';
		i++;
	}
}

int	pc_check_map(char **map, t_vec2 p_pos, t_vec2 size, t_env *env)
{
	int	result;

	result = pc_fill(map, size, (int)p_pos.y, (int)p_pos.x);
	pc_print_map(env);
	pc_fill_edges(map, (int)size.y, (int)size.x);
	return (result);
}

unsigned int	pc_decode_color(t_env *env, char *option)
{
	unsigned int	result;
	char			*tmp;
	int				i;
	int				k;

	i = 0;
	k = 0;
	result = 0;
	while (k < 3)
	{
		option += i;
		i = 0;
		while (!ft_isdigit(*(++option)))
			;
		while (ft_isdigit(option[i]))
			i++;
		tmp = ft_substr(option, 0, i);
		if (!ft_isnumber(tmp) || ft_atoi(tmp) < 0 || ft_atoi(tmp) > 255)
			pc_error("One of color argument is not a valid number", env);
		result <<= 8;
		result += ft_atoi(tmp);
		free(tmp);
		k++;
	}
	return (result);
}
