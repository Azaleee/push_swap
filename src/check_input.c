/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:33:05 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/09 19:14:39 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_num(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_dup(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac == 2)
		i = 0;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && (ft_atoi(av[i]) == ft_atoi(av[j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_input(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 2)
	{
		i = 0;
	}
	while (av[i])
	{
		if (is_num(av[i]) == 0)
		{
			exit_error();
		}
		i++;
	}
	if (is_dup(ac, av) == 0)
		exit_error();
}
