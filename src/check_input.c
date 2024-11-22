/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:33:05 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/22 17:15:33 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

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

void	free_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	check_input(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 2)
		i = 0;
	while (av[i])
	{
		if (is_num(av[i]) == 0
			|| (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN))
		{
			if (ac == 2)
				free_av(av);
			exit_error();
		}
		i++;
	}
	if (is_dup(ac, av) == 0)
	{
		if (ac == 2)
			free_av(av);
		exit_error();
	}
}
