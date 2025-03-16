/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:55:01 by hauchida          #+#    #+#             */
/*   Updated: 2025/01/08 15:59:21 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int argc, char **argv)
{
	int i;

	i = 0;

	if (argc < 5 || argc > 5)
	{
		ft_putendl_fd("args not validate", ERROR_FD);
		return (0);
	}
	while (argv[i])
	{
		if (ft_atoi(argv[i]) < 0)
		{
			ft_putendl_fd("args not validate", ERROR_FD);
			return (0);
		}
		i++;
	}

	return (1);
}