/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:36:56 by hauchida          #+#    #+#             */
/*   Updated: 2024/11/18 23:23:27 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	retry_signal(pid_t pid, int sig)
{
	static int	retry_count;

	if (retry_count > 10)
		exit(EXIT_FAILURE);
	if (kill(pid, sig) < 0)
	{
		retry_signal(pid, sig);
		retry_count++;
	}
}

static void	put_char_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				bit_count;

	(void)context;
	if (sig == SIGUSR2)
		c |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		if (c != '\0')
			ft_putchar_fd(c, 1);
		else
		{
			ft_putchar_fd('\n', 1);
			retry_signal(info->si_pid, SIGUSR1);
		}
		bit_count = 0;
		c = 0;
	}
	retry_signal(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_printf("pid: %d\n", getpid());
	ft_printf("LETS MINITALK\n");
	s_sigaction.sa_flags = SA_SIGINFO;
	s_sigaction.sa_sigaction = &put_char_handler;
	sigemptyset(&s_sigaction.sa_mask);
	if (sigaction(SIGUSR1, &s_sigaction, NULL) < 0 || sigaction(SIGUSR2,
			&s_sigaction, NULL) < 0)
		exit(EXIT_FAILURE);
	while (1)
		pause();
	return (0);
}
