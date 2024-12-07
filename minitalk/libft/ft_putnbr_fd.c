/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:36:00 by hauchida          #+#    #+#             */
/*   Updated: 2024/11/10 20:47:44 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	*dest;
	int		result;

	dest = ft_itoa(n);
	if (!dest)
		return (-1);
	result = ft_putstr_fd(dest, fd);
	free(dest);
	return (result);
}
