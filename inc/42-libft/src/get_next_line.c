/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:00:50 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/28 17:31:48 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*read_file(int fd, char *main_str);
char	*return_func(char *main_str);
char	*reset(char *main_str);

/**
 * @brief Read buffer size from fd (up untill string end) and returns a line.
 *
 * @param fd file descriptor
 * @return char* Read line: correct behavior
 * NULL: there is nothing else to read, or an error occurred
 */
char	*get_next_line(int fd)
{
	static char	*main_str[1024];
	char		*return_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	main_str[fd] = read_file(fd, main_str[fd]);
	if (!main_str[fd])
		return (NULL);
	return_str = return_func(main_str[fd]);
	main_str[fd] = reset(main_str[fd]);
	return (return_str);
}

/**
 * @brief Allocates (with malloc(3)) and returns a new
 * string, which is the result of the concatenation of ’s1’ and ’s2’.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return Char pointer to the new string.
 * 	NULL if the allocation fails.
 */
char	*ft_strjoink(char *s1, char *s2)
{
	char	*new;
	size_t	size_s1;
	size_t	size_s2;
	size_t	i;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = 0;
	}
	i = 0;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	new = malloc(size_s1 + size_s2 + 1);
	if (!new)
		return (NULL);
	while (i < size_s1 + 1)
	{
		((char *)new)[i] = ((char *)s1)[i];
		i++;
	}
	ft_strlcat(new, s2, size_s1 + size_s2 + 1);
	free(s1);
	return (new);
}

/**
 * @brief Reads buffer number of characters from file descriptor and allocates
 * a string to store them. Stops at the end of the file.
 * @param fd file descriptor
 * @param main_str string in which everything gets saved
 * @return char* string
 */
char	*read_file(int fd, char *main_str)
{
	int		i;
	char	*buffer_str;

	i = 1;
	buffer_str = malloc(BUFFER_SIZE + 1);
	if (!buffer_str)
		return (NULL);
	while (!ft_strchr(main_str, '\n') && i != 0)
	{
		i = read(fd, buffer_str, BUFFER_SIZE);
		if (i == -1)
		{
			ft_printf("aaaaa\n", main_str);
			free(buffer_str);
			return (NULL);
		}
		buffer_str[i] = '\0';
		main_str = ft_strjoink(main_str, buffer_str);
	}
	free(buffer_str);
	return (main_str);
}

/**
 * @brief Function returns everything up to new line or end of the file
 * i = chars before new line or end of the file
 * substr cuts the line in place of index
 * i++ before return is for new line char or null
 * null creates buffer overflow but ft_substr() has hardcoded check for that
 * @param main_str
 * @return char*
 */
char	*return_func(char *main_str)
{
	char	*next_line;
	int		i;

	i = 0;
	if (!main_str[i])
		return (NULL);
	while (main_str[i] && main_str[i] != '\n')
		i++;
	i++;
	next_line = ft_substr(main_str, 0, i);
	return (next_line);
}

/**
 * @brief Function substract returned line from main_str and returns the rest
 * of characters that are left in main_str
 * which later on gets reasigned to the main_function if there
 * still is something left
 *
 * @param main_str
 * @return char*
 */
char	*reset(char *main_str)
{
	char	*rest;
	int		i;

	i = 0;
	while (main_str[i] && main_str[i] != '\n')
		i++;
	i++;
	rest = ft_substr(main_str, i, ft_strlen(main_str));
	if (rest[0] == '\0')
	{
		free(rest);
		rest = NULL;
	}
	free(main_str);
	return (rest);
}
