/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelleng <tbelleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:01:15 by tbelleng          #+#    #+#             */
/*   Updated: 2023/01/30 16:02:50 by tbelleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef int			t_bool;
# define FALSE 0
# define TRUE 1

typedef struct s_list
{
	int				data;
	int				pos;
	struct s_list	*next;
}					t_list;

long long int		ft_atoi(const char *nptr);
long long int		atoi_checker(const char *nptr);
int					ft_isdigit(int c);
int					digit(int ac, char **av);
int					one_arg(char *arg);
int					too_long(char *arg);

void				ft_lstadd_front(t_list **lst, t_list *new);
void				free_a(t_list **stack_a, int *tab);
void				push_a(t_list **stack_b, t_list **stack_a);
void				push_b(t_list **stack_b, t_list **stack_a);
void				creating_stack(t_list **stack_a, int ac, char **av,
						int *tab);
void				ft_lstadd_back(t_list **lst,
						t_list *new);
void				sorting_tab(int *tab, int ac);
void				attributing_pos(t_list **stack_a, int *tab, int ac);

void				swap_a(t_list **stack_a);
void				swap_b(t_list **stack_b);

void				rotate_a(t_list **stack_a);
void				rotate_b(t_list **stack_b);

t_list				*find_pre_last(t_list *stack);
void				reverse_a(t_list **stack_a);
void				reverse_b(t_list **stack_b);

int					is_sorted(t_list **stack_a);
int					is_sorted_pre(t_list **stack_a, t_list **stack_b, int *tab);
int					int_count(t_list **stack_a);
void				sort_choice(t_list **stack_a, t_list **stack_b, int ac);
int					smallest(t_list **stack_a);
int					get_pos(t_list **stack_a, int small);
int					biggest(t_list **stack_a);
int					getting_median(t_list **stack_a);
int					is_median(int value, t_list *tmp, int count);

void				sort_three(t_list **stack_a);
void				sort_four(t_list **stack_a, t_list **stack_b);
void				sort_five(t_list **stack_a, t_list **stack_b);
void				sort_x100(t_list **stack_a, t_list **stack_b, int ac);
void				sort_x500(t_list **stack_a, t_list **stack_b, int ac);

void				free_all(t_list **stack_a, t_list **stack_b, int *tab);

int					ra_or_rra(t_list **stack_b, int big);

t_list				*create_nb(int a, int b, t_list **stack_a, int *tab);

t_list				*ft_lstlast(t_list *lst);

int					isnt_double(int ac, char **av);
long long int		is_nb(int ac, char **av);
int					checker(int ac, char **av);
size_t				ft_strlen(const char *s);

#endif
