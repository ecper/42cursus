/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:38:31 by hauchida          #+#    #+#             */
/*   Updated: 2024/10/28 01:48:16 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
