/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:29:08 by hauchida          #+#    #+#             */
/*   Updated: 2024/10/28 01:48:36 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	s_len;
	size_t	malloc_len;

	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	malloc_len = len;
	if (s_len - start < len)
		malloc_len = s_len - start;
	dest = (char *)malloc(sizeof(char) * (malloc_len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < malloc_len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
