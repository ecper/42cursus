/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:33:22 by hauchida          #+#    #+#             */
/*   Updated: 2024/10/23 14:13:03 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*tmp_s1 < *tmp_s2)
		{
			return (-1);
		}
		else if (*tmp_s1 > *tmp_s2)
		{
			return (1);
		}
		tmp_s1++;
		tmp_s2++;
		n--;
	}
	return (0);
}
