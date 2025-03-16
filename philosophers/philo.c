/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:01:59 by hauchida          #+#    #+#             */
/*   Updated: 2025/01/08 19:57:50 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_philo(int index)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->status = 0;
	philo->eat_count = 0;
	philo->philo_number = index;
	philo->prev = NULL;
	philo->next = NULL;
	return (philo);
}

t_philo	*get_philo_back(void)
{
	t_philo	**philos;

	philos = get_philo();
	while (*philos)
	{
		if (!(*philos)->next)
			break ;
		*philos = (*philos)->next;
	}
	return (*philos);
}

void	add_philo_back(t_philo *new)
{
	t_philo *philo_back;
	t_philo **philos;

	philo_back = get_philo_back();
	philos = get_philo();

	if (!philo_back)
		(*philos) = new;
	else
	{
		philo_back->next = new;
		new->prev = philo_back;
	}
}