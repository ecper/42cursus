/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 02:35:56 by hauchida          #+#    #+#             */
/*   Updated: 2024/10/30 02:05:38 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	uintlen(unsigned int n)
{
	if (n < 10)
	{
		return (1);
	}
	return (uintlen(n / 10) + 1);
}

static int	check_correct_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if ((base[i] == '+') || (base[i] == '-'))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static char	*ft_utoa_base(unsigned int nbr, char *base)
{
	size_t	base_len;
	int		n_len;
	char	*dest;

	base_len = ft_strlen(base);
	if (base_len < 1 || !check_correct_base(base))
		return (NULL);
	n_len = uintlen(nbr);
	dest = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!dest)
		return (NULL);
	dest[n_len] = '\0';
	while (n_len-- > 0)
	{
		dest[n_len] = base[(nbr % base_len)];
		nbr = nbr / base_len;
	}
	return (dest);
}

int	ft_putnbr_base_fd(unsigned int nbr, char *base, int fd)
{
	char	*dest;
	char	*tmp_dest;
	int		i;
	int		result;

	dest = ft_utoa_base((unsigned int)nbr, base);
	tmp_dest = dest;
	if (!dest)
		return (-1);
	i = 0;
	if (nbr != 0)
	{
		while (*dest && *dest == '0')
			dest++;
	}
	while (dest[i])
		i++;
	result = write(fd, dest, i);
	free(tmp_dest);
	return (result);
}
