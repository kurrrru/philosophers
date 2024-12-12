/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:13:21 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/12 21:43:42 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	die_to_starvation(t_philo *philo, int i);

void	*supervisor(void *p)
{
	t_philo	*philo;
	int		i;
	int		min_meal_cnt;

	philo = (t_philo *)p;
	while (!end_status(philo, NULL))
	{
		min_meal_cnt = INT_MAX;
		i = -1;
		while (++i < philo->config.num_philo)
		{
			if (philo->config.time_to_die
				< getms() - philo->persons[i].last_meal)
				return (die_to_starvation(philo, i), NULL);
			if (philo->persons[i].last_meal
				&& philo->persons[i].meal_cnt < min_meal_cnt)
				min_meal_cnt = philo->persons[i].meal_cnt;
		}
		pthread_mutex_lock(&philo->meal_mutex);
		philo->min_meal_cnt = min_meal_cnt;
		pthread_mutex_unlock(&philo->meal_mutex);
		usleep(50);
	}
	return (NULL);
}

static void	die_to_starvation(t_philo *philo, int i)
{
	state_message(getms(), i + 1, msg_die, &philo->persons[i]);
	pthread_mutex_lock(&philo->end_mutex);
	philo->end = true;
	pthread_mutex_unlock(&philo->end_mutex);
}
