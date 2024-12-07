/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:23:36 by hauchida          #+#    #+#             */
/*   Updated: 2024/10/27 17:45:53 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(long long n)
{
	if ((0 <= n && n < 10))
	{
		return (1);
	}
	if (n < 0)
	{
		n = -(n);
		return (intlen(n) + 1);
	}
	return (intlen(n / 10) + 1);
}

static void	ft_putnbrll(long long nb, char *dest, int *index)
{
	if (nb < 0)
	{
		nb = -(nb);
		dest[*index] = '-';
		*index += 1;
	}
	if (nb == 0)
	{
		dest[*index] = '0';
		*index += 1;
		return ;
	}
	else if (0 < nb && nb < 10)
	{
		dest[*index] = nb + '0';
		*index += 1;
		return ;
	}
	ft_putnbrll(nb / 10, dest, index);
	dest[*index] = (nb % 10) + '0';
	*index += 1;
}

char	*ft_itoa(int n)
{
	int		n_len;
	int		index;
	char	*dest;

	n_len = intlen((long long)n);
	index = 0;
	dest = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!dest)
	{
		return (NULL);
	}
	ft_putnbrll(n, dest, &index);
	dest[index] = '\0';
	return (dest);
}
