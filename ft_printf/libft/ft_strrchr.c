/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:04:15 by hauchida          #+#    #+#             */
/*   Updated: 2024/10/25 16:17:03 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen((char *)s);
	while (s_len > 0)
	{
		if ((unsigned char)s[s_len] == (unsigned char)c)
		{
			return ((char *)&s[s_len]);
		}
		s_len--;
	}
	if ((unsigned char)s[s_len] == (unsigned char)c)
	{
		return ((char *)&s[s_len]);
	}
	return (NULL);
}
