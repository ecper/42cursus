/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:10:51 by hauchida          #+#    #+#             */
/*   Updated: 2024/12/04 21:16:58 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	struct s_list	*prev;
	void			*content;
	struct s_list	*next;
}					t_list;

// lst
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				sa(t_list *a, t_list *b);
void				sb(t_list *b, t_list *a);
void				ss(t_list *a, t_list *b);
void				pa(t_list **a, t_list **b);
void				pb(t_list **b, t_list **a);
void				ra(t_list **a, t_list **b);
void				rb(t_list **b, t_list **a);
void				rr(t_list **a, t_list **b);
void				rra(t_list **a, t_list **b);
void				rrb(t_list **b, t_list **a);
void				rrr(t_list **a, t_list **b);
//
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *src);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
long				ft_atoi(const char *nptr);

int					ft_isdigit(int c);
void				ft_contentdelone(void *content);
void				compression(t_list **lst);
int					is_valid_sort(t_list *lst);
int					is_valid_duplicate(t_list *lst);
int					is_valid_isdigits(char **argv);
int					get_min_index(t_list *lst);
int					get_max_index(t_list *lst);
int					get_max_bits(t_list *lst);
void				exit_error(t_list **a, t_list **b);
void				lets_sort(t_list **a, t_list **b, int count);
void				success_split(char **split);
void				success(t_list **a, t_list **b);
void				free_all(t_list **a, t_list **b, char **argv,
						int arg_status);
#endif