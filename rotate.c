/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelleng <tbelleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:37:56 by tbelleng          #+#    #+#             */
/*   Updated: 2023/01/10 13:34:08 by tbelleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stack_a;
	tmp2 = *stack_a;
	*stack_a = (*stack_a)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp2;
	tmp->next->next = NULL;
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **stack_b)
{
	t_list	*last;
	t_list	*tmp;

	last = *stack_b;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b == NULL)
		return ;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}
