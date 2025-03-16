/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:52:36 by hauchida          #+#    #+#             */
/*   Updated: 2025/01/08 17:18:29 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	mutex;

void	init_meta_args(char **argv)
{
	t_meta_args	*meta_args;

	meta_args = get_meta_args();
	meta_args->number_of_philosophers = ft_atoi(argv[0]);
	meta_args->number_of_forks = meta_args->number_of_philosophers;
	meta_args->time_to_die = ft_atoi(argv[1]);
	meta_args->time_to_eat = ft_atoi(argv[2]);
	meta_args->time_to_sleep = ft_atoi(argv[3]);
	if (argv[4] != NULL)
		meta_args->number_of_each_philosopher_must_eat = ft_atoi(argv[4]);
}

int	init_philos(void)
{
	t_meta_args	*meta_args;
	t_philo		*philo;
	int			i;

	meta_args = get_meta_args();
	if (!meta_args->number_of_philosophers)
	{
		free_all("number_of_philosophers not found", ERROR_FD);
		return (0);
	}
	i = 0;
	while (i < meta_args->number_of_philosophers)
	{
		philo = create_philo(i);
		if (!philo)
		{
			free_all("failed to create philo", ERROR_FD);
			return (0);
		}
		add_philo_back(philo);
		i++;
	}
}

int	init_mutex(void)
{
	if (pthread_mutex_init(get_mutex(), NULL) != 0)
	{
		free_all("failed to init mutex", ERROR_FD);
		return (0);
	}
	return (1);
}

int	start_philo_thread(void)
{
	t_philo	**philos;
	int		ret;

	philos = get_philo();
	while (*philos)
	{
		ret = pthread_create(&(*philos)->thread, NULL, routine,
				(void *)(*philos));
		if (ret != 0)
		{
			free_all("pthread_create failed, fatal error", ERROR_FD);
			return (0);
		}
		ret = pthread_join((*philos)->thread, NULL);
		if (ret != 0)
		{
			free_all("pthread_join failed, fatal error", ERROR_FD);
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	// check_error
	if (!check_args(argc, argv))
		return (1);

	// initialize
	init_meta_args(argv);
	if (!init_philos())
		return (1);

	if (!init_mutex())
		return (1);

	// start
	start_philo_thread();

	return (0);
}