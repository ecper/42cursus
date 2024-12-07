/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:09:23 by hauchida          #+#    #+#             */
/*   Updated: 2024/10/30 02:06:04 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	uintptrlen(uintptr_t n)
{
	if (n < 16)
	{
		return (1);
	}
	return (uintptrlen(n / 16) + 1);
}

static char	*ft_addr(uintptr_t addr)
{
	const char	*hex_digits;
	char		*dest;
	int			n_len;

	n_len = uintptrlen(addr);
	dest = (char *)malloc(sizeof(char) * (n_len + 3));
	if (!dest)
		return (NULL);
	hex_digits = "0123456789abcdef";
	dest[0] = '0';
	dest[1] = 'x';
	dest[n_len + 2] = '\0';
	while (n_len-- > 0)
	{
		dest[n_len + 2] = hex_digits[(addr % 16)];
		addr = addr / 16;
	}
	return (dest);
}

int	ft_putaddr_fd(uintptr_t addr, int fd)
{
	int		result;
	char	*dest;

	if (!addr)
		return (write(fd, "(nil)", 5));
	dest = ft_addr(addr);
	if (!dest)
		return (-1);
	result = ft_putstr_fd(dest, fd);
	free(dest);
	return (result);
}
