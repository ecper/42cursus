/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:36:00 by hauchida          #+#    #+#             */
/*   Updated: 2024/10/28 00:53:04 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrll_fd(long long nb, int fd)
{
	char	a;

	if (nb < 0)
	{
		nb = -(nb);
		ft_putchar_fd('-', fd);
	}
	if (nb == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	else if (0 < nb && nb < 10)
	{
		a = nb + '0';
		ft_putchar_fd(a, fd);
		return ;
	}
	ft_putnbrll_fd(nb / 10, fd);
	a = (nb % 10) + '0';
	ft_putchar_fd(a, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbrll_fd((long long)n, fd);
}
