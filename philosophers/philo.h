/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:41:49 by hauchida          #+#    #+#             */
/*   Updated: 2025/01/08 20:01:37 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define ERROR_FD 2
# define DEFAULT_FD 1

typedef struct s_meta_args
{
	int				number_of_philosophers;
	int				number_of_forks;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_each_philosopher_must_eat;
}					t_meta_args;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	mutex;
	int				philo_number;
	int				eat_count;
	// 0: none, 1: eating, 2: sleeping, 3: thinking, 4: die
	int				status;
	// 0: left, 1: right
	pthread_mutex_t	fork[2];
	t_philo			*prev;
	t_philo			*next;
}					t_philo;

// philo.c
t_philo				*create_philo(int index);
t_philo				*get_philo_back(void);
void				add_philo_back(t_philo *new);

// free.c
void				free_all(char *message, int fd);
void				free_philo(void);

// global.c
t_meta_args			*get_meta_args(void);
t_philo				*get_philo(void);
pthread_mutex_t		*get_mutex(void);

// ft_atoi.c
int					ft_atoi(const char *nptr);

// putstr_utils.c
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);

#endif