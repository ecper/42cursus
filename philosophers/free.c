/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:51:22 by hauchida          #+#    #+#             */
/*   Updated: 2025/01/08 17:28:43 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(void)
{
	t_philo	**philos;
	t_philo	*tmp;

	philos = get_philo();
	while (*philos)
	{
		tmp = (*philos)->next_philo;
		pthread_detach((*philos)->thread);
		free(*philos);
		*philos = tmp;
	}
}

void	free_all(char *message, int fd)
{
	free_philo();
	pthread_mutex_unlock(get_mutex());
	pthread_mutex_destroy(get_mutex());
	ft_putendl_fd(message, fd);
}
