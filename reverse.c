/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelleng <tbelleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:18:51 by tbelleng          #+#    #+#             */
/*   Updated: 2023/01/10 13:33:22 by tbelleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_pre_last(t_list *stack)
{
	t_list	*pre_last;

	pre_last = NULL;
	if (stack && stack->next)
	{
		pre_last = stack;
		while (pre_last->next->next)
			pre_last = pre_last->next;
	}
	return (pre_last);
}

void	reverse_a(t_list **stack_a)
{
	t_list	*pre_last;
	t_list	*last;
	t_list	*tmp;

	if (*stack_a && (*stack_a)->next)
	{
		tmp = *stack_a;
		pre_last = find_pre_last(*stack_a);
		last = pre_last->next;
		pre_last->next = NULL;
		last->next = tmp;
		*stack_a = last;
		write(1, "rra\n", 4);
	}
}

void	reverse_b(t_list **stack_b)
{
	t_list	*pre_last;
	t_list	*last;
	t_list	*tmp;

	if (*stack_b && (*stack_b)->next)
	{
		tmp = *stack_b;
		pre_last = find_pre_last(*stack_b);
		last = pre_last->next;
		pre_last->next = NULL;
		last->next = tmp;
		*stack_b = last;
		write(1, "rrb\n", 4);
	}
}
