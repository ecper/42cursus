/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:46:44 by hauchida          #+#    #+#             */
/*   Updated: 2024/10/28 00:49:41 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*tmp_dest;
	unsigned const char	*tmp_src;
	size_t				i;

	i = 0;
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned const char *)src;
	if (tmp_dest < tmp_src)
	{
		while (i < n)
		{
			tmp_dest[i] = tmp_src[i];
			i++;
		}
	}
	else if (tmp_dest > tmp_src)
	{
		i = n;
		while (i-- > 0)
		{
			tmp_dest[i] = tmp_src[i];
		}
	}
	return (dest);
}
