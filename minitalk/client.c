/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:08:53 by hauchida          #+#    #+#             */
/*   Updated: 2024/11/29 18:36:48 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	*set_acknowledge(int value)
{
	static int	g_acknowledge;

	g_acknowledge = value;
	return (&g_acknowledge);
}

static void	received_signal_handler(int sig)
{
	(void)sig;
	ft_printf("success sent message\n");
	exit(EXIT_SUCCESS);
}

static void	acknowledge_signal_handler(int sig)
{
	(void)sig;
	set_acknowledge(1);
}

static void	send_char(pid_t pid, char c)
{
	int	bit;
	int	i;
	int	sig;
	int	*flag;

	i = 0;
	while (i < 8)
	{
		bit = (c >> i) & 1;
		sig = SIGUSR2;
		if (!bit)
			sig = SIGUSR1;
		flag = set_acknowledge(0);
		if (kill(pid, sig) == -1)
			exit(EXIT_FAILURE);
		while (!*flag)
			usleep(10);
		i++;
	}
}

int	main(int ac, char **argv)
{
	int	i;
	int	server_pid;

	i = 0;
	if (ac < 1 || ac > 3 || !argv[2])
		return (1);
	server_pid = (pid_t)ft_atoi(argv[1]);
	if (server_pid < 100 || server_pid > 999999)
	{
		ft_printf("wrong pid\n");
		return (1);
	}
	ft_printf("Send string: %s\n", argv[2]);
	if (signal(SIGUSR1, received_signal_handler) < 0 || signal(SIGUSR2,
			acknowledge_signal_handler) < 0)
		exit(EXIT_FAILURE);
	while (argv[2][i])
	{
		send_char(server_pid, argv[2][i]);
		i++;
	}
	send_char(server_pid, '\0');
	return (0);
}
