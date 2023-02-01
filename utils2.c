/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelleng <tbelleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:34:40 by tbelleng          #+#    #+#             */
/*   Updated: 2023/01/27 18:18:39 by tbelleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_list **stack_a, t_list **stack_b, int *tab)
{
	t_list	*tmp;

	while (*stack_a != NULL)
	{
		tmp = (*stack_a)->next;
		free(*stack_a);
		*stack_a = tmp;
	}
	while (*stack_b != NULL)
	{
		tmp = (*stack_b)->next;
		free(*stack_b);
		*stack_b = tmp;
	}
	free(tab);
}

void	free_a(t_list **stack_a, int *tab)
{
	t_list	*tmp;

	while (*stack_a != NULL)
	{
		tmp = (*stack_a)->next;
		free(*stack_a);
		*stack_a = tmp;
	}
	free(tab);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	too_long(char *arg)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]))
			count++;
		i++;
	}
	if (count > 11)
		return (0);
	return (1);
}

int	one_arg(char *arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[i] == 32)
		i++;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (ft_isdigit(arg[i]))
		i++;
	while (arg[i] == 32)
		i++;
	if (arg[i] != '\0')
		return (0);
	return (1);
}
