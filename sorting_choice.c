/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_choice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelleng <tbelleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:38:16 by tbelleng          #+#    #+#             */
/*   Updated: 2023/01/12 16:27:51 by tbelleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_count(t_list **stack_a)
{
	int		count;
	t_list	*tmp;

	count = 1;
	tmp = *stack_a;
	while ((*stack_a)->next != NULL)
	{
		count++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = tmp;
	return (count);
}

void	sort_choice(t_list **stack_a, t_list **stack_b, int ac)
{
	int	count;

	count = int_count(stack_a);
	if (count == 2)
		swap_a(stack_a);
	else if (count == 3)
		sort_three(stack_a);
	else if (count == 4)
		sort_four(stack_a,
			stack_b);
	else if (count == 5)
		sort_five(stack_a, stack_b);
	else if (count > 5 && count <= 100)
		sort_x100(stack_a, stack_b, ac);
	else
		sort_x500(stack_a, stack_b, ac);
}

int	is_sorted(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while ((*stack_a)->next != NULL)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
		{
			*stack_a = tmp;
			return (0);
		}
		*stack_a = (*stack_a)->next;
	}
	*stack_a = tmp;
	return (1);
}

int	is_sorted_pre(t_list **stack_a, t_list **stack_b, int *tab)
{
	t_list	*tmp;

	tmp = *stack_a;
	while ((*stack_a)->next != NULL)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
		{
			*stack_a = tmp;
			return (0);
		}
		*stack_a = (*stack_a)->next;
	}
	*stack_a = tmp;
	free_all(stack_a, stack_b, tab);
	return (1);
}
