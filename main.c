/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelleng <tbelleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:01:22 by tbelleng          #+#    #+#             */
/*   Updated: 2023/01/27 18:17:43 by tbelleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_nb(int a, int b, t_list **stack_a, int *tab)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		free_a(stack_a, tab);
		return (NULL);
	}
	new->data = a;
	new->pos = b;
	new->next = NULL;
	return (new);
}

void	creating_stack(t_list **stack_a, int ac, char **av,
		int *tab)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = 1;
	j = 0;
	while (i < ac)
	{
		tab[j] = atoi_checker(av[i]);
		tmp = create_nb(ft_atoi(av[i]), j, stack_a, tab);
		ft_lstadd_back(stack_a, tmp);
		i++;
		j++;
	}
}

void	sorting_tab(int *tab, int ac)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (i < ((ac - 1) - 1))
	{
		j = 0;
		while (j < ((ac - 1) - i - 1))
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	attributing_pos(t_list **stack_a, int *tab, int ac)
{
	int		i;
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp != NULL)
	{
		i = 0;
		while (i < ac - 1)
		{
			if (tmp->data == tab[i])
				tmp->pos = i;
			i++;
		}
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*tab;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	tab = malloc(sizeof(int) * (ac - 1));
	if (!tab)
		return (0);
	if (!checker(ac, av))
	{
		free_all(&stack_a, &stack_b, tab);
		return (0);
	}
	creating_stack(&stack_a, ac, av, tab);
	if (is_sorted_pre(&stack_a, &stack_b, tab))
		return (0);
	sorting_tab(tab, ac);
	attributing_pos(&stack_a, tab, ac);
	if (!is_sorted(&stack_a))
		sort_choice(&stack_a, &stack_b, ac);
	free_all(&stack_a, &stack_b, tab);
}
