/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelleng <tbelleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:17:09 by tbelleng          #+#    #+#             */
/*   Updated: 2023/01/27 18:14:53 by tbelleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	is_nb(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) < -2147483648 || ft_atoi(av[i]) > 2147483647)
			return (0);
		if ((av[i][0] == '+' || av[i][0] == '-') && (av[i][1] < '0'
				|| av[i][1] > '9'))
			return (0);
		i++;
	}
	return (1);
}

int	isnt_double(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		if (av[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	digit(int ac, char **av)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 0;
	k = 0;
	while (i < ac)
	{
		j = 0;
		k = ft_strlen(av[i]);
		while (j < k)
		{
			if ((av[i][j] == '-' || av[i][j] == '+'))
				j++;
			if (!ft_isdigit(av[i][j]) && av[i][j] != 32)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	no_over(int ac, char **av)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 0;
	k = 0;
	while (i < ac)
	{
		if (!too_long(av[i]))
			return (0);
		if (!one_arg(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	checker(int ac, char **av)
{
	if (!is_nb(ac, av))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!no_over(ac, av))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!isnt_double(ac, av))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!digit(ac, av))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
