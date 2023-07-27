/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels_drawings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:55:24 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/28 19:31:24 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	pc_put_px(t_env *med, int color, t_vec2 point)
{
	char	*dst;
	int		line_l;
	int		bpp;

	line_l = med->line_length;
	bpp = med->bits_per_pixel;
	dst = med->img_addr + ((int)point.y * line_l + (int)point.x * (bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	pc_get_px(t_texture texture, t_vec2 point)
{
	char	*dst;
	int		line_l;
	int		bpp;

	line_l = texture.line_length;
	bpp = texture.bits_per_pixel;
	dst = texture.addr + ((int)point.y * line_l + (int)point.x * (bpp / 8));
	return (*(unsigned int *)dst);
}
