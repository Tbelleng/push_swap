/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelleng <tbelleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:43:51 by tbelleng          #+#    #+#             */
/*   Updated: 2023/01/10 13:36:15 by tbelleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a)
{
	int	tmp;

	if (!(*stack_a))
		return ;
	tmp = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = tmp;
	tmp = (*stack_a)->pos;
	(*stack_a)->pos = (*stack_a)->next->pos;
	(*stack_a)->next->pos = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_list **stack_b)
{
	int	tmp;

	if (!(*stack_b))
		return ;
	tmp = (*stack_b)->data;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->next->data = tmp;
	tmp = (*stack_b)->pos;
	(*stack_b)->pos = (*stack_b)->next->pos;
	(*stack_b)->next->pos = tmp;
	write(1, "sb\n", 3);
}
