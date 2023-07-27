/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:25:13 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/28 19:31:02 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	pc_count_map_height(t_list **file_lines, t_env *env);
static int	pc_count_map_wight(t_list **file_lines);
static void	pc_get_map(t_env *env, t_list *el, char ***map);
static void	pc_get_player(t_env *env, int j, int i, char c);

void	pc_map_validation(t_env *env, t_list **file_lines, int offset)
{
	t_list	*el;
	int		height;
	int		wight;
	char	**map;

	el = *file_lines;
	while (el->next && offset--)
		el = el->next;
	height = pc_count_map_height(&el, env);
	wight = pc_count_map_wight(&el);
	printf("Map size: (%s%i x %i%s)\n", DARKBLUE, wight, height, NC);
	map = ft_calloc(height + 1, sizeof(char *));
	pc_get_map(env, el, &map);
	env->map.bit_map = map;
	if (env->player.pos.x == -1)
		return (pc_error("Map did not contain a player", env));
	if (!pc_check_map(env->map.bit_map, env->player.pos,
			(t_vec2){wight, height}, env))
		return (pc_error("Map is not surrounded by walls", env));
}

static int	pc_count_map_height(t_list **file_lines, t_env *env)
{
	t_list	*el;
	int		size;

	size = 0;
	el = *file_lines;
	while (el->next)
	{
		if (!pc_line_map_vailidation(el->content))
		{
			ft_printf("%s Map contain forbiden character in line %i : %s%s",
				ERROR, size, el->content, NC);
			pc_error("", env);
		}
		el = el->next;
		size++;
	}
	return (size);
}

static int	pc_count_map_wight(t_list **file_lines)
{
	t_list	*el;
	size_t	max;

	max = 0;
	el = *file_lines;
	while (el->next)
	{
		if (ft_strlen(el->content) > max)
		{
			max = ft_strlen(el->content);
		}
		el = el->next;
	}
	return (max);
}

static void	pc_get_map(t_env *env, t_list *el, char ***map)
{
	int		i;
	int		j;

	j = 0;
	while (el->next)
	{
		i = -1;
		while (el->content[++i])
		{
			if (el->content[i] != '1')
			{
				if (el->content[i] == 'N' || el->content[i] == 'S'
					|| el->content[i] == 'W' || el->content[i] == 'E')
					pc_get_player(env, j, i, el->content[i]);
				if (el->content[i] == '\n')
					el->content[i] = '\0';
				else
					el->content[i] = '0';
			}
		}
		(*map)[j] = ft_strdup(el->content);
		j++;
		el = el->next;
	}
	(*map)[j] = 0;
}

static void	pc_get_player(t_env *env, int j, int i, char c)
{
	env->player.pos.x = i + 0.4;
	env->player.pos.y = j + 0.4;
	if (c == 'N')
		env->player.rotation = 270;
	if (c == 'E')
		env->player.rotation = 0;
	if (c == 'S')
		env->player.rotation = 90;
	if (c == 'W')
		env->player.rotation = 180;
}
