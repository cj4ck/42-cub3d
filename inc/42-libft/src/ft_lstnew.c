/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:20:15 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/23 16:33:48 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/**
 * @brief Allocates (with malloc(3)) and returns a new node (ptr).
 * The variable ’content’ (in t_list) is initialized with the value of ’content’
 * The variable ’next’ is initialized to NULL.
 *
 * @param content The content to create the node with.
 * @return t_list* The new node.
 */
t_list	*ft_lstnew(char *content)
{
	t_list	*result;

	result = (t_list *)malloc(sizeof(t_list));
	if (!result)
		return (0);
	if (content == 0)
	{
		result->content = 0;
		result->next = 0;
	}
	else
	{
		result->content = content;
		result->next = 0;
	}
	return (result);
}

// int	main()
// {
// 	t_list	*b;
// 	b = ft_lstnew("hello");
// 	printf("%s\n", (char *)(b -> content));
// }
