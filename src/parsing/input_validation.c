/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:55:37 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/27 17:14:55 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	print_instructions(void)
{
	printf("%sPlease provide as an argument one of the maps from maps folder \
example:%s ./cub3d maps/cube.cub%s\n", ERROR, GREEN, NC);
	exit(1);
}

void	pc_input_checker(int ac, char **av)
{
	int	fd;

	if (ac != 2 || ft_strlen(av[1]) < 4 || ft_strncmp(av[1]
			+ ft_strlen(av[1]) - 4, ".cub", 4))
		print_instructions();
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		print_instructions();
	close(fd);
}
