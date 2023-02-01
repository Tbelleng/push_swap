/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_five_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelleng <tbelleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:21:37 by tbelleng          #+#    #+#             */
/*   Updated: 2023/01/16 23:45:16 by tbelleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->data;
	b = (*stack_a)->next->data;
	c = (*stack_a)->next->next->data;
	if (a > b && c > b && c > a)
		swap_a(stack_a);
	else if (a > b && a > c && b > c)
	{
		swap_a(stack_a);
		reverse_a(stack_a);
	}
	else if (a > b && c > b && a > c)
		rotate_a(stack_a);
	else if (a < b && a < c && b > c)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (a < b && a > c && b > c)
		reverse_a(stack_a);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	small;

	small = smallest(stack_a);
	while ((*stack_a)->data != small)
		rotate_a(stack_a);
	push_b(stack_b, stack_a);
	sort_three(stack_a);
	push_a(stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	small;
	int	small2;
	int	half;
	int	pos;

	half = (int_count(stack_a) / 2);
	small = smallest(stack_a);
	pos = get_pos(stack_a, small);
	while ((*stack_a)->data != small)
	{
		if (pos >= half)
			reverse_a(stack_a);
		else
			rotate_a(stack_a);
	}
	push_b(stack_b, stack_a);
	small2 = smallest(stack_a);
	while ((*stack_a)->data != small2)
		rotate_a(stack_a);
	push_b(stack_b, stack_a);
	sort_three(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

int	smallest(t_list **stack_a)
{
	t_list	*tmp;
	int		small;

	tmp = *stack_a;
	small = (*stack_a)->data;
	while ((*stack_a) != NULL)
	{
		if (small > (*stack_a)->data)
			small = (*stack_a)->data;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = tmp;
	return (small);
}

int	get_pos(t_list **stack_a, int small)
{
	t_list	*tmp;
	int		pos;

	tmp = *stack_a;
	pos = 0;
	while ((*stack_a)->data != small)
	{
		pos++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = tmp;
	return (pos);
}
