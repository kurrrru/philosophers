/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:15:49 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/09 00:39:27 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static bool	is_any_invalid_char(char **arg);
static bool	is_any_non_positive(t_philo *philo, int argc);

int	process_input(int argc, char **argv, t_philo *philo)
{
	if (argc != 5 && argc != 6)
		return (printf("Error: invalid number of arguments\n"), ERROR);
	if (is_any_invalid_char(argv))
		return (printf("Error: numeric argument required\n"), ERROR);
	philo->config.num_philo = ft_atoi(argv[1]);
	philo->config.time_to_die = ft_atol(argv[2]);
	philo->config.time_to_eat = ft_atol(argv[3]);
	philo->config.time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		philo->config.min_meal = ft_atoi(argv[5]);
	else
		philo->config.min_meal = -1;
	if (is_any_non_positive(philo, argc))
		return (printf("Error: non-positive argument\n"), ERROR);
	return (SUCCESS);
}

static bool	is_any_invalid_char(char **arg)
{
	int	i;
	int	j;

	i = 1;
	while (arg[i])
	{
		j = 0;
		while (ft_isspace(arg[i][j]))
			j++;
		if (arg[i][j] == '+' || arg[i][j] == '-')
			j++;
		if (!ft_isdigit(arg[i][j]))
			return (true);
		while (ft_isdigit(arg[i][j]))
			j++;
		if (arg[i][j])
			return (true);
		i++;
	}
	return (false);
}

static bool	is_any_non_positive(t_philo *philo, int argc)
{
	if (philo->config.num_philo <= 0)
		return (true);
	if (philo->config.time_to_die <= 0)
		return (true);
	if (philo->config.time_to_eat <= 0)
		return (true);
	if (philo->config.time_to_sleep <= 0)
		return (true);
	if (argc == 6 && philo->config.min_meal <= 0)
		return (true);
	return (false);
}
