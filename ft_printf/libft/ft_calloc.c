/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:43:57 by hauchida          #+#    #+#             */
/*   Updated: 2024/10/28 00:55:43 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*val;

	i = 0;
	if (nmemb == 0)
		return (malloc(0));
	if (size != 0 && (nmemb > SIZE_MAX / size))
	{
		return (NULL);
	}
	val = malloc(size * nmemb);
	if (!val)
	{
		return (NULL);
	}
	return (ft_memset(val, 0, nmemb * size));
}
