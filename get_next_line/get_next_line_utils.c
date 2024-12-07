/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 22:29:19 by hauchida          #+#    #+#             */
/*   Updated: 2024/11/05 22:04:33 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (count);
	while (str[count] != '\0')
		count++;
	return (count);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size <= 0)
	{
		return (src_len);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strdup(const char *src)
{
	size_t	src_len;
	char	*dest;

	src_len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, src_len + 1);
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*tmp_dest;
	unsigned const char	*tmp_src;

	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned const char *)src;
	while (n-- > 0)
	{
		*tmp_dest = *tmp_src;
		tmp_dest++;
		tmp_src++;
	}
	return (dest);
}

char	*ft_putstr(char const *s1, char s2)
{
	size_t	s1_len;
	char	*dest;

	s1_len = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (s1_len + 1 + 1));
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s1, s1_len);
	dest[s1_len] = s2;
	dest[s1_len + 1] = '\0';
	free((char *)s1);
	s1 = NULL;
	return (dest);
}
