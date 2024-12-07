/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:45:27 by hauchida          #+#    #+#             */
/*   Updated: 2024/10/28 01:47:59 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	start;
	size_t	end;
	size_t	s1_len;

	start = 0;
	s1_len = ft_strlen(s1);
	end = s1_len - 1;
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	if (start >= end || !s1_len)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[end]) && end > 0)
		end--;
	dest = (char *)malloc(sizeof(char) * ((end - start) + 2));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, &s1[start], ((end - start) + 2));
	return (dest);
}
