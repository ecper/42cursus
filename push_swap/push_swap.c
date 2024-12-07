/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:23:32 by hauchida          #+#    #+#             */
/*   Updated: 2024/12/04 21:08:12 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*init_lst(t_list *lst, char **argv, int arg_status)
{
	int		i;
	int		content;
	long	tmp;
	t_list	*new_node;

	i = 0;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			free_all(&lst, NULL, argv, arg_status);
		content = (int)tmp;
		new_node = ft_lstnew((void *)(&content));
		if (!new_node)
			free_all(&lst, NULL, argv, arg_status);
		ft_lstadd_back(&lst, new_node);
		i++;
	}
	return (lst);
}

static int	check_args(int *argc, char ***argv)
{
	int	splitted;

	splitted = 1;
	if (*argc < 2)
		return (0);
	if (*argc == 2)
	{
		*argv = ft_split(argv[0][1], ' ');
		splitted = 2;
	}
	else
		(*argv)++;
	*argc = is_valid_isdigits(*argv);
	if (!(*argc))
	{
		if (splitted == 2)
			success_split(*argv);
		write(1, "Error\n", 6);
		return (0);
	}
	return (splitted);
}

int	main(int argc, char **argv)
{
	static t_list	*a;
	static t_list	*b;
	int				arg_status;

	arg_status = check_args(&argc, &argv);
	if (!arg_status)
		return (1);
	b = NULL;
	a = init_lst(a, argv, arg_status);
	if (arg_status == 2)
		success_split(argv);
	if (!is_valid_duplicate(a))
		exit_error(&a, &b);
	if (!is_valid_sort(a))
	{
		success(&a, &b);
		return (1);
	}
	compression(&a);
	lets_sort(&a, &b, argc);
	success(&a, &b);
}
