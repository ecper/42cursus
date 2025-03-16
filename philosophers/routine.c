/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:42:19 by hauchida          #+#    #+#             */
/*   Updated: 2025/01/09 10:09:06 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *philo)
{
	t_meta_args		*meta_args;
	struct timeval	tv;

	meta_args = get_meta_args();
	if (meta_args->number_of_philosophers <= 1)
	{
		free_all("die", DEFAULT_FD);
		return (0);
	}
	pthread_mutex_lock(&philo->next->fork[0]);
	if (gettimeofday(&tv, NULL) != 0)
		return (0);
	printf("%d %d has taken a fork\n", tv.tv_sec, philo->philo_number);
	pthread_mutex_lock(&philo->prev->fork[1]);
	if (gettimeofday(&tv, NULL) != 0)
		return (0);
	printf("%d %d has taken a fork\n", tv.tv_sec, philo->philo_number);
	return (1);
}

int	release_fork(t_philo *philo)
{
	t_meta_args	*meta_args;

	meta_args = get_meta_args();
	pthread_mutex_unlock(&philo->next->fork[0]);
	pthread_mutex_unlock(&philo->prev->fork[1]);
	return (1);
}

int	eat(t_philo *philo)
{
}

void	*routine(void *param)
{
	t_philo *philo;

	// param is absolutely exist, so i dont handle error
	philo = (t_philo *)param;
	// take forks
	pthread_mutex_lock(get_mutex());
}