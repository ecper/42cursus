/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:49:51 by hauchida          #+#    #+#             */
/*   Updated: 2025/01/08 19:54:10 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_meta_args	*get_meta_args(void)
{
	static t_meta_args	meta_args;

	return (&meta_args);
}

t_philo	*get_philo(void)
{
	static t_philo	*philos;

	return (&philos);
}

// pthread_mutex_t	*get_mutex(void)
// {
// 	static pthread_mutex_t	mutex;

// 	return (&mutex);
// }
