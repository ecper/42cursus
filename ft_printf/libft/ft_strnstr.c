/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:55:39 by hauchida          #+#    #+#             */
/*   Updated: 2024/10/28 01:48:56 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_identical(const char *big, const char *little,
		size_t start, size_t len)
{
	size_t	i;

	i = 0;
	while (little[i] != '\0' && big[start + i] != '\0' && big[start
			+ i] == little[i] && start + i < len)
	{
		i++;
	}
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;
	size_t	count;

	i = 0;
	little_len = ft_strlen(little);
	if (!little_len)
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		count = check_identical(big, little, i, len);
		if (count == little_len)
		{
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
