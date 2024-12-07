/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:39:13 by hauchida          #+#    #+#             */
/*   Updated: 2024/10/24 15:09:18 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	s_len;
	unsigned int	i;

	s_len = (unsigned int)ft_strlen(s);
	i = 0;
	while (i < s_len)
	{
		(*f)(i, &s[i]);
		i++;
	}
}
