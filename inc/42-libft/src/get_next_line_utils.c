/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:00:50 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/28 17:32:03 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/**
 * @brief   function searches for the FIRST occurrence of
 * character 'c' in string 's'.If 's' doesnt end with
 * NULL program might cras!
 * @param s This is the string to be scanned.
 * @param c This is the character to be searched in 's'.
 * @return char* Returns a pointer to the first
 * occurrence of c that is converted to a character in string.
 * The function returns NULL if the specified character is not found.
 */
char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if ((char)c == str[i])
				return ((char *)&str[i]);
			i++;
		}
		if ((char)c == str[i])
			return ((char *)&str[i]);
	}
	return (NULL);
}

/**
 * @brief Allocates (with malloc) and returns a substring from the string 's'.
 * The substring begins at index ’start’ and is of maximum size ’len’.
 * @param s	The string from which to create the substring.
 * @param start	The start index of the substring in the string ’s’.
 * @param len	The maximum length of the substring.
 * @return char* to allocated with subtring memory.
**/
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (s[0] == 0 || ft_strlen(s) <= start)
		return (ft_strdup(""));
	sub = NULL;
	if (len > ft_strlen(s))
		sub = malloc(ft_strlen(s) + 1);
	else
		sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	while (i < len && s[start])
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = 0;
	return (sub);
}

/**
 * @brief 	Function appends the NUL-terminated string 'src' to the end of 'dst'.
 * Takes whole size of destination buffer not only the size
 * It garantees null termination (as long size > 0 && dest
 * has at least onefree space)
 * Function does not check if 'dts' or 'src' is NULL!
 * @param dst String where 'src' gets appended to.
 * @param src String that gets appended to the end of 'dst'
 * @param dstsize How many characters of 'dst' gets appended.
 * @return 	Returns size_t of src + dst (without NUL) OR NULL if fails.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ldst;
	size_t	lsrc;
	size_t	i;
	size_t	j;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	i = 0;
	j = ldst;
	if (ldst < dstsize - 1 && dstsize > 0)
	{
		while (src[i] && (ldst + i < dstsize - 1))
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	if (ldst >= dstsize)
		ldst = dstsize;
	return (ldst + lsrc);
}
